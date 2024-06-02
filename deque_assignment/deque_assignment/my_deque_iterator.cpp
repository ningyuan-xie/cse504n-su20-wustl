// define my_deque_iterator here
#include "my_deque_iterator.h"
#include "my_deque.h"

#include <iostream>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Part II: Implement my_deque_iterator

// a. my_deque_iterator(int*, my_deque*)
my_deque_iterator::my_deque_iterator(int* i, my_deque* md)
	// initialize "curr" and "deque" with the parameters accordingly
	: curr(i), address_of_my_deque(md) {
	
	// Case 1: Invalid, when "curr" does not point to an element in the deque

	// check if "curr" points to an element in the deque
	int count = 0;
	for (size_t t = md->lIndex + 1; t < md->rIndex; ++t) {
		if (i == &md->array[t]) {
			count += 1;
		}
	}
	if (count == 0) {
		
		this->curr = nullptr;
	}

	// Case 2: Past the end, when "curr" points to rIndex
	
	// check if "curr" points to the last element in the deque
	if (i == &md->array[md->rIndex]) {
		
		this->curr = &md->array[md->rIndex];
	}

}


// b. my_deque_iterator operator+ (int n)
my_deque_iterator my_deque_iterator::operator+ (int n) {

	if (n >= 0) {

		return my_deque_iterator(this->curr + n, this->address_of_my_deque);

	}

	// if n is negative
	else {

		// an invalid my_deque_iterator should be returned
		return my_deque_iterator(nullptr, this->address_of_my_deque);
	}
}	


// c. my_deque_iterator& operator+= (int n)
my_deque_iterator& my_deque_iterator::operator+= (int n) {

	if (n >= 0) {

		// update the my_deque_iterator to be advanced by n integers in the deque
		*this = my_deque_iterator(this->curr + n, this->address_of_my_deque);
	}

	// if n is negative
	else {

		// an invalid my_deque_iterator should be returned
		*this = my_deque_iterator(nullptr, this->address_of_my_deque);
	}

	return *this;
}


// d. int& operator* ()
int& my_deque_iterator::operator* () {

	// Case 1: Invalid, when "curr" points to nullptr
	if (this->curr == nullptr) {

		// throw an exception of type std::exception
		throw exception("Iterator is invalid.");
	}

	// Case 2: Past the end, when "curr" points to rIndex
	size_t rIndex_iterator = this->address_of_my_deque->rIndex;

	// ensure both sides of the comparison are ADDRESS: 
	// this->curr shows the ADDRESS of the value that curr points to
	// &this->address_of_my_deque->array[rIndex_iterator] shows the ADDRESS of array[rIndex_iterator]
	if (this->curr == &this->address_of_my_deque->array[rIndex_iterator]) {

		// throw an exception of type std::exception
		throw exception("Iterator past the end.");
	}

	// dereference: *curr = value pointed by curr, not address
	// return a "reference to the integer" int& that my_deque_iterator is currently aliasing using *curr
	return *curr;
	// It is also possible to write "int my_deque_iterator::operator* ()" as interface because *p is an int
}


// e. bool operator< (const my_deque_iterator compare_against) const
bool my_deque_iterator::operator< (const my_deque_iterator compare_against ) const {

	// Case 2: Past the end, when "curr" points to rIndex
	size_t rIndex_iterator = this->address_of_my_deque->rIndex;

	// if either my_deque_iterator this function acts on is in an invalid state, or if they are not iterating over the same deque
	if (this->curr == nullptr || this->address_of_my_deque != compare_against.address_of_my_deque) {
		
		// throw an exception of type std::exception
		throw exception("Either the iterator is in an invalid state, or they are not iterating over the same deque.");
	}

	else {

		// Comparing address: if “this” is aliasing an integer that comes before the integer aliased by “compare_against” int the deque
		if (this->curr < compare_against.curr) {

			// return true
			return true;
		}
		else {

			// return false otherwise
			return false;
		}
	}
}


// f. operator== (const my_deque_iterator) const
bool my_deque_iterator::operator== (const my_deque_iterator mdi) const {

	// if both the my_deque_iterator iterate over the same deque object, and are aliasing the same integer element
	if (this->address_of_my_deque == mdi.address_of_my_deque && this->curr == mdi.curr) {
		
		// return true
		return true;
	}

	else {

		// return false otherwise
		return false;
	}

}


// g. int* get_mem()
int* my_deque_iterator::get_mem() {

	// return the memory address of the integer this iterator is currently aliasing
	return this->curr;
}

