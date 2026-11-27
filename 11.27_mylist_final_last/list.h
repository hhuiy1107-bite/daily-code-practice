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
			, _prev(nullptr)
			, _next(nullptr)
		{
		}

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

		list_iterator<T>( Node* node)//内置类型，不需要传引用
			:_node(node)
		{ }

		T& operator*()const
		{
			return _node->_date;
		}

		//前置++
		Self& operator++()
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


	template<class T>
	struct list_const_iterator
	{
		//注意区分const iterator 和 const_iterator 的区别 我们想要限制的是指向内容不被改变，而不是指向对象
		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;

		list_const_iterator<T>(Node* node)//思考是否可以写成 Node* const& node?
			:_node(node)
		{ }

		const T& operator*()const//后面可再加const，因为函数体内不改变任何指向，只获取内容
		{
			return _node->_date;
		}

		const Self& operator++()//后面切不可再加const，因为传入参数已经是被const类型
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


	//list类
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
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		//空初始化，创建头节点
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

		//赋值重载
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

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
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


		void insert(iterator pos, const T& x)
		{
			Node* new_node = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = new_node;
			new_node->_prev = prev;

			new_node->_next = cur;
			cur->_prev = new_node;
			_size++;

		}
		bool empty()const
		{
			//不能拿这个条件进行判断，因为如果链表中只有一个元素，这个条件也会满足
			//return _head->_prev == _head->_next;


			return size == 0;
			//或者return _head->prev == _head;
		}

		void pop_back()
		{
			assert(!empty());

			Node* prev = _head->_prev->_prev;

			delete _head->_prev;

			prev->_next = _head;
			_head->_prev = prev;
			_size--;
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
			_size--;


		}


		size_t size()const
		{
			return _size;
		}


	private:
		Node* _head;
		size_t _size;
	};

	template<class container>
	void print_container(const container& con)
	{
		//typename const_iterator it = con.begin();

		auto it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	


		for (auto& e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void list_test01();//增删测试
	void list_test02();//拷贝 赋值 析构测试
	void list_test02();//迭代器测试
}

