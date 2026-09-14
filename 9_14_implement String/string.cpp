#define  _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace hy
{
	void string_test01()
	{
		string st1;

		string st2("abcde");

		cout << st1.c_str() << endl;
		cout << st2.c_str() << endl;
	}
}