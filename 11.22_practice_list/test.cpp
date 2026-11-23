#define  _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

namespace hhy
{
	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		//list<int>::iterator it = lt.begin();
		//lt.end()返回的是一个临时变量，具有右值属性，所以在iterator参数列表中需要const
		//while (it != lt.end())
		//{
		//	cout << *it << " ";
		//	++it;
		//}

	}

	void list_test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		print_container(lt);

		cout << endl;
		
		list<int> lt0(lt);
		print_container(lt0);


		list<int> lt1;
		lt1 = lt;
		print_container(lt1);

		//list<AA> lt;
		//lt.push_back(AA());
		//lt.push_back(AA());
		//lt.push_back(AA());
		//lt.push_back(AA());
		//lt.push_back(AA());

		////print_container(lt);
		//list<AA>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	cout << it->a << " " << it->b << endl;
		//	++it;
		//}
	}


}

int main()
 {

	//hhy::list_test1();
	hhy::list_test2();
	return 0;
}