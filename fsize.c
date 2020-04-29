#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"
#include <stdlib.h>

#define NAME_MAX 14
typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} Dir;

void fsize(char *);

int main(int argc, char **argv)
{
	if (argc == 1)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}


void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}

#ifndef  MAX_PATH
   #define MAX_PATH 1024
#endif

Dir *opndir(char *dirname);
void closdir(Dir *dp);
Dirent *raddir(Dir *dp);

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	Dir *dfd;

	if ((dfd = opndir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = raddir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: name%s/%s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s %s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closdir(dfd);
}

#ifndef DIRSIZ
  #define DIRSIZ 14
#endif
struct direct
{
	ino_t d_ino;
	char d_name[DIRSIZ];
};

int fstat(int fd, struct stat *);

Dir *opndir(char *dirname)
{
	int fd;
	struct stat stbuf;
	Dir *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
		|| fstat(fd, &stbuf) == -1
		|| (stbuf.st_mode & S_IFMT) != S_IFDIR
		|| (dp = (Dir *) malloc(sizeof(Dir))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

void closdir(Dir *dp)
{
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

Dirent *raddir(Dir *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';
		return &d;
	}
	return NULL;
}