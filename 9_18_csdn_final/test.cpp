#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


class Data
{
public:

	friend void print(Data& d);

	Data(int year = 2026)
		:_year(year)
	{ }

private:
	int _year;
};

void print(Data& d)
{
	cout << d._year<< endl;
}

int main()
{
	Data d1;
	print(d1);
	
	return 0;
}