unsigned short int sh;
signed long int counter;
'\ooo'
'\xhh'
#define VTAB '\013'
#define BELL '\007'
#define VTAB '\xb'
#define BELL '\x7'
'\f'
'\v'
#define MAXLINE 1000

char line[MAXLINE + 1];

#define LEAP 1
int days[31 + 28];
"I am a string"
enum boolean {NO, YES};
enum escapes {BELL = '\a', BACKSPACE = '\b'};
const double e = 2.718;

if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	printf("%d is leap year\n", year);
else
	printf("%d is not a leap year\n", year);

-3 * -8 + 6 = 30;

int i = 0;
while (i >= 0){
	if (i < lim -1){
		c = getchar();
	    if (c != '\n'){
	    	if (c != EOF){
	    		s[i] = c;
	    		++i;
	    	}
	    	else
	    		break;
	    }
	    else
	    	break;
    }
    else
    	break;
}

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0')
	return n;
}


int htoi(char s[])
{
	int i, n;

	i = n = 0;
	while (i >= 0){
		if (s[i] >= '0' && s[i] <= '9'){
			n = n * 16 + (s[i] - '0');
			++i;
		}
		else if (s[i] >= 'a' && s[i] <= 'f'){
			n = n * 16 + (s[i] -'a' + 10);
			++i;
		}
		else if (s[i] >= 'A' && s[i] <= 'F'){
			n = n * 16 + (s[i] - a + 10);
			++i;
		}
		else
			return n;
	}
}

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0', i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

void destr(char s[], char t[])
{
	int i, j, k;

    i = k = 0;
	for (j = 0;t[j] != '\0'; ++j){
		while (s[i] != '\0'){
			if (s[i] != t[j])
				s[k++] = s[i];
			++i;
		}
		s[k] = '\0';
		i = 0;
		k = 0;
    }
}

void any(char s[], char t[])
{
	int i, j, m;

    i = j = m = 0;
	while (s[i] != '\0') {
		while (t[j] != '\0') {
			if (t[j] = s[i]){
				printf("%d ", i);
				m = i;
			}
			++j;
		}
		j = 0;
	}

	if (m == 0)
		printf("%d\n", -1);
}

int bitcount(unsigned x)
{
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
		return b;
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; ++b)
		x &= x - 1;
}


z = (a > b) ? a : b;


for (i = 0; i < n; i++)
	printf("%6d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');

printf("You have %d item%s.\n", n, n == 1 ? "" : "s");

(c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;