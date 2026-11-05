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
		
		cout << v.size() << " " << v.capacity() << endl;
		print_vector(v);
	}



}

int main()
{
	hhy::vector_test02();
	


	//int i = 10;
	//const int& j = i;
	//
	//int* k = &i;
	//const int*& l = k;


	

	return 0;
}