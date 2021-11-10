#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	cout << "STEP 1: Createing list and add element (555)" << endl;
	list<int> l;
	l.push_front(555);
	cout << l;

	cout << "\nSTEP 2: Createing iterator and add element (444) with him help, then delete this element" << endl;
	list<int>::iterator i = l.begin();
	l.push_after(i, 444);
	cout << l;
	l.pop_after(i);
	cout << l;

	cout << "\nSTEP 3: Checking increment of iterator but begin add element (444) with him help" << endl;
	l.push_after(i, 444);
	cout << "first elem == " << *i << endl;
	i++;
	cout << "second elem == " << *i << endl;

	cout << "\nSTEP 4: Add element (333) after the iterator (iterator indicate on second element) " << endl;
	l.push_after(i,333);
	cout << l;

	cout << "\nSTEP 5: Checking operator * (get_data) of iterator" << endl;
	cout << *i << endl;

	cout << "\nSTEP 6: Checking operator += of iterator: add element (222) after element (333) (iterator indicate on first element and then iterator += 2 -> now iterator indicate on third element)" << endl;
	i = l.begin();
	i += 2;
	l.push_after(i, 222);
	cout << l;

	//i = l.begin();
	//l.pop_front();
	//*i = 123;
	//cout << *i;

	cout << "\nSTEP 7: Manual clear of the list:" << endl;

	try {
		list<int>::iterator it = l.begin();
		while (it!=l.end())
		{
			++it;
			l.pop_front();
		}
	}
	catch (const char* ex) {
		cout << ex;
	}

	cout << l;

	// Joseph flavius

	int size, step;
	cout << "Enter number of people: " << endl;
	cin >> size;
	cout << "Enter step (how many people are skip) : " << endl;
	cin >> step;

	int count = size;
	while (l.get_size() != size)
	{
		l.push_front(count);
		--count;
	}

	list<int>::iterator it = l.begin();
	count = 0;
	while (l.get_size() != 1)
	{
		++count;

		if (count == step)
		{
			(it + 1) == l.end() ? l.pop_front() : l.pop_after(it);
;			count = 0;
		}

		it = ((it+1) ==l.end()) ? l.begin() : it+1;
	}

	cout << "Answer: " << l << endl;

	l.clear();

	return 0;
}