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

		lt.insert(lt.begin(), 100);

		lt.insert(lt.end()++, 66);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//for (auto e : lt)
		//{
		//	cout << e << " ";
		//}

		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;


		lt.erase(lt.begin());
		for (auto e : lt)
		{
			cout << e << " ";
		}

		cout << endl;


		//lt.erase(lt.end());
		//for (auto e : lt)
		//{
		//	cout << e << " ";
		//}

	}

}


int main()
{
	hhy::list_test01();
	return 0;
}