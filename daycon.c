#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day > daytab[leap][month])
		printf("The the you input is over limit of %d\n", daytab[leap][month]);
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap, sum;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (sum = 0, i = 0; i <= 12; i++)
		sum += daytab[leap][i];
	if (yearday > sum)
		printf("The day you input is over limit of %d\n", sum);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
} 