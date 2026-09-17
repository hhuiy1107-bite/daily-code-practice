#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//class hy
//{
//public:
//	hy(int a)
//		:_a(a)
//	{ }
//
//private:
//	int _a;
//};
//
//
//int main()
//{
//	hy h1 = 1;
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	double b = 10;
//	return 0;
//}


//class Data
//{
//public:
//	explicit Data(int year)
//		:_year(year)
//	{ }
//
//private:
//	int _year;
//};
//
//int main()
//{
//	Data d1 = 2026;
//	return 0;
//}


//class Data
//{
//public:
//	operator int()
//	{
//		return _year;
//	}
//
//	Data(int year = 2026)
//		:_year(year)
//	{ }
//
//private:
//	int _year = 2026;
//};
//
//int main()
//{
//	Data d1;
//	int year = d1;
//	cout << year;
//	return 0;
//}


//class Data
//{
//public:
//	Data(int year = 2026)
//		:_year(year)
//	{ }
//
//private:
//	int _year;
//	inline static int _time = 1;
//};
//
//
//int main()
//{
//	Data d1;
//	return 0;
//}


class Data
{
public:
	Data(int year = 2026)
		:_year(year)
	{
	}
	static void print()
	{
		cout << _time << endl;
	}
private:
	int _year;
	static int _time;
};

int Data::_time = 1;

int main()
{
	Data d1(2026);
	Data d2(2025);

	d1.print();
	d2.print();
	return 0;
}