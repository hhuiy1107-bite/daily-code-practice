#pragma once

#include <iostream>
#include <assert.h>

using namespace std;


namespace hy
{
	class string
	{
	public:

		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		char* str()
		{
			return _str;
		}

		void reserve(size_t len);
		void push_back(const char ch);
		void operator+=(const char ch);
		void append(const char* ch);
		void insert(size_t pos, const char ch);
		void insert(size_t pos, const char* ch);
		char operator[](size_t pos);
		void erase(size_t pos, size_t len);
		size_t find(const char ch, size_t pos);
		size_t find(const char* str, size_t pos);
		string& substr(size_t pos, size_t len = npos);
		

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void stringtest01();

	void stringtest02();

	void stringtest03();

	void stringtest04();


}
