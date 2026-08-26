#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//
//class Time
//{
//public:
//	Time(int time = 4)
//	{
//		_time = time;
//	}
//	
//private:
//	int _time;
//};
//
//
//class Data
//{
//public:
//	Data(int year, int month, int day, int i, int y)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _i(i)
//		, _y(y)
//	{ }
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _i;
//	int& _y;
//	Time _t;
//};
//
//
//int main()
//{
//
//	return 0;
//}



//class Data
//{
//public:
//	Data(int year = 1, int month =1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//
//	//内部类（默认是外部类的友元函数，但外部类并非内部类里的友元）
//	class Time
//	{
//		friend class Data;
//	public:
//		Time(int time = 4)
//			:_time(time)
//			
//		{ }
//
//	private:
//		int _time;
//	};
//
//
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	static void func(/*无this指针*/)
//	{
//		cout << _a << endl;
//		//cout << _year << endl;    //静态成员函数无法访问非静态成员变量，因为没有this指针
//	}
//
//	void print()
//	{
//		cout <<  << endl;
//	}
//
//	~Data()
//	{
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	static int _a;
//	Time _t;
//};
//
//int Data::_a = 1;
//
//
//int main()
//{
//	return 0;
//}




//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
////private:
//	int _a;
//};
//
//void func(A a)
//{
//	
//	cout << a._a << endl;
//}
//
//int main()
//{
//	func(A(1));
//	return 0;
//}





//struct ListNode
//{
//	int val;
//
//	ListNode* next;
//};
//
//
//
//int main()
//{
//	/*int* p1 = new int(1);
//	cout << *p1 << endl;
//
//	int* p2 = new int[10] {1,2,3,4,5,6};
//	
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p2[i] << " ";
//	}*/
//
//	
//	//delete p1;
//
//
//	ListNode* p1 = new ListNode;
//	ListNode* p2 = new ListNode;
//	ListNode* p3 = new ListNode;
//	ListNode* p4 = new ListNode;
//
//	p1->next = p2;
//	p2->next = p3;
//	p3->next = p4;
//
//
//	 
//
//	return 0;
//}

//
//class Solution
//{
//public:
//
//    static int _sum;
//    static int _ret;
//    //定义内部类
//    class Sum
//    {
//    public:
//        Sum()
//        {
//            _sum++;
//            _ret += _sum;
//        }
//    };
//
//
//    int Sum_Solution(int n)
//    {
//        Sum* p = new Sum[n];
//
//        return _ret;
//    }
//};
//
//int Solution::_sum = 0;
//int Solution::_ret = 0;



//class Time
//{
//
//public:
//	Time(int time)
//		:_time(time)
//		,_a(1)
//	{ }
//
//	/*void print()
//	{
//		cout << "print()成功被调用" << endl;
//	}*/
//
//	/*void show()
//	{
//		cout << this->_time << endl;
//		cout << "show()成功被调用" << endl;
//	}*/
//
//	void print()const
//	{
//		cout << _a << endl;
//	}
//
//	//void operator
//
//	//void operator()(const Time& t)
//
//
//private:
//	int _time;
//
//	const int _a;
//};
//
//int main()
//{
//	//创建一个类类型指针，空指针 
//	//Time* t = nullptr;
//
//
//	//t->print();
//
//	//t->show();
//
//	const Time t(4);
//	t.print();
//
//
//	return 0;
//}

//
//class AA
//{
//private:
//
//	AA* abc()const
//	{
//		return this;
//	}
//
//private:
//};
//
//
//
//int main()
//{
//	AA x;
//
//	x.abc();
//	return 0;
//}



class Hy
{
public:
	Hy(int a = 4)
		:_a(a)
	{ 
		cout << "Hy(int a)" << endl;
	}
	
private:
	int _a;
};


int main()
{
	Hy* p1 = new Hy(1);
	cout << endl;
	Hy* p2 = new Hy[3]{ Hy(1), Hy(2), Hy(3) };
	cout << endl;

	Hy* p3 = new Hy[3]{ {1},{2},{3} };
	return 0;
}