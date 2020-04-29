#include <stdio.h>

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

char s[4][2] = {
	{'s', 'g'},
	{'f', 'k'},
	{'t', 'b'},
	{'j', 'a'}
};

struct key tty = {"while", 0};
struct key ppy = {"typedef", 0};

struct num {
	int x;
	int y;
} n = {2, 3};

char a[] = "Hello, World!";

char *t;

char *r = "what's wrong";

int main(int argc, char const *argv[])
{
	printf("%d %d %d %s %d %d %d %d\n", &keytab, &keytab[0].count, keytab[1].count, keytab[2].word, &keytab[3], &keytab[4], &keytab[5], &keytab[6]);
	printf("%d %d %d %d\n", s, s[0], &s[1], &s[2], s[3]);
	printf("%d\n", tty);
	printf("& %d\n", &tty);
	printf("& %s\n", tty);
	printf("%s\n", tty.word);
	printf("%d\n", tty.word);
	printf("%d\n", ppy);
	printf("& %d\n", &ppy);
	printf("%d\n", ppy.word);
	printf("%d\n", n);
	printf("%d\n", &n);
	t = a;
	*t = 'h';
	printf("%s\n", t);
	printf("%d\n", &r);
	printf("%d\n", &a);
	printf("%d\n", a);
	return 0;
}