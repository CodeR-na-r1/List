#pragma once
#include <iostream>

using namespace std;

template <typename T>
class list
{
	class Node
	{
	public:
		T data;
		Node* next;

		Node(const T& adata, Node* anext)
		{
			this->data = adata;
			this->next = anext;
		}

		const T& get_data() const
		{
			return this->data;
		}

		Node* get_next()
		{
			return this->next;
		}

		~Node()
		{
			data.~T();
			next = nullptr;
		}
	};

	long long int size;
	Node* head;

	list(list& l);
	list& operator =(const list& l);

public:
	struct iterator
	{
		friend class list;

		iterator()
		{
			it = nullptr;
		}

		iterator& operator++()
		{
			if (!this->it)
				throw "out range iterator!";
			this->it = this->it->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator res;
			res.it = this->it;
			++(*this);
			return res;
		}

		T& operator *()
		{
			return this->it->data;
		}

		iterator& operator +=(int num)
		{
			for (int i = 0; i < num; i++)
			{
				this->it = this->it->next;
				if (!this->it)
					throw "out range iterator!";
			}
			return *this;
		}

		iterator operator +(int num)
		{
			iterator res = this->it;
			res += num;
			return res;
		}

		bool operator ==(iterator it_other)
		{
			return this->it == it_other.it;
		}

		bool operator !=(iterator it_other)
		{
			return this->it != it_other.it;
		}

	private:
		Node* it;
	};

	list()
	{
		this->size = 0;
		this->head = nullptr;
	}

	Node* get_start()
	{
		return this->head;
	}

	long long int get_size()
	{
		return this->size;
	}

	void pop_front()
	{
		if (this->head)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			temp->~Node();
			--this->size;
		}
		else
			throw "List is empty!";

		return;
	}

	void pop_after(iterator& ptr)
	{
		if (ptr.it && ptr.it->next)
		{
			Node* temp = ptr.it->get_next();
			ptr.it->next = ptr.it->next->next;
			delete temp;
			--this->size;
		}
		else
			throw "Agrument is nullptr";
		return;
	}

	void push_front(const T& d)
	{
		Node* temp = this->head;
		this->head = new Node(d, temp);
		++this->size;
		return;
	}

	void push_after(iterator& ptr, const T& d)
	{
		if (ptr.it)
		{
			ptr.it->next = new Node(d, ptr.it->get_next());
			++this->size;
		}
		else { throw "error iterator!"; }
		
		return;
	}

	void clear()
	{
		while (this->head)
		{
			this->pop_front();
		}

		--this->size;

		return;
	}

	iterator begin()
	{
		iterator res;
		res.it = this->head;
		return res;
	}

	iterator end()
	{
		iterator res;
		res.it = nullptr;
		return res;
	}

	friend ostream& operator <<(ostream& out, list<T>& l)
	{
		if (l.get_size() == 0)
			out << "List is empty!" << endl;

		for (list<T>::iterator it = l.begin(); it != l.end(); ++it)
		{
			out << *it << ' ';
		}
		out << endl;

		return out;
	}

	~list()
	{
		while (this->head != nullptr)
		{
			this->pop_front();
		}

		return;
	}
};