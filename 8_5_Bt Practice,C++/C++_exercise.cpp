#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;
	int& c = b;

	//指向性不能改变
	int d = 20;
	c = 20;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;

	return 0;
}