#pragma once

#include <iostream>
using namespace std;

namespace hhy
{

	struct AA
	{
		int a = 1;
		int b = 2;
	};

	template<class container>
	void print_container(const container& con)
	{
		typename container::const_iterator it = con.begin();
		//while (it != con.end())
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;
		for (auto e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	

	template<class T>
	struct list_node
	{

		list_node(const T& x = T())
			:_date(x)
			,_prev(nullptr)
			,_next(nullptr)
		{}

		T _date;
		list_node<T>* _prev;
		list_node<T>* _next;
	};


	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;

		list_iterator<T>(Node* node)
			:_node(node)
		{
		}

		T& operator*()
		{
			return _node->_date;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		T* operator->()
		{
			return &(_node->_date);
		}

		//注意const修饰，否则无法接受
		bool operator!=(const list_iterator<T> it)
		{
			return _node != it._node;
		}

		Node* _node;
	};

	template<class T>
	struct list_const_iterator
	{

		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;

		list_const_iterator<T>(Node* node)
			:_node(node)
		{
		}

		const T& operator*()
		{
			return _node->_date;
		}

		const Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//注意const修饰，否则无法接受
		bool operator!=(const list_const_iterator<T> it)
		{
			return _node != it._node;
		}

		Node* _node;
	};


	template<class T>
	class list
	{

	public:
		typedef list_node<T> Node;
		typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;

		list()
		{
			_head = new Node(T());
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin()const 
		{
			return _head->_next;
		}

		const_iterator end()const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node(T());
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}


		//拷贝构造
		list(const list<T>& lt)
		{
			//空初始化，因为这时候还没有哨兵位
			empty_init();
			const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}
		}

		//l2 = l1
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}


		void push_back(const T& x)
		{
			Node* new_node = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = new_node;
			new_node->_prev = tail;
			new_node->_next = _head;
			_head->_prev = new_node;
			_size++;
		}


	private:
		Node* _head;
		size_t _size;
	};

	void list_test1();
	void list_test2();
}
