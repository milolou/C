void escape(char s[], char t[], int n)
{
	int i, j;
	char c;

	i = j = 0;
	while (i < n) {
		c = t[i++];
		switch (c) {
			case '\n':
			    t[j++] = '\\';
			    t[j++] = 'n';
			    break;
			case '\t':
			    t[j++] = '\\';
			    t[j++] = 't';
			    break;
			default:
			    t[j++] = c;
			    break;
		}
		t[j] = '\0';
	}
}