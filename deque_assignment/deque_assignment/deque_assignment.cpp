// deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <deque>

#include "my_deque.h"
#include "my_deque_iterator.h"

using namespace std;

int main()
{    

	// Deep vs. Shallow copy
	deque<int> d_1 = { 1, 0, 2, 5 };
	cout << "Address of d_1 is " << &d_1 << "; " << endl ;

	deque<int> d_2 = d_1;
	cout << "Address of d_2 is " << &d_2 << ". " << endl;
	
}
