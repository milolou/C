#include <stdio.h>

/* visualize */
int main(int argc, char const *argv[])
{
	int c;
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b'){
			putchar('\\');
			putchar('b');
		}
		putchar(c);
	}
	return 0;
}