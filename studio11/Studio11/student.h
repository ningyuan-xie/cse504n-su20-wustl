#pragma once
#include <string>
#include <iostream>

using namespace std;

class student { 
public: // member functions and variables
	student(); // default constructor
	student(string, unsigned int); // constructor
	string name;
	unsigned int id;
	bool operator<(student); // overload the operator<

};

ostream& operator<<(ostream&, student&); // overload the extraction operator<<
istream& operator>>(istream&, student&); // overload the insertion operator>>