#define  _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace hy
{
	size_t string::npos = -1;
	void string::reserve(size_t n)
	{
		if (n> _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);

			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}


	void string::push_back(char str)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size++] = str;
		_str[_size] = '\0';

	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		for (int i = 0; i < len; i++)
		{
			_str[_size++] = str[i];
		}

		_str[_size] = '\0';
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		size_t end = _size + 1;
		while (pos < end)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}


	void string::insert(size_t pos, const char* ch)
	{
		assert(pos <= _size);

		size_t len = strlen(ch);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		size_t end = _size + len;
		while (pos + len <= end)
		{
			_str[end] = _str[end - len];
			end--;
		}

		for (int i = 0; i < len; i++)
		{
			_str[pos + i] = ch[i];
		}

		_size += len;
	}

	void string::erase(size_t pos)
	{
		assert(pos < _size);

		_str[pos] = '\0';
		_size = pos;
	}

	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);
		for (int i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}


	char* string::find(const char* ch, size_t pos)
	{
		assert(pos < _size);
		
		char* re = strstr(_str, ch);
		if (re != nullptr)
		{
			return re;
		}
		return nullptr;
	}


	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		size_t 
	}


}