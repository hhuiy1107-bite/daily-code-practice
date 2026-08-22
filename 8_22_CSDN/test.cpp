#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Data
//{
//public:
//	//全缺省构造函数
//	Data(int year = 2022, int month = 10, int day = 9)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//无参构造函数
//	/*Data()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}*/
//
//	void print()const
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//	//取地址重载
//	const Data* operator&()const
//	{
//		return this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	const Data d1;
//	d1.print();
//
//	cout << &d1 << endl;
//
//	return 0;
//}

//
//class Hy
//{
//public:
//	//未显式实现构造函数
//	void print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	Hy a1;
//	a1.print();
//	return 0;
//}


//class Stack
//{
//
//public:
//	//构造函数
//	Stack(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		_top = 0;
//		_capacity = n;
//	}
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//	}
//
//	//拷贝构造函数
//
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1;
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
private:
	int _year;
	int _month;
	int _day;
};