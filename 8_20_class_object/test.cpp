#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>	
using namespace std;

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


	//析构函数
	~Data()
	{
		;
	}

	//拷贝构造函数
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print()		
	{
		cout << _year << " " << _month << " " << _day << endl;
	}


	////运算符重载
	//bool operator==(Data& d)
	//{
	//	return (_year == d._year) && (_month == d._month) && (_day == d._day);
	//}

	
	//赋值重载
	void operator=(Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



//private:
public:
	int _year;
	int _month;
	int _day;
};

//
////运算符重载
//bool operator==(Data d1, Data d2)
//{
//	return (d1._year == d2._year) && (d1._month == d2._month) && (d1._day == d2._day);
//}

int main()
{
	Data d1(2026, 8, 20);
	d1.print();

	Data d2(d1);

	//int re = operator==(d1, d2);
	//cout << re << endl; 



	Data d3(2026, 8, 21);


	//赋值重载
	//d3 = d1;


	int i = 0;
	int j = 1;
	int& a = i;

	a = j;
	cout << a << endl;
	cout << i << endl;
	
	return 0;
}