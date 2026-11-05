#pragma once

#include <assert.h>
#include <iostream>
using namespace std;

namespace hhy
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;


		size_t size()
		{
			return _finish - _start;
		}
		
		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		T& operator[](size_t n)
		{
			assert(n < size());

			return _start[n];
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, old_size* sizeof(T));
				delete[] _start;

				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}


		void push_back(const T& val)
		{
			//ÅÐ¶Ï¿Õ¼äÊÇ·ñ³ä×ã
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			(*_finish) = val;
			_finish++;
		}

		T& insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator it = pos;
			iterator end = _finish;
			while (it < end)
			{
				*(end) = *(end - 1);
				end--;
			}
			*(pos) = val;
			_finish++;

			return _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	template<class T>
	void print_vector(const vector<T>& v)
	{
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;


		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void vector_test02();

}
