#define  _CRT_SECURE_NO_WARNINGS 1

#include "string.h"


namespace hy
{
	static size_t npos = -1;

	void string::reserve(size_t len)
	{
		if (len > _capacity)
		{
			char* tmp = new char[len + 1];

			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = len;
		}
	}

	void string::push_back(const char ch)
	{
		//先判断是否空间足够
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void string::operator+=(const char ch)
	{
		push_back(ch);
	}

	void string::append(const char* ch)
	{
		size_t len = strlen(ch);


		//if (len + _size > _capacity)
		//{
		//	size_t newcapacity = (_capacity == 0 ? 4 : _capacity * 2);
		//	//保证边界为0的问题，大于二倍要多少给多少
		//	if (len + _size > _capacity)
		//	{
		//		newcapacity = len + _size;
		//		reserve(newcapacity);
		//	}
		//}

		if (len + _size > _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
		}

		for (int i = 0; i < len; i++)
		{
			_str[_size] = ch[i];
			_size++;
		}
		_str[_size] = '\0';
	}


	void string::insert(size_t pos, const char ch)
	{
		assert((pos >= 0) && (pos <= _size));
		if (_size + 1 > _capacity)
		{
			reserve(_size + 1);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}


	void string::insert(size_t pos, const char* ch)
	{
		assert(pos >= 0 && pos <= _size);
		size_t len = strlen(ch);
		if (len + _size > _capacity)
		{
			reserve(len + _size > _capacity * 2 ? len + _size : _capacity * 2);
		}
		size_t end = _size + len;

		while (end > pos)
		{
			_str[end] = _str[end - len];
			end--;
		}
		
		for (int i = 0; i < len; i++)
		{
			_str[pos + i] = ch[i];
			_size++;
		}
	}

	char string::operator[](size_t pos)
	{
		return _str[pos];
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len > _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			//erase越界问题  123456
			//for (size_t i = pos; i < _size; i++)
			//{

			//	_str[i] = _str[i + len];
			//}

			for (size_t i = pos + len; i < _size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
	}



	//从pos位置找ch，找到返回下标
	size_t string::find(const char ch, size_t pos = 0)
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}


	size_t string::find(const char* str, size_t pos = 0)
	{
		assert(pos < _size);

		char* ret = strstr(_str, str);
		if (ret != nullptr)
		{
			return ret - _str;
		}
		return npos;
	}


	//从pos位置开始取出len个字符，并返回string
	string& string::substr(size_t pos = 0, size_t len = npos)
	{
		assert(pos < _size);

		if (len > _size)
		{
			len = _size - 1;
		}

		string tmp;
		tmp.reserve(len);

	}




	void stringtest01()
	{
		string st1 = "abcd";
		cout << st1.str() << endl;

		st1.push_back('*');
		cout << st1.str() << endl;

		st1 += 'x';
		cout << st1.str() << endl;


		st1.append("&&&&");
		cout << st1.str() << endl;

		st1.append("（（（（（（（（（（（（（");
		cout << st1.str() << endl;
	}

	void stringtest02()
	{
		string st1;
		cout << st1.str() << endl;

		st1.push_back('*');
		cout << st1.str() << endl;
		st1.push_back('*');
		cout << st1.str() << endl;

		st1.append("*********&&&&&&&%%%%%%%");
		cout << st1.str() << endl;

	}


	void stringtest03()
	{
		string st1;
		st1.append("abcdef");
		cout << st1.str() << endl;

		//如果end为_size那么最后一处会使得end--到-1，但是无符号-1为正的最大值，所以又判断end > pos所以死循环
		st1.insert(st1.size(), '*');
		cout << st1.str() << endl;

		st1.insert(st1.size(), "$$$");
		cout << st1.str() << endl;

		cout << st1[1] << endl;

	}

	void stringtest04()
	{
		string st1("abcdefg");
		cout << st1.str() << endl;

		//st1.erase(2, 80);
		//cout << st1.str() << endl;

		cout << st1.find("hah", 0) << endl;
	}

}

