#include <stdio.h>

/* count number of characters */
int main(int argc, char const *argv[])
{
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
	return 0;
}