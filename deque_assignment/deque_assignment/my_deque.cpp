// define my_deque here
#include "my_deque.h"

#include <iostream>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Part I: Implement my_deque

// a. my_deque (size_t initial_size) 
my_deque::my_deque(size_t initial_size) 
	: size(initial_size), lIndex(initial_size / 2 - 1), rIndex(initial_size / 2), initial_size(initial_size) {

	// Dynamically allocate an array of integers with size initial_size,
	// set the appropriate member variable to point to this array.
	this->array = new int[initial_size];
}


// b. my_deque(const my_deque& d)
my_deque::my_deque(const my_deque& d): size(d.size), lIndex(d.lIndex), rIndex(d.rIndex), array(nullptr), initial_size(d.initial_size), used(d.used) {
	
	// Define a copy constructor for my_deque class to make a deep copy
	array = new int[d.size];

	for (size_t i = 0; i < d.size; ++i) {
		array[i] = d.array[i];
	}
}

// c. ~my_deque()
my_deque::~my_deque() {

	// Define a destructor in an appropriate way, given that the copy constructor makes a deep copy
	delete this->array;
}

// d. size_t get_used()
size_t my_deque::get_used() {

	// return the number of elements currently in the deque
	return this->used;

}

// e. size_t get_size()
size_t my_deque::get_size() {

	// return the size of the array managed by the deque
	return this->size;

}

// f. size_t getlIndex()
size_t my_deque::get_lIndex() {

	// return lIndex
	return this->lIndex;

}

// g. size_t get_rIndex()
size_t my_deque::get_rIndex() {

	// return rIndex
	return this->rIndex;
}


// h. void push_back(int v)
void my_deque::push_back(int v) {

	// Case 1: resize (growing) and recenter the array if needed to make room for the element being pushed
	if (this->used > this->size/2 && this->rIndex == this->size) {

		// 1.1 resize (growing)
		int shift = this->size / 4; // 8 / 4 = 2
		this->size *= 2;			// 8 * 2 = 16

		// 1.2 a new array of twice the size was allocated
		int* array_after_push_back = new int[this->size];

		// 1.3 elements were copied and recentered to the new array
		for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
			array_after_push_back[i + shift] = this->array[i];
		}

		// 1.4 update member variable lIndex, rIndex, and array
		this->lIndex += shift;
		this->rIndex += shift;

		delete this->array;

		array_after_push_back[this->rIndex] = v;
		this->array = array_after_push_back;

		// update member variables as needed
		this->used += 1;
		this->rIndex += 1;
	}

	// Case 2: Only recenter the array to make room for the element being pushed
	else if (this->used <= this->size / 2 && this->rIndex == this->size) {

		// 2.1 define shift
		int shift = -(this->size / 2); // - (8 / 2) = - 4

		// 2.2 a new array with the same size was allocated
		int* array_after_push_back = new int[this->size];

		// 2.3 elements were copied and recentered to the new array

		// Special situation: there is no element in old array, update Index directly
		if (this->lIndex + 1 == this->rIndex) {
			this->lIndex += shift;
			this->rIndex += shift;
		}

		else {
			for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
				array_after_push_back[i + shift] = this->array[i];
			}

			// 2.4 update member variable lIndex, rIndex, and array
			this->lIndex += shift;
			this->rIndex += shift;
		}

		delete this->array;

		array_after_push_back[this->rIndex] = v;
		this->array = array_after_push_back;

		// update member variables as needed
		this->used += 1;
		this->rIndex += 1;
	}

	// Case 3. Simply add element at rIndex
	else {
		// add v to the end of the array maintained by the deque
		this->array[this->rIndex] = v;

		// update member variables as needed
		this->used += 1;
		this->rIndex += 1;
	}
}

// i. void push_front(int v)
void my_deque::push_front(int v) {

	// Case 1: resize (growing) and recenter the array if needed to make room for the element being pushed
	if (this->used > this->size / 2 && this->lIndex == -1) {

		// 1.1 resize (growing)
		int shift = this->size * 3 / 4; // 8 * 3/4 = 6
		this->size *= 2;				// 8 * 2 = 16

		// 1.2 a new array of twice the size was allocated
		int* array_after_push_front = new int[this->size];

		// 1.3 elements were copied and recentered to the new array
		for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
			array_after_push_front[i + shift] = this->array[i];
		}

		// 1.4 update member variable lIndex, rIndex, and array
		this->lIndex += shift;
		this->rIndex += shift;

		delete this->array;
		this->array = array_after_push_front;
	}

	// Case 2: Only recenter the array to make room for the element being pushed
	else if (this->used <= this->size / 2 && this->lIndex == -1) {
		
		// 2.1 define shift
		int shift = this->size / 2; // 8 / 2 = 4;
		int shift_for_lIndex = shift - 1;
		
		// 2.2 a new array with the same size was allocated
		int* array_after_push_front = new int[this->size];
		
		// 2.3 elements were copied and recentered to the new array
		
		// Special situation: there is no element in old array, update Index directly
		if (this->rIndex == 0) {
			this->lIndex = shift_for_lIndex;
			this->rIndex += shift;
		}

		else {
			for (size_t i = 0; i <= this->rIndex - 1; ++i) {
				array_after_push_front[i + shift] = this->array[i];
			}

			// 2.4 update member variable lIndex, rIndex, and array
			this->lIndex = shift_for_lIndex;
			this->rIndex += shift;
		}

		delete this->array;
		this->array = array_after_push_front;
	}

	// add v to the beginning of the array maintained by the deque
	this->array[this->lIndex] = v;

	// update member variables as needed
	this->used += 1;
	this->lIndex -= 1;
}


