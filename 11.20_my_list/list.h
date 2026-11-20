#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

namespace hhy
{

	//节点类
	template<class T>
	struct list_node
	{
		list_node<T>(const T& x = T())
			:_date(x)
			,_prev(nullptr)
			,_next(nullptr)
		{ }

		T _date;
		list_node<T>* _prev;
		list_node<T>* _next;

	};


	//迭代器类
	template<class T>
	struct list_iterator
	{
		typedef list_iterator<T> Self;
		typedef list_node<T> Node;

		list_iterator<T>(Node* node)
			:_node(node)
		{ }


		T& operator*()
		{
			return _node->_date;
		}

		//前置++
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//后置++
		Self& operator++(int)
		{
			_node = _node->_next;
			return *this;
		}

		//前置--
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//后置--
		Self& operator--(int)
		{
			_node = _node->_prev;
			return *this;
		}



		bool operator!=(const Self& it)const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)const
		{
			return _node == it._node;
		}


		Node* _node;
	};


	//list类
	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T> iterator;

		list()
		{
			_head = new Node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		//不可以使用传引用返回，因为_head->_next会生成一个临时变量，返回引用后，临时变量被销毁，无法找到

		//iterator& begin()
		//{
		//	return iterator(_head->_next);
		//}

		//iterator& end()
		//{
		//	return iterator(_head);
		//}


		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}



		void push_back(const T& x)
		{
			Node* new_node = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = new_node;
			new_node->_prev = tail;
			new_node->_next = _head;
			_head->_prev = new_node;
			Size++;
		}


		void insert(iterator pos, const T& x)
		{
			Node* new_node = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = new_node;
			new_node->_prev = prev;

			new_node->_next = cur;
			cur->_prev = new_node;
			Size++;
			
		}


		void pop_back()
		{
			assert(!empty());

			Node* prev = _head->_prev->_prev;

			delete _head->_prev;

			prev->_next = _head;
			_head->_prev = prev;
			Size--;
		}

		void erase(iterator pos)
		{
			assert(!empty());
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;

			prev->_next = next;
			next->_prev = prev;
			Size--;


		}


		size_t size()const
		{
			return Size;
		}

		bool empty()const
		{
			//不能拿这个条件进行判断，因为如果链表中只有一个元素，这个条件也会满足
			//return _head->_prev == _head->_next;


			return Size == 0;
			//或者return _head->prev == _head;
		}


	private:
		Node* _head;
		size_t Size;
	};


	void list_test01();
}
