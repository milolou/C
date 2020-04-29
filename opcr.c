#include <fcntl.h>

int fd;
int open(char *name, int flags, int perms);
fd = open(name, flags, perms);

int creat(name, perms);
fd = creat(name,perms);