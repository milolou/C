#include <stdio.h>

void swap(char s[], int i, int j);

int main(int argc, char const *argv[])
{
	char s[6] = {'1', '2', '3', '4', '5','\0'};
	int i = 0;
	int j = 4;

   /* printf("%s\n", s); */

    for (; i < j; ++i, --j)
    	swap(s, i, j);
    printf("%s\n", s);
	return 0;
}

void swap(char s[], int i, int j)
{
	char temp;

	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}