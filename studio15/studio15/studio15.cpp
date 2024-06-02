// studio15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
	cout << "This is begining of main" << endl;

	// 2. Initializing l value and r value
	// two variables of type int that are initialized with different integer values
	cout << endl << "2. Initializing l value and r value: " << endl;
	int a = 5;
	int b = 10;

	// two variables that are l-value references to type int 
	int& l_value = a;
	int& l_value2 = b;

	// two variables that are r-value references to type int
	int&& r_value = 15;
	int&& r_value2 = 20;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "l_value = " << l_value << endl;
	cout << "l_value2 = " << l_value2 << endl;

	cout << "r_value = " << r_value << endl;
	cout << "r_value2 = " << r_value2 << endl;
	
	// 3. Use the std::move function to initialize r-value references
	cout << endl << "3.1 Using the std::move function to initialize r-value references: " << endl;
	int&& r_value3 = move(a);
	int&& r_value4 = move(b);

	cout << "After move(a), r_value3 = " << r_value3 << endl;
	cout << "After move(b), r_value4 = " << r_value4 << endl;

	cout << endl << "3.2 Using the std::move function to assign r-value: " << endl;
	r_value = move(b);
	r_value2 = move(l_value);

	cout << "After move(b), r_value = " << r_value << endl;
	cout << "After move(l_value), r_value2 = " << r_value2 << endl;

	l_value = b;
	r_value = l_value;
	cout << "l_value now = " << l_value << endl;
	cout << "After assigning r_value = l_value, r_value = " << r_value << endl;

	cout << endl << "4. The detector and wrappers classes: " << endl;

	// 4. Test wrapper's different constructors and assignment operator=
	cout << endl << "Test wrapper's different constructors and assignment operator=: " << endl;

	cout << endl << "4.1 Construct wrapper w using default constructor: " << endl;
	wrapper w1;

	cout << endl << "4.2 Construct wrapper w2 using Copy constructor=: " << endl;
	wrapper w2(w1);
	
	cout << endl << "4.3 Construct wrapper w3 using Copy-Assignment operator=: " << endl;
	wrapper w3;
	w3 = w1;

	cout << endl << "4.4 Construct wrapper w4 using Move constructor: " << endl;
	wrapper w4 = move(w1); // after move, w1 is zero-out and now safe to destroy  

	cout << endl << "4.5 Construct wrapper w5 using Move-Assignment operator=: " << endl;
	wrapper w5;
	w5 = move(w2);

	cout << endl << "This is ending of main" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
