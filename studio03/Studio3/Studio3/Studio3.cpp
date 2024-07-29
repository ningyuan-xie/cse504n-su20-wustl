// Studio3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])

// int argc: "argument count", the number of command-line arguments passed to the program when it is executed.
// char* argv[]: "argument vector", an array of strings (or array of character pointers) containing the command-line arguments themselves. 
// Each element of this array represents one command-line argument.

{
	for (auto b = argv; b != 0; ++b){ 
		// auto b = argv: This initializes a pointer b to the beginning of the argv array. 
		// In C++, auto is used for type inference, so b will have the same type as the elements of argv, which is char*.
		// cout << *b << endl; // This prints the value pointed to by b
		// *b: This dereferences the pointer b, giving us the value (i.e., a pointer to a string) that b is pointing to. 
		// In this case, it's a command-line argument passed to the program.
		std::cout << "b = " << *b << std::endl; 

		for (auto c = b; *c != '\0'; ++c) {
			// This condition checks whether the character pointed to by c is not equal to the null character ('\0'). 
			// In C and C++, strings are terminated by a null character, so this loop continues until it encounters the null character, indicating the end of the string.
			// cout << *c << endl; // This prints the character pointed to by c to the standard output stream (cout) followed by a newline (endl).
			// *c This dereferences the pointer c, giving us the character that c is pointing to
			std::cout << "c = " << *c << std::endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
