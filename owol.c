#include <stdio.h>

/* put each word each line */

int main(int argc, char const *argv[])
{
	int c;
	while ((c =getchar()) != EOF){
		if (c == ' ' || c == '\n' || c =='\t'){
			putchar('\n');
			while ((c =getchar()) != EOF)
				if (c != ' ' && c != '\n' && c != '\t'){
					putchar(c);
					break;
				}
		}
		else
			putchar(c);
	}
	return 0;
}