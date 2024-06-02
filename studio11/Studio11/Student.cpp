#include <string>
#include <iostream>
#include "student.h"

student::student() {} // default constructor

student::student(string name, unsigned int id) // constructor
	: name(name), id(id) {
	cout << "made a new student named " << name << " and id number " << id << endl;
}

ostream& operator<<(ostream& o, student& s) { // overload the extraction operator<<
	o << s.name << " " << s.id;
	return o;
}

bool student::operator< (student other) { // overload the less-than operator<
	return name < other.name;
}

istream& operator>>(istream& i, student& s) { // overload the insertion operator>>
	i >> s.name;
	i >> s.id;
	return i;
}

