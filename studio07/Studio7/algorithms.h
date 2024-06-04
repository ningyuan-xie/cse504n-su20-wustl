#pragma once
/* algorithms.h
Author: Jon Shidal

Purpose: This file holds function declarations for the algorithms used throughout this program
*/

// example header guards, this prevents the precompiler from copying the same header file in to a single .cpp more than once.
// #pragma once above accomplishes the same goal. However, although most compilers support #pragma once,
// it is not in the C++ standard
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include<vector>

// sort a vector of integers into ascending order using an implementation of insertion sort
void insertion_sort(std::vector<int> & v);

// search a vector of integers for a given integer. Returns true if value was found. Returns false otherwise.
bool binary_search(const std::vector<int> & v, int value);

#endif  // ALGORITHMS_H