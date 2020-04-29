#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char const *argv[])
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
			    push(atof(s));
			    break;
			case '+':
			    push(pop() + pop());
			    break;
			case '*':
			    push(pop() * pop());
			    break;
			case '%':
			    op2 = pop();
			    push((int) pop() % (int) op2);
			    break;
			case '-':
			    op2 = pop();
			    push(pop() - op2);
			    break;
			case '/':
			    op2 = pop();
			    if (op2 != 0.0)
			    	push(pop() / op2);
			    else
			    	printf("error: zero divisor\n");
			    break;
			case '\n':
			    printf("\t%.8g\n", pop());
			    break;
			default:
			    printf("error: unknown command %s\n", s);
			    break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    extern int sp;

	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    extern int sp;

	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(char t[]);
void ungetch(int);

int getop(char s[])
{
	int i, c;
	static char t[2];
	t[0] = '\0';

	while ((s[0] = c = getch(t)) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 2;
	if (c == '-') {
		if (isdigit(s[1] = c = getch(t))) {
			if (isdigit(c)) {
				while (isdigit(s[i++] = c = getch(t)))
					;
			}
			if (c == '.')
		        while (isdigit(s[i++] = c = getch(t)))
			        ;
	    }
	    else {
		s[1] ='\0';
		return c;
	    }
	}
	else {
		if (isdigit(s[1] = c = getch(t))) {
			if (isdigit(c)) {
				while (isdigit(s[i++] = c = getch(t)))
					;
			}
			if (c == '.')
		        while (isdigit(s[i++] = c = getch(t)))
			        ;
	    }
    }
	s[i] = '\0';
	if (c != EOF)
		/* ungetch(c) */
		t[0] = c;
	return NUMBER;
}

void printop(void);
void copytop(void);
double pastetop(void);
void exchangetop(void);
void deletestack(void);
double d;

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(char t[])
{
	int c;
	/* return (bufp > 0) ? buf[--bufp]: getchar(); */
	if (t[0] != '\0') {
		c = t[0];
		t[0] = '\0';
		return c;
	}
	else
		return getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


void printop(void)
{
    extern int sp;

	printf("%.8g\n", pop());
	sp++;
}

void copytop(void)
{
    extern int sp;
    extern double d;

	d = pop();
	sp++;
}

double pastetop(void)
{
    extern double d;

	return d;
}

void exchangetop(void)
{
	double s, j;

	s = pop();
	j = pop();
	push(j);
	push(s);
}

void deletestack(void)
{
	extern int sp;
	sp = 0;
}