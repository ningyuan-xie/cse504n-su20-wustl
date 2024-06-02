#pragma once
// declare my_deque_iterator here

//#include "my_deque.h"

#include <iostream>
#include <string>
#include <map>

class my_deque;

// Part II: Implement my_deque_iterator

class my_deque_iterator {

public:

	// Implementation details:
	my_deque_iterator(int*, my_deque*);								// a.
	my_deque_iterator operator+ (int n);							// b.
	my_deque_iterator& operator+= (int n);							// c.
	int& operator* ();												// d.
	bool operator< (const my_deque_iterator compare_against) const; // e.
	bool operator== (const my_deque_iterator) const;				// f.
	int* get_mem();													// g.

private:
	int* curr;						// address of the integer it is currently referring
	my_deque* address_of_my_deque;  // address of the my deque object the iterator is currently iterating over

};