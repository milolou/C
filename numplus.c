#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tnode {
	char *word;
	int as;
	int count;
	struct tnode *left;
	struct tnode *right;
	struct tnode *father;
};

#define MAXWORD 100
#define GROUPSTD 0

struct tnode *addtree(struct tnode *, char *, struct tnode *);
void treeprint(struct tnode *, int);
int getword(char *, int);
int ati(char *s);

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int n;
	
	n = GROUPSTD;
	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
		n = ati(argv[2]);
	}
	else if (argv[1] != NULL && strcmp(argv[1], "-n") != 0) {
		printf("Usage: numplus -n <number>\n");
		return -1;
	}
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word, root);
	treeprint(root, n);
	return 0;
}

int ati(char *s)
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

int ascount(char *s, char *t);
struct tnode *talloc(void);
char *strdump(char *);

struct tnode *addtree(struct tnode *p, char *w, struct tnode *r)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		if (r == NULL) {
			p->as = strlen(w);
			p->father = NULL;
		}
		else {
		    p->as = ascount(w, r->word);
		    p->father = r;
		}
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w, p);
	else
		p->right = addtree(p->right, w, p);
	return p;
}

int ascount(char *s, char *t)
{
	int i;
	for (i = 0 ; *s++ == *t++; )
		i++;
	return i;
}

void treeprint(struct tnode *p, int n)
{
	if (p != NULL) {
		treeprint(p->left, n);
		if (p->as >= n) {
			if (strcmp(p->word, p->father->word) < 0) {
				printf("%4d %s\n", p->count, p->word);
				if (p->father->as < n)
					printf("%4d %s\n", p->father->count, p->father->word);
			}
			else {
				if (p->father->as < n)
					printf("%4d %s\n", p->father->count, p->father->word);
				printf("%4d %s\n", p->count, p->word);
			}
			
		}
		treeprint(p->right, n);
	}
}

#include <stdlib.h>

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdump(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int getch(void);
void ungetch(int c);

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c == '"') { 
		while ((c = getch()) != '"')
			;
	    *w++ = c;
	    *w = '\0';
	    return c;
	}
	if (c == '/') {
		*w++ = c;
		if ((c = getch()) == '*') {
			while ((c = getch()) != '/')
				;
	        *--w = c;
	        *++w = '\0';
	        return c;
		}
		else {
			ungetch(c);
			*w = '\0';
			return c;
		}
	}
	if (c == '#') {
		while ((c = getch()) != ' ')
			;
	    *w++ = c;
	    *w = '\0';
	    return c;
	}
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c) && c != '_') {
		*w = '\0';
		return c;
	} 
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}