#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 2;
	if (c == '-') {
		if (isdigit(s[1] = c = getch())) {
			if (isdigit(c)) {
				while (isdigit(s[i++] = c = getch()))
					;
			}
			if (c == '.')
		        while (isdigit(s[i++] = c = getch()))
			        ;
	    }
	    else {
		s[1] ='\0';
		return c;
	    }
	}
	else {
		if (isdigit(s[1] = c = getch())) {
			if (isdigit(c)) {
				while (isdigit(s[i++] = c = getch()))
					;
			}
			if (c == '.')
		        while (isdigit(s[i++] = c = getch()))
			        ;
	    }
    }
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}