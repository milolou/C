#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"

struct config baseConfig;
static char *keyword[] = {"asctime", "levelname", "message", '\0'};

char getlastword(char *s)
{
	int i;
	char c;

	for (i = 0; s[i] != '\0'; i++)
		;
	c = s[i-1];
	return c;
}

char *strcaten(char *l, char *s);

char *dirlist(char *dirname)
{
	char *c;
	DIR *dp;
	struct dirent *dirp;
	char *nu[5] = {"0", "1", "2", "3", "4"};
	int num[5] = {0, 0, 0, 0, 0};
	char w;
	int b;
	time_t ltime[5];
	struct stat *s;
	int t;
	int tmp;
	char *r;
	char *p;

	c = r = malloc(2);
	s = malloc(sizeof(struct stat));
	if((dp = opendir(dirname)) == NULL) {
		mkdir(dirname, 777);
		*r++ = '0';
		*r = '\0';
		return c;
	}
	while((dirp = readdir(dp)) != NULL){ 
		c = dirp->d_name;
		if (c != "." && c != "..") {
			w = getlastword(c);
		    for (b = 0; b < 5; b++)
		    	if (w == *nu[b]) {
		    		num[b] = 1;
					p = strcaten(dirname,c);
		    	    int ret = stat(p, s);
					if (ret != 0)
					{
						perror("stat err:");
						printf("stat err :%d \n", ret);
					}
			        ltime[b] = s->st_mtim.tv_sec;
			    }
		}
	}
	free(s);
	for (b = 0; b < 5; b++)
		if (num[b] == 0) {
			strcpy(r, nu[b]);
			return r;
		}
    tmp = 0;
	t = ltime[0];
	for (b = 0; b < 5; b++) {
		if (ltime[b] < t) {
			t = ltime[b];
		    tmp = b;
		}
	}

	strcpy(r, nu[tmp]);
	closedir(dp);
	return r;
}

void strip(char *s)
{
	while (*s != '\n')
		s++;
	*s = '\0';
}

char *strcaten(char *l, char *s)
{
	char *n;
	char *tmp;

	if (l != NULL)
		tmp = n = malloc(strlen(l) + strlen(s) + 1);
	else {
		tmp = n = malloc(strlen(s) + 1);
		while (*n++ = *s++)
			;
		return tmp;
	}
	while (*n = *l) {
		n++;
		l++;
	}
	while (*n++ = *s++)
		;
	return tmp;
}

void formatchecker(char *s, char **format)
{
	char *p;
	char *i;
	int k;

    k = 0;
	while (*s != '\0')
		if (*s++ == '%')
			if (*s++ == '(') {
				i = p = malloc(10);
				while (*s != ')') 
					*p++ = *s++;
				*p = '\0';
				if (*++s == 's')
					*format++ = i;
			}
		s++;
	p = malloc(1);
	*p = '\0';
	*format = p;
}

char *getasctime(void)
{
	struct tm *local;
	time_t t;

    t=time(NULL);  
    local=localtime(&t);
    return asctime(local);
}

char *record(char **st, char *s, int n)
{
	int i;
	int j;
	char *u = NULL;
	char *t;
	char div[] = " - ";
	char *p = NULL;

	for (i = 0; st[i] != NULL; i++) {
		for (j = 0; keyword[j] != NULL; j++) {
			if (strcmp(st[i], keyword[j]) == 0) {
				switch (j) {
					case 0:
					    t = getasctime();
					    strip(t);
                        u = strcaten(u, t);
                        p = u;
                        u = strcaten(u, div);
                        free(p);
                        p = u;
                        break;
                    case 1:
                        switch (n) {
                        	case 0:
                        	    u = strcaten(u, "DEBUG");
                        	    free(p);
                        	    p = u;
                        	    u = strcaten(u, div);
                        	    free(p);
                        	    p = u;
                        	    break;
                        	case 1:
                        	    u = strcaten(u, "INFO");
                        	    free(p);
                        	    p = u;
                        	    u = strcaten(u, div);
                        	    free(p);
                        	    p = u;
                        	    break;
                        	case 2:
                        	    u = strcaten(u, "WARNING");
                        	    free(p);
                        	    p = u;
                        	    u = strcaten(u, div);
                        	    free(p);
                        	    p = u;
                        	    break;
                        	case 3:
                        	    u = strcaten(u, "ERROR");
                        	    free(p);
                        	    p = u;
                        	    u = strcaten(u, div);
                        	    free(p);
                        	    p = u;
                        	    break;
                        	case 4:
                        	    u = strcaten(u, "CRITICAL");
                        	    free(p);
                        	    p = u;
                        	    u = strcaten(u, div);
                        	    free(p);
                        	    p = u;
                        	    break;
                        }
                        break;
                    case 2:
                        u = strcaten(u, s);
                        free(p);
                        break;
				}
			}
		}
	}
	return u;
}

void basiConfig(int level, char *format)
{
	char *n;
	char *filename;
	char *tmp;
	char *s = "./logging/";
	char *pre = "log";

	baseConfig.level = level;
    formatchecker(format, baseConfig.format);
	n = dirlist(s);
	tmp = filename = strcaten(pre, n);
	filename = strcaten(s, filename);
	free(tmp);
	baseConfig.fp = fopen(filename, "w");
	free(n);
	free(filename);
}

int disable(int n)
{
	baseConfig.level = n;
	printf("%d\n", baseConfig.level);
	return 0;
}

void stop(void)
{
	int i;

	i = 0;
	while (baseConfig.format[i] != NULL) {
		free(baseConfig.format[i]);
		i++;
	}
	free(baseConfig.format[i]);
	fclose(baseConfig.fp);
}

int debug(char *s)
{
	char **st;
	char *ns;

	if (baseConfig.level > DEBUG)
		;
	else {
		st = baseConfig.format;
		ns = record(st, s, DEBUG);
		while (*ns != '\0') {
			putc(*ns, stdout);
			putc(*ns, baseConfig.fp);
			ns++;
		}
	}
	return 0; 
}

int info(char *s)
{
	char **st;
	char *ns;

	if (baseConfig.level > INFO)
		;
	else {
		st = baseConfig.format;
		ns = record(st, s, INFO);
		while (*ns != '\0') {
			putc(*ns, stdout);
			putc(*ns, baseConfig.fp);
			ns++;
		}
	}
	return 0; 
}

int warning(char *s)
{
	char **st;
	char *ns;

	if (baseConfig.level > WARNING)
		;
	else {
		st = baseConfig.format;
		ns = record(st, s, WARNING);
		while (*ns != '\0') {
			putc(*ns, stdout);
			putc(*ns, baseConfig.fp);
			ns++;
		}
	}
	return 0; 
}

int error(char *s)
{
	char **st;
	char *ns;

	if (baseConfig.level > ERROR)
		;
	else {
		st = baseConfig.format;
		ns = record(st, s, ERROR);
		while (*ns != '\0') {
			putc(*ns, stdout);
			putc(*ns, baseConfig.fp);
			ns++;
		}
	}
	return 0; 
}

int critical(char *s)
{
	char **st;
	char *ns;

	if (baseConfig.level > CRITICAL)
		;
	else {
		st = baseConfig.format;
		ns = record(st, s, CRITICAL);
		while (*ns != '\0') {
			putc(*ns, stdout);
			putc(*ns, baseConfig.fp);
			ns++;
		}
	}
	return 0; 
}
