#include <stdio.h>
#include <ctype.h>

#define N 10
#define MAXLINES 5000

int readlines(char *lineptr[], int maxlines);
int atoi(const char s[]);

int main(int argc, char const *argv[])
{
	const char *p;
	int n, nlines;
	int c;
	char *lineptr[MAXLINES];

	if (argc > 1) {
		while (--argc > 0) {
			p = *++argv;
			if (p[0] == '-' && p[1] == 'n') {
				n = atoi(*++argv);
				break;
			}
			else {
				printf("Usage: tail -n <number>");
				return -1;
			}
		}
    }
    else if (argc == 1)
    	n = N;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0 && nlines > n) {
    	c = nlines - n;
    	while (n-- > 0) {
    		printf("%s\n", lineptr[c++]);
    	}
    }
	return 0;
}

int atoi(const char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

#define MAXLEN 1000
int gtline(char *, int);
void strcp(char *s, char *t);
char *alloc(int);

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