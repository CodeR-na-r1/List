#include <iostream>
#include "cyclic_list.h"

using namespace std;

int main()
{
	// Joseph flavius
	
	// step - what kind of person are we killing. # If the step is 2, then we kill every second. (but we skip 1 person)

	cyclic_list<int> cl;
	
	int size, step;

	cout << "Enter number of people: " << endl;
enter_size:
	cin >> size;
	if (cin.fail() || size < 1)
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << "error input! Try again: " << endl;
		goto enter_size;
	}

	cout << "Enter step (how many people are skip) : " << endl;
enter_step:
	cin >> step;
	if (cin.fail() || step < 0)
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << "error input! Try again: " << endl;
		goto enter_step;
	}

	if (step == 1|| step == 0)
	{
		cout << endl << "Answer: " << size;
		return 0;
	}


	int count = size;
	while (cl.get_size() != size)
	{
		cl.push_front(count);
		--count;
	}

	--step;
	cyclic_list<int>::iterator it = cl.begin();
	count = 1;
	while (cl.get_size() != 1)
	{
		if (count == step)
		{
			cl.pop_after(it);
;			count = 0;
		}
		
		it = it.shift(cl, 1);
		++count;
	}
	
	cout << "Answer: " << cl << endl;

	cl.clear();
	
	return 0;
}