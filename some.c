#include <string.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = (char) c;
	}
}


void expand(char s1[], char s2[])
{
	int i, j, k;
	char s[27];

	s = "abcdefghijklmnopqrstuvwxyz"

	for (i = 0, j = 0; (s2[j] = s1[i]) != '\0'; ++i, ++j) {
		if (s1[i] == 'a') {
			++i;
			if (s1[i] == '-') {
				++i;
				if (s[i] == 'z') {
					for (k = 0; s[k] !='\0'; ++k, ++j) {
						s2[j] = s[k];
					}
				}
				else
					i = i -2;
			}
			else
				--i;
		}
	}
}