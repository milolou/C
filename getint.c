#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1: 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			while ((c = getch()) != EOF && !isdigit(c))
				;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}


int getfloat(float *pn)
{
	int c, sign, time, e, si;
	float temp;

    time = 1;
    e = 1;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1: 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			while ((c = getch()) != EOF && !isdigit(c))
				;
		}
	}
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.') {
		c = getch();
		temp = *pn;
	    for (*pn = 0.0; isdigit(c); c = getch()) {
	    	*pn = 10.0 * *pn + (c - '0');
		    time *= 10;
	    }
	    temp = temp + *pn / time;
	    if (c == 'e') {
		    e = 10;
		    c = getch();
		    si = (c == '-') ? -1: 1;
            if (c == '-' || c == '+')
            	c = getch();
            for (*pn = 0.0; isdigit(c); c = getch())
    	        *pn = 10.0 * *pn + (c - '0');
            *pn = sign * temp * pow(e, *pn * si);
	    }
	    else
	    	*pn = sign * temp;
	}
	else if (c == 'e'){
		e = 10;
		c = getch();
		temp = *pn;
		si = (c == '-') ? -1: 1;
        if (c == '-' || c == '+')
        	c = getch();
        for (*pn = 0.0; isdigit(c); c = getch())
        	*pn = 10.0 * *pn + (c - '0');
        *pn = sign * temp * pow(e, *pn * si);
	}
	else
		*pn *= sign;

    if (c != EOF)
    	ungetch(c);
    return c;
}