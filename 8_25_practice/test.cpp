#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;



//class Data
//{
//public:
//	Data(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{ }
//
//	/*bool operator==(const Data& d)
//	{
//		return (_year == d._year)
//			&& (_month == d._month)
//			&& (_day == d._day);
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1(2026, 8, 25);
//
//	Data d2(2026, 8, 24);
//
//	//int re = d1 == d2;
//	//cout << re << endl;
//
//	return 0;
//}



//class Data
//{
//public:
//	Data(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//
//	void operator=(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void operator<<(/*第一参数默认传入this指针*/ostream& out)
//	{
//		out << _year << endl;
//	}
//
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1(2026, 8, 25);
//	/*d1 << cout;*/
//
//
//	return 0;
//}



//class Stack
//{
//public:
//	Stack(int n = 4)
//		: _a((int*)malloc(sizeof(int)* n))
//		, _top(0)
//		, _capacity(n)
//	{
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(1);
//		}
//	}
//
//	Stack& operator=(const Stack& st)
//	{
//		_a = (int*)malloc(sizeof(int) * st._capacity);
//		
//		_top = st._top;
//		_capacity = st._capacity;
//
//		memcpy(_a, st._a, sizeof(int) * st._top);
//
//		return *this;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1(8);
//	Stack st2;
//	Stack st3;
//
//	st3 = st2 = st1;
////	return 0;
//}








class Data
{
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	
	Data* operator&()
	{
		return nullptr;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	Data d1(2026, 8, 25);
	cout << &d1 << endl;
	return 0;
}