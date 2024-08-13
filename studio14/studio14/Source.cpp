#include "Header.h"
#include <iostream>

using namespace std;

// 2. Define a detector class
detector::detector() : x(y) // a public default constructor; int x initialized = y = 0
{ 
	++y; // everytime a new detector is constructed, x will increase by 1 through x(y)
	cout << "detector() " << this << " x = " << x << endl;

}

detector::~detector() // a destructor
{
	cout << "~detector() " << this << " x = " << x << endl;

}

unsigned int detector::y = 0; // private unsigned integer member variable that is static and is initialized to 0

// 3. Define a wrapper class
// 3.1 Default constructor with deep copy version
wrapper::wrapper() : p_d(0), b_m_v(true) {
	p_d = new detector; // deep copy here; p_d is a pointer to a new detector object
	cout << "wrapper() " << this << " p_d = " << p_d << endl;
}

wrapper::~wrapper() { // destructor
	cout << "~wrapper() " << this << " p_d = " << p_d << endl;
	
	//if (b_m_v == true) {
	//	delete p_d;
	//}
	delete p_d;
}

// 3.2 Copy constructor with deep copy version
wrapper::wrapper(const wrapper& p) : b_m_v(false), p_d(p.p_d) { // copy constructor with deep copy
	
	p_d = new detector; // deep copy here; p_d is a pointer to a new detector object

	cout << "wrapper() " << this << " p_d = " << p_d << endl;
}
