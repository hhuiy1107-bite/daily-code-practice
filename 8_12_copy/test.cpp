#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//class Data
//{
//public:
//	//构造函数
//	Data(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data d1(2026, 8, 12);
//	d1.print();
//
//	Data d2(d1);
//	d2.print();
//	return 0;
//}

//
//class Stack
//{
//
//public:
//	//拷贝构造函数
//	Stack(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return; 
//		}
//		_top = 0;
//		_capacity = n;
//	}
//
//	//拷贝构造函数
//	Stack(const Stack& d)
//	{
//		_a = (int*)malloc(sizeof(int) * d._capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_a, d._a, sizeof(int) * d._top);
//		_top = d._top;
//		_capacity = d._capacity;
//	}
//
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
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
//	Stack st1;
//	Stack st2(st1);
//	return 0;
//}




class Data
{
public:
	//构造函数
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//运算符重载
	bool operator== (Data& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}



	//赋值重载
	Data& operator= (const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}




private:
	int _year;
	int _month;
	int _day;
};




Data& func()
{
	Data d(2026, 8, 13);
	
	return d;
}



int main()
{

	Data d1(2026, 8, 12);

	Data d2(2026, 8, 11);

	Data d3(2026, 8, 13);

	//d2 = d1;
	/*int re = d2 == d1;
	cout << re << endl;*/

	//d2 = func();

	d3 = d2 = d1;

	return 0;
}