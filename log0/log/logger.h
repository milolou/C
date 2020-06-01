#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>

enum levelType 
{
	DEBUG, 
	INFO, 
	WARNING, 
	ERROR, 
	CRITICAL
};

struct config {
	enum levelType level;
	char *format[5];
	FILE *fp;
};

struct log {
	void (*basiConfig)(int level, char *format);
	int (*debug)(char *s);
	int (*info)(char *s);
	int (*warning)(char *s);
	int (*error)(char *s);
	int (*critical)(char *s);
	int (*disable)(int n);
	void (*stop)(void);
	int DEBUG;
	int INFO;
	int WARNING;
	int ERROR;
	int CRITICAL;
};

void basiConfig(int level, char *format);
int debug(char *s);
int info(char *s);
int warning(char *s);
int error(char *s);
int critical(char *s);
int disable(int n);
void stop(void);

//extern struct config baseConfig;
struct log logging = {
	basiConfig,
	debug,
	info,
	warning,
	error,
	critical,
	disable,
	stop,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

#endif
