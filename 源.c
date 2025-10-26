#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) 
{
	if((year%4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
		return true;
	else 
		return false;
}

int get_days_of_month(int year, int month) 
{
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 2 && is_leap_year(year)) 
		return 29;
	else 
		return days[month];
}

int main()
{
	int year = 0;
	int month = 0;
	scanf("%d %d", &year, &month);

	int days = get_days_of_month(year, month);

	printf("%d\n", days);

	return 0;
}