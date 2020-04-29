#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void sort(void *v[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int strcm(char *s, char *t);
void reverse(void *s[], int left, int right);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int verse = 0;

	if (argc > 1 && strcm(argv[1], "-n") == 0)
		numeric = 1;
	if (argc > 1 && strcm(argv[1], "-nr") == 0 || strcm(argv[1], "-rn") == 0 || strcm(argv[1], "-r") == 0)
		verse = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		sort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp: strcm));
		if (verse == 1)
			reverse((void **) lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return -1;
	}
}

void swap(void *v[], int i, int j);

void sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	sort(v, left, last - 1, comp);
	sort(v, last + 1, right, comp);
}

void reverse(void *s[], int left, int right)
{
	if (left >= right)
		return;
	swap(s, left, right);
	reverse(s, ++left, --right);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int strcm(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000
int gtline(char *, int);
char *alloc(int);
void strcp(char *s, char *t);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = gtline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcp(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

int gtline(char *s, int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 5000000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char *alloc(int n)
{
	if (allocbuff + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void strcp(char *s, char *t)
{
	while (*s++ = *t++)
		;
}