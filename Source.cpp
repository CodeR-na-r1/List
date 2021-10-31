#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	list<int> l;
	l.push_front(555);
	l.pop_front();
	cout << l;
	
	return 0;
}