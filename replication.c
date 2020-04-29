#include <stdio.h>

/* read and put */

int main(int argc, char const *argv[])
{
	int c;
	c = getchar();
	while (c != EOF){
		putchar(c);
		c = getchar();
	}
	return 0;
}