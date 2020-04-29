#include "unistd.h"
#include <stdio.h>

#if defined(getchar)
   #undef getchar
#endif

int main(int argc, char const *argv[])
{
	getchar();
	return 0;
}

int getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >=  0) ? (unsigned char) *bufp++ : EOF;
}