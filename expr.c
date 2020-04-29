#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'

void push(float f);
float pop(void);

int main(int argc, char const *argv[])
{
    char c;
    float op2;

	while (--argc > 0) {
		++argv;
		c = (*argv[0] == '+' || *argv[0] =='x' || *argv[0] == '-' || *argv[0] == '/') ? *argv[0] : NUMBER;
		switch (c) {
			case NUMBER:
			    push(atof(*argv));
			    break;
			case '+':
			    push(pop() + pop());
			    break;
			case 'x':
			    push(pop() * pop());
			    break;
			case '-':
			    op2 = pop();
			    push(pop() - op2);
			    break;
			case '/':
			    op2 = pop();
			    push(pop() / op2);
			    break;
			default:
			    printf("unknown commamnd\n");
			    break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}

#define MAXPO 20
static float n[MAXPO];

static float *p = n;

void push(float f)
{
	if (p < (n + MAXPO))
	    *p++ = f;
	else
		printf("too many numbers\n"); 
}

float pop(void)
{
	if (p < n) {
		printf("stack has been empty\n");
		return 0.0;
	}
	else
		return *--p;
}