#include <limits.h>

void itoa(int n,char s[])
{
	int i, sign;

    if (n < LONG_MIN) {
    	if ((sign = n) < 0)
    		n = -n;
    }
    else {
    	sign = n;
    	n = -(n + 1);
    }
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	if (sign = LONG_MIN)
		s[0] = s[0] + 1;
	s[i] = '\0';
	reverse(s);
}