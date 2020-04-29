typedef int length

length len, maxlen;
length *length[];

typedef char *String;

String p, lineptr[MAXLINES], alloc(int);

int strcmp(String, String);
p = (String) malloc(100);

typedef struct tnode *Treeprt;

typedef struct tnode {
	char *word;
	int count;
	Treeprt left;
	Treeprt right;
} Treenode;

Treeprt talloc(void)
{
	return (Treeprt) malloc(sizeof(Treenode));
}

typedef int (*PFI)(char *, char *)

PFI strcmp, numcmp; 