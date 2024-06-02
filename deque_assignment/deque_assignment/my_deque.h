#pragma once
// declare your my_deque class here
#include "my_deque_iterator.h"

#include <iostream>
#include <string>
#include <map>

//class my_deque_iterator;

// Part I: Implement my_deque
class my_deque {

	friend class my_deque_iterator;

public:
	my_deque(size_t initial_size);		// a.
	my_deque(const my_deque& d);		// b.
	~my_deque();						// c.

	size_t get_used();					// d.
	size_t get_size();					// e.
	size_t get_lIndex();				// f.
	size_t get_rIndex();				// g.

	void push_back(int v);				// h.
	void push_front(int v);				// i.

	int pop_back();						// j.
	int pop_front();					// k.
	int* get_mem();						// l.
	int& operator[](const size_t& i);	// m.


	// Part II: Implement my_deque_iterator
	// Adding begin() and end() to my_deque:
	my_deque_iterator begin();			// a.
	my_deque_iterator end();			// b.


private:
	int* array;
	int size;
	size_t lIndex;
	size_t rIndex;

	size_t used = 0;		// initially, no element in the array
	size_t initial_size;	// used to record whether to shrink or not
};