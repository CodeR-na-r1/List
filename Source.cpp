#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	list<int> l;
	l.push_front(555);
	cout << l;

	list<int>::iterator i = l.begin();
	l.push_after(i, 444);
	cout << l;
	l.pop_after(i);
	cout << l;

	l.push_after(i, 444);
	cout << *i;
	i++;
	cout << *i;
	l.push_after(i,333);
	cout << l;

	i = l.begin();
	i += 2;
	l.push_after(i, 222);
	cout << l;

	i = l.begin();
	l.pop_front();
	cout << *i;
	try {
		for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		{
			l.pop_front();
			cout << l;
		}
	}
	catch (const char* ex) {
		cout << ex;
	}

	cout << *i;
	
	return 0;
}