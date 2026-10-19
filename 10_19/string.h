#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace hy
{
	typedef char* iterator;
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			,_size(strlen(str))
			,_capacity(_size)
		{ 
			strcpy(_str, str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char* c_str()
		{
			return _str;
		}

		size_t c_size()
		{
			return _size;
		}

		size_t c_capacity()
		{
			return _capacity;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		void reserve(size_t size);

		void push_back(char str);
		void operator+=(char str)
		{
			push_back(str);
		}
		void operator+=(const char* str)
		{
			append(str);
		}

		void append(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* ch);

		void erase(size_t pos);

		size_t find(char ch, size_t pos =0);

		char* find(const char* ch, size_t pos = 0);
		string substr(size_t pos, size_t len = npos);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};
}
