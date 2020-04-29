#include <stdio.h>
/* substitute space */

int main(int argc, char const *argv[])
{
	int c;
	while ((c = getchar()) != EOF)
		if (c == ' ') {
			putchar(c);
			while((c = getchar()) != EOF)
				if (c != ' '){
					putchar(c);
					break;
				}
		}
		else if (c != ' ')
			putchar(c);
	return 0;
}