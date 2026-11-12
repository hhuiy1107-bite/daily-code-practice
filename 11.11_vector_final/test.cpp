#define  _CRT_SECURE_NO_WARNINGS 1

#include "vector.h"

namespace hhy
{
	//void vector_test01()
	//{
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);

	//	print_vector(v);
	//	cout << v.size() << " " << v.capacity() << endl;

	//	//v.pop_back(v);
	//	//print_vector(v);
	//	//cout << v.size() << " " << v.capacity() << endl;


	//	v.insert(v.begin() + 1, 20);
	//	print_vector(v);
	//	cout << v.size() << " " << v.capacity() << endl;


	//}



	void vector_test02()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

		auto it = v.insert(v.begin() + 1, 20);
		*it *= 30;
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

		cout << endl;


		//v.erase(v.begin() + 2, 1);
		//print_vector(v);
		//cout << v.size() << " " << v.capacity() << endl;


		v.resize(7, 3);
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

	}


	void vector_test03()
	{
		vector<string> v;
		v.push_back("111111");
		v.push_back("111111");
		v.push_back("111111");
		v.push_back("111111");
		v.push_back("111111");

		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

		//v.pop_back();
		//print_vector(v);


		v.resize(3, "2222");
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;


		//因为没有写拷贝构造，默认的只能是浅拷贝，对同一块空间析构了两次
		vector<string> vv = v;
		print_vector(v);


	}
}



int main()
{
	//hhy::vector_test01();
	//hhy::vector_test02();
	hhy::vector_test03();
	return 0;
}