#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{

	LinkedList<int> l;
	l.add(11);
	l.add(5);
	l.add(-1);
	l.add(6);
	l.add(2);

	cout << "Original List:" << l;
	l.mergeSort();
	cout << "\nList after sort:" << l;
	

	cin.ignore();
	cin.get();
	return 0;
}