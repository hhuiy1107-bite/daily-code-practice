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
	//	cout << v.capacity() << endl;

	//	v.push_back(5);
	//	cout << v.capacity() << endl;
	//	print_vector(v);
	//}


	void vector_test02()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		v.insert(v.begin() + 1 , 20);
		v.insert(v.begin() + 3, 40);

		
		cout << v.size() << " " << v.capacity() << endl;
		print_vector(v);



		v.pop_back();
		cout << v.size() << " " << v.capacity() << endl;
		print_vector(v);
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		print_vector(v);

	}




	void vector_test03()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		print_vector(v);

		//vector<int>::iterator p = find(v.begin(), v.end(), 8);
		//v.erase(p);

		//print_vector(v);

	}


	void vector_test04()
	{
		//vector<int> v;
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);
		//v.push_back(5);
		//print_vector(v);
		//cout << v.size() << " " << v.capacity() << endl;

		//cout << endl;

		//v.resize(15, 10);
		//print_vector(v);
		//cout << v.size() << " " << v.capacity() << endl;


		vector<string> v;
		v.push_back("11111");
		v.push_back("11111");
		v.push_back("11111");
		v.push_back("11111");
		v.push_back("11111");
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

		cout << endl;

		v.resize(15, "222222");
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;

	}

	void vector_test05()
	{
		//vector<int> v(10, 7);
		//cout << v.size() << " " << v.capacity() << endl;
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);
		//v.push_back(5);
		//print_vector(v);
		//cout << v.size() << " " << v.capacity() << endl;


		string st = { "123456" };
		vector<char> v(st.begin(), st.end());
		print_vector(v);
		cout << v.size() << " " << v.capacity() << endl;
	}




	void vector_test06()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		print_vector(v1);
		cout << endl;


		vector<int> v2(v1);
		print_vector(v2);
		cout << endl;

		vector<int> v3 = v2;
		print_vector(v2);

	}



}

int main()
{
	//hhy::vector_test02();
	
	//hhy::vector_test03();
	//hhy::vector_test04();

	//hhy::vector_test05();

	hhy::vector_test06();




	//int i = 10;
	//const int& j = i;
	//
	//int* k = &i;
	//const int*& l = k;


	

	return 0;
}