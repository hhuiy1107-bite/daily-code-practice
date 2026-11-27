#define  _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

namespace hhy
{
	void list_test01()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		


		print_container(lt);

	}

}

int main()
{
	hhy::list_test01();
	return 0;
}