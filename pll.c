#include <stdio.h>

int gtline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
	long i;
	int c;

	i = 0;
	while ((c =getchar()) != EOF){
		if (c == '\n'){
			putchar(c);
			printf("%d\n", ++i);
			i = 0;
		}
		++i;
		putchar(c);
	}
	return 0;
}

int gtline(char s[], int lim)
{
	int c, i;
    
    i = 0;
	for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
		s[i] = c;
	
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}