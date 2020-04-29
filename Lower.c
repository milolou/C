#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char *c;

	c = argv[0];
	while (*c != '\0')
		putchar(tolower(*c++));
	return 0;
}