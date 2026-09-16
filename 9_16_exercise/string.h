#pragma once

#include <iostream>
#include <assert.h>
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
		{
		}

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


		void reserve(size_t n);
		void push_back(const char ch);
		void operator+=(const char ch);
		void operator+=(const char* ch);
		void append(const char* ch);
		char& operator[](size_t pos);
		void 

		void insert(size_t pos, const char ch);
		void insert(size_t pos, const char* ch);



		//Ä£Äâµü´úÆ÷
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

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


