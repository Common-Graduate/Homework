#include<stdio.h>       //用结构体计算日期是本年的第几天
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;
int FUN(struct Date* pd);
int main()
{
	Date date_0;
	printf("Please input a date：\nFor example：2021.12.31\n");
	scanf("%d.%d.%d", &date_0.year, &date_0.month, &date_0.day);
	int a = 0;
	a = FUN(&date_0);
	printf("The day is the %d day.", a);
	return 0;
}
int FUN(struct Date* pd)
{
	int sum = 0;
	switch (pd->month - 1)
	{
	case 11:sum += 30;
	case 10:sum += 31;
	case 9:sum += 30;
	case 8:sum += 31;
	case 7:sum += 31;
	case 6:sum += 30;
	case 5:sum += 31;
	case 4:sum += 30;
	case 3:sum += 31;
	case 2: 
	{
		if ((pd->year % 100 != 0 && pd->year % 4 == 0) || (pd->year % 400 == 0))
			sum += 29;
		else
			sum += 28;
	}
	case 1:sum += 31;
	default:sum += pd->day;
	}
	return sum;
}