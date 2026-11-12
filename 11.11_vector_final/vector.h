#pragma once

#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
namespace hhy
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;


		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_stroage = nullptr;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_stroage - _start;
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

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				//memcpy(tmp, _start, size() * sizeof(T));

				for (size_t i = 0; i < old_size; i++)
					tmp[i] = _start[i];
				{
				}
				
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_stroage = tmp + n;
			}
		}

		void push_back(const T& v)
		{
			if (_finish == _end_of_stroage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*(_finish) = v;
			_finish++;
		}

		iterator insert(iterator pos, const T& v)
		{

			size_t n = pos - _start;
			if (_finish == _end_of_stroage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			//iterator end = _finish;
			//while (pos < end)
			//{
			//	*(end) = *(end - 1);
			//	end--;
			//}
			//*pos = v;
			//_finish++;


			iterator end = _finish - 1;
			//迭代器失效问题，扩容后_start改变，故与pos的相对位置也改变
			pos = _start + n;
				while (pos <= end)
				{
					*(end + 1) = *end;
					end--;
				}
				*pos = v;

			_finish++;

			return pos;
		}

		bool Empty()
		{
			return size() == 0;
		}

		void pop_back()
		{
			assert(!Empty());

			_finish--;
		}


		void erase(iterator pos, size_t len)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			size_t remain = _finish - pos;
			if (remain < len)
			{
				len = remain;
			}

			iterator end = pos + len;
			while (end != _finish)
			{
				*pos = *end;
				pos++;
				end++;
			}

			_finish -= len;
		}


		T& operator[](size_t pos)
		{
			assert(pos >= size());
			assert(pos < end());
			return _start[pos];
		}

		
		void resize(size_t n, T v = T())
		{
			if (n > size())
			{
				//不管多不多都reserve,函数内部会自己判断是否扩容
					reserve(n);
					iterator it = end();
					iterator finish = _start + n;
					while (it != finish)
					{
						*it = v;
						it++;
					}
					_finish += finish - _finish;
			}
			else//不缩容到，但是数据减少到n
			{
				_finish = _start + n;
			}
		}



	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_stroage = nullptr;
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
	}


	void vector_test01();

	void vector_test02();

	void vector_test03();

}