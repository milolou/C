#include <stdio.h>

#define N 8

int main(int argc, char const *argv[])
{
	int i;
	int c;

	i = 0;
	while ((c = getchar()) != EOF){
		if (c != '\n'){
			if (c == '\t'){
				while ((i % N) != 0){
					putchar(' ');
					++i;
				}
			}
		    else {
			    putchar(c);
			    ++i;
		    }
	    }
	    else {
	    	i = 0;
	    	putchar(c);
	    }
	}
	return 0;
}