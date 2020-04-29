#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int gtline(char *line, int max);

int main(int argc, char const *argv[])
{
	char line[MAXLEN];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
				    except = 1;
				    break;
				case 'n':
				    number = 1;
				    break;
				default:
				    printf("find: illegal option %c\n", c);
				    argc = 0;
				    found = -1;
				    break;
			}

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (gtline(line, MAXLEN) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%s", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
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