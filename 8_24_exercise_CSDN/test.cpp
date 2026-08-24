#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;



//class Time
//{
//public:
//	Time(int time)
//	{
//		_time = time;
//	}
//
//private:
//	int _time;
//};
//
//class Data
//{
//public:
//	Data(int year , int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _t(1)
//		, _a((int*)malloc(12))	
//	{
//		_n = 1; 
//	}
//
//	/*Data(int year, int month, int day ,int n)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		_t = 1;
//	}*/
//
//
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << "/" << _n << endl;
//	}
//
//
//private:
//	int _year; 
//	int _month;
//	int _day;
//
//	int _n;
//
//	int* _a; 
//
//	Time _t;
//
//};
//
//
//int main()
//{
//	Data d1(2026, 8, 24);
//	d1.print();
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	return 0;
//}



//
class hy
{
public:
	hy(int a = 1)
		:_a(a)
	{ }

	void print()
	{
		//cout << "this指针的地址->" << this << endl;
		//cout << "_a的地址" << &_a << endl;
		//cout << "_b的地址" << &_b << endl;
		cout << _a << endl;
	}
private:
	int _a = 4;
	int _b = 4;
};

int main()
{
	hy h = 3;
	h.print();

	return 0;
}


