#include <stdio.h>

/*  space counting */

int main(int argc, char const *argv[])
{
	int s, c;
	s = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n')
			++s;
		else if (c == '\t')
			++s;
		else if (c == ' ')
			++s;
	printf("%d\n", s);
	return 0;
}