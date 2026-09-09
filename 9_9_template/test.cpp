#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	//int i = 0; 
	//int j = 1;
	//Swap(i, j);
	//cout << i << " " << j << endl;
	//Swap<int>(i, j);
	//cout << i << " " << j << endl;

	//swap(i, j);
	//cout << i << " " << j << endl;


	//string st1("abcdef", 5);
	//cout << st1 << endl;

	//string st2(st1, 5);
	//cout << st2 << endl;


	//string st3("abcdef", 7);
	//cout << st3 << endl;

	//string st4(10, 'X');
	//cout << st4 << endl;

	//st4 = st1;
	//cout << st4 << endl;
	//cout << st4[3] << endl; 


	//for (int i = 0; i < st4.size(); i++)
	//{
	//	cout << st4[i] << " " << endl;
	//}

	string st;
	return 0;
}