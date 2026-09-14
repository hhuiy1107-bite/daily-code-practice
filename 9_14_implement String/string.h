#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace hy
{
	class string
	{
	public:
		string()
			: _str(new char('\0'))
			, _size(0)
			, _capacity(0)
		{ }

		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}


		size_t capacity() const
		{
			return _capacity;
		}


		void push_back(const char* ch);


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void string_test01();
}


