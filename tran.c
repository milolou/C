void itob(int n, char s[], int b)
{
	int i, sign;

    if ((sign = n) < 0)
    	n = -n;
	i = 0;
	do {
		s[i++] = n % b + '0';
	} while (n /= b > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}