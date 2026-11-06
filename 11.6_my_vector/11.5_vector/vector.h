#pragma once

#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

namespace hhy
{
	template <class T>
	class vector
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;


		//强制生成默认构造函数
		//vector() = default;


		size_t size() const
		{
			return _finish - _start;
		}


		
		size_t capacity() const
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
		
		void swap(vector<T>& it)
		{
			std::swap(_start, it._start);
			std::swap(_finish, it._finish);
			std::swap(_end_of_storage, it._end_of_storage);
		}

		//全缺省构造函数
		vector(size_t n = 0,  const T& val = T())//这里为什么要加const呢？因为如果不传入实参，那么会生成一个匿名的临时对象，，临时对象返回值具有右值属性      vector(size_t n = 0, T val = T())  或者直接传值
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//迭代器区间构造
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//拷贝构造函数（利用现成接口）
		vector(const vector<T>& v)
		{
			//提前开好空间，防止频繁扩容
			reserve(v.capacity());//注意这里传入的v是const引用的，所以v.capacity() 中capacity函数参数必须也是const，否则将造成权限放大问题
			for (auto e : v)
			{
				push_back(e);
			}
		}



		//赋值重载（现代写法）
		vector<T>& operator=( vector<T> v)
		{
			swap(v);
			return *this;
		}



		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}



		void resize(size_t n ,T val = T())
		{

			if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);
				}
				iterator it = _finish;
				//注意这里循环条件，维持左闭右开，不能<=
				while (_finish < _start + n)
				{
					*(_finish) = val;
					_finish++;
				}
			}

			if (n < size())
			{
				//删除数据个数到n
				size_t len = size() - n;

				for (size_t i = 0; i < len; i++)
				{
					pop_back();
				}
			}
		}

		//void reserve(size_t n)
		//{
		//	if (n > capacity())
		//	{
		//		size_t old_size = size();
		//		T* tmp = new T[n];
		//		memecpy对于存在指针的成员浅拷贝，导致this和tmp指向同一块空间
		//		memcpy(tmp, _start, old_size* sizeof(T));

		//		delete[] _start;

		//		_start = tmp;
		//		_finish = _start + old_size;
		//		_end_of_storage = _start + n;
		//	}
		//}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				for (size_t i = 0; i < size(); i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}


		void push_back(const T& val)
		{
			//判断空间是否充足
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			(*_finish) = val;
			_finish++;
		}

		bool empty()
		{
			return _start == _finish;
		}

		void pop_back()
		{
			if (!empty())
			{
				_finish--;
			}
		}

		void insert(iterator pos, const T& val)
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
			
		}


		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			/*if (!empty())
			{	
				iterator it = pos;
				iterator end = _finish;
				while (it < end)
				{
					*it = *(it + 1);
					it++;
				}
				_finish--;
			}*/

				iterator it = pos;
				iterator end = _finish - 1;//向前挪一位，防止越界访问
				while (it < end)
				{
					*it = *(it + 1);
					it++;
				}
				_finish--;
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
		//while (it != v.end())
		//{
		//	cout << *it << " ";
		//	it++;
		//}
		//cout << endl;


		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void vector_test02();

	void vector_tets03();

	void vector_test04();

	void vector_test05();

	void vector_test06();


}
