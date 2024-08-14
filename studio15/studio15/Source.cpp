#include "Header.h"
#include <iostream>

using namespace std;

detector::detector() : x(y) // a public default constructor; int x initialized = y = 0
{
	++y; // everytime a new detector is constructed, x will increase by 1 through x(y)
	cout << "detector() " << this << " x = " << x << endl;
}

detector::~detector()
{
	cout << "~detector() " << this << " x = " << x << endl;
	--y;
}

unsigned int detector::y = 0; // private unsigned integer member variable that is static and is initialized to 0

// Define a wrapper class

// default constructor
wrapper::wrapper() : p_d(0), b_m_v(true) { 
	p_d = new detector; // deep copy here
	cout << "wrapper()" << this << " p_d = " << p_d << endl;
}

// destructor
wrapper::~wrapper() { 
	cout << "~wrapper()" << this << " p_d = " << p_d << endl;

	//if (b_m_v == true) {
	//	delete p_d;
	//}
	delete p_d;
}

// Copy constructor
wrapper::wrapper(const wrapper& p) : b_m_v(false), p_d(p.p_d) { 
	cout << "Begin Copy constructor" << endl;
	cout << "Num Detector (copy) = " << p_d->y << endl;

	p_d = new detector; // deep copy here

	cout << "wrapper()" << this << " p_d = " << p_d << endl;
	cout << "Num Detector (copy)= " << p_d->y << endl;
	cout << "End Copy constructor" << endl;
}

// Copy-Assignment operator=
wrapper& wrapper::operator= (const wrapper& p) {
	cout << "Begin Copy-Assignment operator" << endl;
	cout << "Num Detector = " << p_d->y << endl;

	if (&p != this) { // test for self-assignment
		wrapper temp(p); // similar to wrapper temp = p; copy constructor (defined above) makes deep copy of p
		swap(temp.p_d, p_d); // Swap Trick for Copy-Assignment
	}

	cout << "Num Detector = " << p_d->y << endl;
	cout << "End Copy-Assignment operator" << endl;
	return *this; // temp destroyed
}

// Move constructor: A lot like shallow copy constructor’s implementation; move from one to another
wrapper::wrapper(wrapper&& p): p_d(p.p_d), b_m_v(false) { 
	cout << "Begin Move constructor" << endl;
	cout << "Num Detector = " << p_d->y << endl;

	p.p_d = 0; // Except, zeroes out state of p; original object p is now safe to destroy 

	cout << "Num Detector = " << p_d->y << endl;
	cout << "End Move constructor" << endl;
}

// Move-Assignment operator
 wrapper& wrapper::operator= (wrapper&& p) { // r-value reference
	 cout << "Begin Move-Assignment operator" << endl;
	 cout << "Num detectors = "<< p_d->y << endl;

	 if (&p != this) { // test for self-assignment
		 delete p_d; // Simply free existing implementation

		 p_d = p.p_d; // Then copy over p_d value from p
		 p.p_d = 0; // Then zero out p_d in p

	 }

	 cout << "Num detectors = " << p_d->y << endl;
	 cout << "End Move-Assignment operator" << endl;
	 return *this;

 }