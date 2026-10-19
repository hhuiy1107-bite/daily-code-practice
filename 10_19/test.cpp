#define  _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace hy
{
	void string_test01()
	{
		string st1("hello world");
		st1.push_back('h');
		cout << st1.c_str() << endl;

		st1.append("*******");
		cout << st1.c_str() << endl;

		st1 += 'h';
		cout << st1.c_str() << endl;
		st1 += "ch";
		cout << st1.c_str() << endl;
	}


	void string_test02()
	{
		string st1("hello world");
		st1.insert(st1.c_size(), 'h');
		cout << st1.c_str() << endl;

		st1.insert(st1.c_size(), "*****");
		cout << st1.c_str() << endl;

		//st1.erase(2);
		//cout << st1.c_str() << endl;

		//cout << st1.find('i') << endl;

		char* re = st1.find("ello");
		
		iterator it = st1.begin();

		while (it != st1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto s : st1)
		{
			cout << s << " ";
		}
		cout << endl;
	}

}



	int main()
	{

		//string_test01();
		hy::string_test02();

		return 0;
	}

