#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>	
using namespace std;

//
//class A
//{
//	void printF()
//	{
//		;
//	}
//};
//
//class B
//{
//	
//};
//
//
//int main()
//{
//	A a;
//	B b;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//
//	cout << &a << endl;
//
//	return 0;
//}


//class Data
//{
//
//public:
//
//	//手动初始化函数
//	void init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//1.无参数构造函数
//	//Data()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//
//	//2.含参构造函数
//	//Data(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//3.全缺省构造函数
//	Data(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	void print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//
//private:
//
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//
//int main()
//{/*
//	Data d1;
//	d1.init(2026, 8, 9);
//	d1.print();
//
//	Data d2;
//	d2.print();
//
//	Data d3(2026, 8, 9);
//	d3.print();*/
//
//	Data d4;
//	d4.print();
//
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Add(int y, int x)
//{
//	return x + y;
//}
//
//int Add(int x, int y, int z)
//{
//	return x + y + z;
//}
//int Add(double a, double b)
//{
//	return  a + b;
//}
//
//int main()
//{
//
//	return 0;
//}



//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int x = 10)
//{
//	cout << "f(int x)" << endl;
//}
//
//int main()
//{
//	f();
//	return 0;
//}


int main()
{
	int a = 10;
	int& b = a;
	return 0;
}