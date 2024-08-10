#include "Header.h"
#include <iostream>
using namespace std;

void test(A j) {
	j.method();
}

int main()
{	
	// 1. Construct objects
	cout << endl << "1. Constructing objects: " << endl;
	A a; // A was constructed
	B b; // A was constructed; B was constructed
	cout << "done " << endl;

	// 2. Construct pointers
	cout << endl << "2. Constructing pointers: " << endl;
	A* AptrA = new A();	// A was constructed
	A* AptrB = new B(); // Dynamic: A was constructed; B was constructed (static: A; dynamic: B)
	B* BptrB = new B(); // A was constructed; B was constructed
	cout << "done " << endl;

	cout << endl << "3. Testing pointers overriding: " << endl;
	cout << "A pointer to A:" << endl;
	(*AptrA).method(); // A's method was called; (*AptrA).method() = AptrA->method()
	cout << "A pointer to B:" << endl;
	AptrB->method(); // Dynamic + Overriding: B's method was called (static: A; dynamic: B)
	cout << "B pointer to B:" << endl;
	BptrB->method(); // Dynamic + Overriding: B's method was called
	cout << "done " << endl;

	cout << endl << "4. Testing pointers deletion: " << endl;
	cout << "deleting AA: " << endl;
	delete AptrA; // A was destroyed
	cout << "deleting AB: " << endl;
	delete AptrB; // Static: A was destroyed (static: A; dynamic: B)
	cout << "deleting BB: " << endl;
	delete BptrB; // B was destroyed; A was destroyed
	// This is because ~A() is the base class destructor
	// it is called after the derived class destructor ~B() finishes executing
	// even if ~A() is not virtual in this case!
	cout << "done " << endl;

	cout << endl << "5. Testing objects overriding: " << endl;
	cout << "A method:" << endl;
	a.method(); // A's method was called
	cout << "B method:" << endl;
	b.method(); // Dynamic + Overriding: B's method was called
	cout << "done " << endl;

	return 0;
}