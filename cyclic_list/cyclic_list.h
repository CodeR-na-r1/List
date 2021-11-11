#pragma once
#include <iostream>

using namespace std;

template <typename T>
class cyclic_list
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

	cyclic_list(cyclic_list& l);
	cyclic_list& operator =(const cyclic_list& l);

public:
	struct iterator
	{
		friend class cyclic_list;

		iterator()
		{
			it = nullptr;
		}

		T& operator *()
		{
			return this->it->data;
		}

		iterator shift(cyclic_list& l, int num)
		{
			iterator res = (*this);
			for (int i = 0; i < num; i++)
			{
				if (!res.it)
					throw "out range iterator!";

				if (res.it->next == nullptr)
					res.it = l.get_start();
				else
					res.it = res.it->next;
			}
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

	cyclic_list()
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
		if (ptr.it)
		{
			Node* temp = (ptr.shift(*this, 1)).it;
			ptr.it->next = (ptr.shift(*this, 2)).it;
			if (temp==this->head)
				this->head = ptr.it->next;
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

		this->size = 0;

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

	friend ostream& operator <<(ostream& out, cyclic_list<T>& l)
	{
		if (l.get_size() == 0)
			out << "List is empty!" << endl;

		int size = 0;
		for (cyclic_list<T>::iterator it = l.begin(); it != l.end();)
		{
			out << *it << ' ';
			++size;
			if (size >= l.get_size())
				break;
			it = it.shift(l, 1);
		}
		out << endl;

		return out;
	}

	~cyclic_list()
	{
		while (this->head != nullptr)
		{
			this->pop_front();
		}

		return;
	}
};