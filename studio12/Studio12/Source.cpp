#include "Header.h"
#include <iostream>
using namespace std;

A::A(){
	cout << "A was constructed" << endl;
}

A::~A() {
	cout << "A was destroyed" << endl;
}

B::B() {
	cout << "B was constructed" << endl;
}

B::~B() {
	cout << "B was destroyed" << endl;
}

void A::method() {
	cout << "A's method was called" << endl;
}

void B::method() { // overriding
	cout << "B's method was called" << endl;
}