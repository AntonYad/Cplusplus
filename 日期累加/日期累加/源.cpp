#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int n, year, month, day, num;
	int _day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> year >> month >> day >> num;
		while (num>_day[month - 1])
		{
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
			{
				_day[1] = 29;
			}
			else
			{
				_day[1] = 28;
			}
			num = num - _day[month - 1] + day;
			month++;
			day = 0;
			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
		printf("%4d-%02d-%02d\n", year, month, num);
	}
	return 0;
}