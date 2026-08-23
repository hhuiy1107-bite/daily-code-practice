#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//class Data
//{
//
//	friend void operator<<(ostream& out, Data d1);
//public:
//	//构造函数
//	Data(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;z
//		_year = 1;
//	}
//	//拷贝构造函数
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		
//	}
//	
//
//	void print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void operator<<(ostream& out, Data d1)
//{
//	out << d1._year << " " << d1._month << " " << d1._day << endl;
//}
//
//int main()
//{
//	Data d1(2026, 8, 23);
//	d1.print();
//
//	Data d2(d1);
//	cout << d2;
//
//	return 0;
//}



//
//class Stack
//{
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
	//拷贝构造函数
	//Stack(const Stack& s)
	//{
	//	_a = (int*)malloc(sizeof(int) * s._capacity);
	//	if (_a == nullptr)
	//	{
	//		perror("malloc fail");
	//		exit(1);
	//	}
	//	_top = s._top;
	//	_capacity = s._capacity;
	//	//只需拷贝有效数据个数，拷贝整个capacity会有空间还未利用
	//	memcpy(_a, s._a, sizeof(int) * s._top);
	//}

//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1;
//
//	Stack s2 = s1;//或者Stack s2 (s1);
//	cout << s1._a << endl;
//	cout << s2._a << endl;
//	return 0;
//}




class Data
{
public:
	Data()
		
	{ }


	void print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};


int main()
{
	Data d1;
	d1.print();
	return 0;
}