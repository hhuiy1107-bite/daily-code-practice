#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

int Add(int x = 10, int y = 20)
{
	return x + y;
}

int main()
{
	int re1 = Add();
	std::cout << re1 << std::endl;

	int re2 = Add(1, 2);
	std::cout << re2 << std::endl;
	return 0;
}