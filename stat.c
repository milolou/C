#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDS 8

/* graphic */
int main(int argc, char const *argv[])
{
	int i, j, c, nw, state,maxlen;
	int nchar[MAXWORDS];
	char ch[MAXWORDS];

	nw = maxlen = 0;
	state =OUT;
	for (i = 0; i < MAXWORDS; ++i){
		nchar[i] = 0;
		ch[i] = ' ';
	}

	while ((c = getchar()) != EOF)
		if (c == '\n' || c == '\t' || c == ' ')
			state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
			++nchar[nw - 1];
			ch[nw - 1] = c;
		}
		else
			++nchar[nw - 1];

	maxlen = nchar[0];
	for (i = 0; i < MAXWORDS; ++i)
		if (nchar[i] > maxlen)
			maxlen = nchar[i];

	for (i = 0; i < MAXWORDS; ++i)
		if (i < MAXWORDS - 1)
			printf("%c ", ch[i]);
		else
			printf("%c\n", ch[i]);

	for (i = 0; i < MAXWORDS; ++i)
		if (i < MAXWORDS -1)
			printf("%d ", nchar[i]);
		else
			printf("%d\n", nchar[i]);

	for (j = 0; j < maxlen; ++j)
		for (i = 0; i < MAXWORDS; i++)
			if (i < MAXWORDS -1)
				if (nchar[i] > 0){
					printf("* ");
				    --nchar[i];
			    }
			    else
				    printf("  ");
			else
				if (nchar[i] > 0){
					printf("*\n");
					--nchar[i];
				}
				else
					printf(" \n");   
	return 0;
}