#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}


//
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//	return 0;
//}


//
//int main()
//{
//	int i = 10;
//
//	const int& j = i;
//	return 0;
//}

//表达式计算结果
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int& c = a + b;
//	return 0;
//}

//
//int Add(int& a, int& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& c = Add(a, b);
//	return 0;
//}



//
//int main()
//{
//	int a = 10;
//	double& b = a;
//	return 0;
//}


//
//inline int Add(int& a, int& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);
//	return 0;
//}


//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* x)
//{
//	cout << "f(void* x)" << endl;
//}
//
//int main()
//{
//	f(nullptr);
//	return 0;
//}

//#include <iostream>
//
//namespace A
//{
//	int a = 10;
//	int b = 20;
//}
//using  A::b;
//
//int main()
//{
//
//	printf("%d", b);
//	return 0;
//}



//class A
//{
//	//成员函数
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << _month << _day;
//	}
//
//	//成员变量
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	
//	return 0;
//}
//
//struct A
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << _month << _day;
//	}
//
//private:
//
//	int _year;
//	int _month;
//	int _day;
//
//};

//struct Hy
//{
//	int a;
//	char b;
//	double c;
//};



//class A
//{
//public:
//	//手动初始化
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//带参构造函数
//	A(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	A a;
//	a.Init(100, 20, 30);
//	a.Print();
//	return 0;
//}


//class Stack
//{
//public:
//	//默认构造函数（全缺省）
//	Stack(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
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
//
//	return 0;
//}





//class Stack
//{
//public:
//
//	//构造函数
//	Stack(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		
//		_top = 0;
//		_capacity = n;
//	}
//
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;//即使不手动置0，在销毁栈帧时也会销毁
//	}
//
//
//private:
//
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//
//
//
//int main()
//{
//
//	Stack st;
//	return 0;
//}


class Data
{
public:

	//构造函数
	Data(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//运算符重载
	bool operator==(Data d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}


private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	Data d1(2026, 8, 10);
	Data d1(2026, 8, 10);
	//d1.Print();

	Data d2(2026, 8, 10);
	//d2.Print();

	cout << d1.operator==(d2) << endl;
	d1 == d2;

	return 0;
}