union u_tag {
	int ival;
	float fval;
	char *sval;
} u;

if (utype == INT)
	printf("%d\n", u.ival);
else if (utype == FLOAT)
	printf("%d\n", u.fval);
else if (utype == STRING)
	printf("%d\n", u.sval);
else
	printf("bad type %d in utype\n", utype);

struct {
	char *name;
	int flags;
	int utype;
	union {
		int ival;
		float fval;
		char *sval;
	} u;
} symtab[NSYM];

symtab[i].u.ival
*symtab[i].u.sval
symtab[i].u.sval[0]

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

enum {KEYWORD = 01; EXTERNAL = 02; STATIC = 04};

flags |= EXTERNAL | STATIC;
flags &= EXTERNAL | STATIC;
if ((flags & (EXTERNAL | STATIC)) == 0)

struct {
	unsigned int is_keyword : 1;
	unsigned int is_external : 1;
	unsigned int is_static : 1;
} flags;

flags.is_external = 1;
