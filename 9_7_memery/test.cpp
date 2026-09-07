#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 1)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};


int main()
{

	//int* p1 = new int;
	//free(p1);

	//cout << endl;

	//A* p2 = new A;
	//delete p2;
	//cout << endl;


	A* p3 = new A[5];
	delete p3;

	return 0;
}