// j. pop_back() 
int my_deque::pop_back() {

	// remove 1 element from the back of the deque
	if (this->array[this->rIndex - 1] != -842150451) {
		// The value -842150451 (or 0xCDCDCDCD in hexadecimal) is commonly used in debugging and development environments 
		// to indicate uninitialized memory or a "debug fill" value in certain C++ environments, particularly when using Microsoft's development tools
		// When working with Microsoft's Visual C++ compiler, memory allocated but not yet initialized is often filled with 0xCDCDCDCD.

		int result = array[this->rIndex - 1]; // return a copy of the removed 1 element

		this->array[this->rIndex - 1] = -842150451;

		// update member variables as needed
		this->used -= 1;
		this->rIndex -= 1;

		// Case 1: resize the array if needed
		if (this->used < this->size / 8 && this->size > this->initial_size) {

			// 1.1 resize (shrinking)
			this->size /= 2;

			// 1.2 a new array of half the size was allocated
			int* array_after_pop_back_intermediate = new int[this->size];
			int* array_after_pop_back = new int[this->size];

			// 1.3 elements were copied and recentered to the new array
			int count = 0;
			for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
				array_after_pop_back_intermediate[i- (lIndex + 1)] = this->array[i];
				count += 1;
			}

			this->lIndex = -1;
			this->rIndex = count;

			int shift = this->size / 8 * 3; // 8 / 8 * 3 = 3
			
			for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
				array_after_pop_back[i + shift] = array_after_pop_back_intermediate[i];
			}

			// 1.4 update member variable lIndex, rIndex, and array
			this->lIndex += shift;
			this->rIndex += shift;

			delete this->array;
			this->array = array_after_pop_back;
		}

		// return a copy of it
		return result;
	}

	// if there is no element to be removed
	else {

		// throw an exception of type std::exception
		throw exception("There is no element to be removed.");
	}
}

// k. pop_front()
int my_deque::pop_front() {

	int result;

	// remove 1 element from the beginning of the deque
	if (this->array[this->lIndex + 1] != -842150451) {

		result = array[this->lIndex + 1]; // return a copy of the removed 1 element

		this->array[this->lIndex + 1] = -842150451;

		// update member variables as needed
		this->used -= 1;
		this->lIndex += 1;

		// Case 1: resize the array if needed
		if (this->used < this->size / 8 && this->size > this->initial_size) {

			// 1.1 resize (shrinking)
			this->size /= 2;

			// 1.2 a new array of half the size was allocated
			int* array_after_pop_front_intermediate = new int[this->size];
			int* array_after_pop_front = new int[this->size];

			// 1.3 elements were copied and recentered to the new array
			int count = 0;
			for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
				array_after_pop_front_intermediate[i - (lIndex + 1)] = this->array[i];
				count += 1;
			}
			this->lIndex = -1;
			this->rIndex = count;

			int shift = this->size / 8 * 3; // 8 / 8 * 3 = 3
			for (size_t i = this->lIndex + 1; i <= this->rIndex - 1; ++i) {
				array_after_pop_front[i + shift] = array_after_pop_front_intermediate[i];
			}

			// 1.4 update member variable lIndex, rIndex, and array
			this->lIndex += shift;
			this->rIndex += shift;

			delete this->array;
			this->array = array_after_pop_front;
		}

		// return a copy of it
		return result;
	}

	// if there is no element to be removed
	else {
		
		// throw an exception of type std::exception
		throw exception("There is no element to be removed.");
	}
}


// l. int* get_mem()
int* my_deque::get_mem() {

	// return the address of the array managed by the deque
	return this->array;
}

// m. int& operator[](const size_t& i)
int& my_deque::operator[](const size_t& i) {

	if (array[this->lIndex + 1 + i] != -842150451) {

		// return the ith element in the deque
		return this->array[this->lIndex + 1 + i];
	}

	else {

		// throw an exception of type std::exception
		throw exception("No element stored at that location.");
	}
}

// Part II: Implement my_deque_iterator
// Adding begin() and end() to my_deque:

// a.
my_deque_iterator my_deque::begin() {

	// pointer to the first element in "this" deque
	int* pointer_to_the_first_element = &this->array[this->get_lIndex() + 1];

	// pointer to the past element in "this" deque
	int* pointer_to_the_past_element = &this->array[this->get_rIndex()];

	// if there are elements in the deque
	if (this->lIndex + 1 != this->rIndex) {
		
		// Create and return a my_deque_iterator initialized to iterate over “this” my_deque object, and is initialized to alias the first element in “this” deque
		return my_deque_iterator(pointer_to_the_first_element, this);

	}

	// if there are no elements in the deque
	else {

		// a past the end iterator should be returned
		return my_deque_iterator(pointer_to_the_past_element, this);

	}
}

// b.
my_deque_iterator my_deque::end() {

	// pointer to the past element in "this" deque
	int* pointer_to_the_past_element = &this->array[this->get_rIndex()];

	// Create and return a my_deque_iterator initialized to iterate over “this” my_deque object, and is in a past the end state.
	return my_deque_iterator(pointer_to_the_past_element, this);

}
