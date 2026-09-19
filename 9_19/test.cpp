#define  _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;

//
//class Data
//{
//public:
//	
//	friend class Time;
//
//	Data(int year = 2026)
//		:_year(year)
//	{
//	}
//
//private:
//	int _year;
//};
//
//
//class Time
//{
//public:
//	Time(int time = 1)
//		:_time(time)
//	{
//	}
//
//	void func(Data& d)
//	{
//		cout << d._year << endl;
//	}
//
//private:
//	int _time;
//};
//
//int main()
//{
//	Data d1;
//	Time t1;
//	t1.func(d1);
//	return 0;
//}


//
//class Data
//{
//public:
//
//	friend void print(Data& d);
//
//	Data(int year = 2026)
//		:_year(year)
//	{}
//
//private:
//	int _year;
//};
//
//void func()
//
//void print(Data& d)
//{
//	cout << d._year << endl;
//}
//
//int main()
//{
//	Data d1;
//	print(d1);
//	return 0;
//}

//
//class A
//{
//private:
//    int _a = 10;
//
//    friend class B;
//
//    void func(B& bb)
//    {
//        cout << bb._b << endl;
//    }
//
//};
//
//class B
//{
//public:
//    void func(A& aa)
//    {
//        cout << aa._a << endl; 
//    }
//
//private:
//    int _b = 20;
////};
//
//
//class Data
//{
//public:
//	Data(int year = 10)
//		:_year(year)
//	{ }
//	class Time
//	{
//	public:
//		Time(int time = 1)
//			:_time(time)
//		{ }
//		
//		void print(Data& d)
//		{
//			cout << _time << endl;
//			cout << d._year << endl;
//		}
//
//	private:
//		int _time;
//	};
//
//	
//
//private:
//	int _year;
//};
//
//int main()
//{
//	Data d1;
//	Data::Time t;
//	t.print(d1);
//	cout << sizeof(t) << endl;
//	return 0;
//}



//class A
//{
//public:
//
//	class B
//	{
//	private:
//		int _b;
//	};
//
//private:
//	int _a;
//};




class Data
{
public:

	Data(int year = 2026)
		:_year(year)
	{}

	void func()
	{
		cout << _year << endl;
	}

private:
	int _year;
};



int main()
{

	Data().func();
	cout << 10000009 << endl;

	return 0;
}