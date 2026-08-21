#define  _CRT_SECURE_NO_WARNINGS 1


#include "Data.h"

Data::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Data::print()
{
	cout << _year << " " << _month << " " << _day << endl;
}


int Data::GetMonthDay(int year, int month)
{
	static int arr[13] = { 0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return arr[month];
}




Data& Data::operator+=(int num)
{
	_day += num;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}