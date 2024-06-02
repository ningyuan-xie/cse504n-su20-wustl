#pragma once
#include <string>
#include <iostream>

using namespace std;

class A {
public:
	A();
	
	// Case 1: ~A is not virtual.
	// Since the destructor of A is not virtual, when delete is called on ap, only the destructor of the static type (A) will be called. 
	// This is the behavior even though the dynamic type of the object is B. 
	// As a result, only the destructor of A (~A()) will be called, not the destructor of B.
	~A();

	// Case 2: ~A is virtual, so the destructor of the dynamic type (B) will be called. 
	// When delete is called on ap, the C++ runtime knows that ap points to an object of type B (the dynamic type), but the pointer type is A* (the static type).
	// Since ~A() is declared as virtual in class A, the C++ runtime ensures that the destructor of the dynamic type (B) is invoked first.
	// After the destructor of B (~B) finishes executing, the execution returns to the point where ~A() was called.
	//virtual ~A(); 
	virtual void method();

};


class B : public A {
public:
	B();
	virtual ~B();
	virtual void method(); // overriding
};

