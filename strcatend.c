#include <stdio.h>

void srcat(char *s, char *t);
int srend(int *s, int *t);

int main(int argc, char const *argv[])
{
	int i, c, j;
	char s[200], t[200];
	
	i = 0;
	j = 0;
	while ((c = getchar()) != EOF) {
		s[i++] = c;
		t[j++] = c;
		if (c == '\n') {
			s[i] = '\0';
			t[j] = '\0';
			break;
		}
	}

	srcat(s, t);
	printf("%s\n", s);
	return 0;
}

void srcat(char *s, char *t)
{
	while(*s != '\0')
		s++;
	while((*s++ = *t++) != '\0')
		;
}

int srend(int *s, int *t)
{
	while (*s != *t)
		s++;
	while (*s++ == *t++)
		if (*s == '\0')
			return 1;
	return 0;
}