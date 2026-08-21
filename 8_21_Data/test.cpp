#define  _CRT_SECURE_NO_WARNINGS 1


#include "Data.h"

int main()
{
	Data d1(2026, 8, 21);
	Data d2 = d1 += 10000000;

	d1.print();
	d2.print();
	return 0;
}