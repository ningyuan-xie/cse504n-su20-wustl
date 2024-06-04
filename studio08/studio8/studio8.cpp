// studio8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;

Name::Name() // default constructor
	: x(0), y(0){
	cout << "default constructor memory address: " << this << "; x: " << x << ", y: " << y << endl;
}

Name::Name(const Name& name) // copy constructor
	: x(name.x), y(name.y){
	cout << "copy constructor memory address: " << this << "; x: " << x << ", y: " << y << endl;
}

Name byValue(Name name) { // creates a copy of name; and returns that copy
	return name;
}

Name& byReference(Name& name) { // does not create a copy of name, but operates directly on the original "Name"
	return name;				// both the input and the output is a reference to "Name"
}

int Name::getX() const { // accessor x
	return x;
}

int Name::getY() const { // accessor y
	return y;
}

Name& Name::setX(int a) { // setter x
	x = a;
	return *this;
}

Name& Name::setY(int a) { // setter y
	y = a;
	return *this;
}

int main()
{
	Name name; // default construction
	const Name name2; // default construction
	cout << "x: " << name.getX() << " y: " << name.getY() << endl;
	cout << "const x: " << name2.getX() << " const y: " << name2.getY() << endl;
	cout << "-------------------------------------------------------------------" << endl;

	name.setX(10);
	name.setY(10);
	cout << "x: " << name.getX() << " y: " << name.getY() << endl;
	cout << "-------------------------------------------------------------------" << endl;
	
	// Cannot use setter on name2 as it is a const
	// name2.setX(10);
	// name2.setY(10);

	Name m; // default construction 
	cout << "m.x = " << m.getX() << " and m.y = " << m.getY() << endl;
	m.setX(7).setY(3); // chained use of mutator functions 
	cout << "m.x = " << m.getX() << " and m.y = " << m.getY() << endl;
	Name n(m); // copy construction 
	cout << "n.x = " << n.getX() << " and n.y = " << n.getY() << endl;
	cout << "-------------------------------------------------------------------" << endl;

	cout << "byValue: " << endl;
	byValue(name); // "byValue()" creates a copy of name; and returns that copy
				   // Therefore, the copy constructor is called twice (once for input and once for output), generating two addresses!
	
	cout << "byReference: " << endl; 
	byReference(name); // "byRef()" does not create a copy of name, but operates directly on the original object			 
					   // Therefore, the copy constructor is not called at all, and does not generate address!
	cout << "-------------------------------------------------------------------" << endl;
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
