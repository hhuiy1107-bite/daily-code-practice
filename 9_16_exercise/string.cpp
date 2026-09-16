#define  _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace hy
{

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* new_str = new char[n + 1];

			strcpy(new_str, _str);
			delete[] _str;

			_str = new_str;
			_capacity = n;
		}

	}


	void string::push_back(const char ch)
	{
		//插入前判断是否满
		if (_capacity == _size)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		_str[_size + 1] = '\0';
		_size++;
	}


	void string::operator+=(const char ch)
	{
		//插入前判断是否满
		if (_capacity == _size)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		_str[_size + 1] = '\0';
		_size++;
	}


	void string::append(const char* ch)
	{
		size_t len = strlen(_str) + strlen(ch);
		if (len > _capacity)
		{
			//大于二倍则要多少开多少，小于二倍还给二倍对齐	 
			reserve(len > 2 * _capacity ? len : 2 * _capacity);
		}

		for (int i = 0; i < strlen(ch); i++)
		{
			_str[_size] = ch[i];
			_size++;
		}
		_str[_size] = '\0';
	}


	void string::operator+=(const char* ch)
	{
		size_t len = strlen(this->c_str()) + strlen(ch);

		reserve(len);
		for (int i = 0; i < strlen(ch); i++)
		{
			_str[_size] = ch[i];
			_size++;
		}
		_str[_size] = '\0';
	}


	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}



	void string::insert(size_t pos, const char ch)
	{
		assert(pos <= _size);
		reserve(strlen(_str) + 1);

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

		size_t len =  strlen(ch);

		reserve(len + _size);

		size_t end = _size + len;
		while (pos < end)
		{
			_str[end] = _str[end - len];
			end--;
		}
		
		for (int i = 0; i < len; i++)
		{
			_str[pos] = ch[i];
			pos++;
			_size++;
		}
	}


	void string_test01()
	{
		string st1;

		string st2("abcde");

		//cout << st1.c_str() << endl;
		cout << st2.c_str() << endl;

		/*st2.push_back('*');
		cout << st2.c_str() << endl;

		st2.append("****");
		cout << st2.c_str() << endl;

		st2 += 'x';
		cout << st2.c_str() << endl;

		string::iterator it = st2.begin();
		while (it != st2.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		cout << st2[1] << endl;

		cout << "**************" << endl;*/


		//st2.insert(st2.size(), '%');
		//cout << st2.c_str() << endl;

		st2.insert(0, "****");
		cout << st2.c_str() << endl;
	}

}