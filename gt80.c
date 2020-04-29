#include <stdio.h>

#define MAXLINE 1000
#define BOUND 80

int gtline(char line[], int maxline);

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];

	while ((len = gtline(line, MAXLINE)) > 0)
		if (len > BOUND)
			printf("%s", line);
	return 0;
}

int gtline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}