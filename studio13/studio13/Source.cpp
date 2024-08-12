#include "studio13.h"
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