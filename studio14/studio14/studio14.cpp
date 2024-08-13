// studio14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{	
	cout << "This is begining of main" << endl;

	cout << endl << "Construct wrapper w using default constructor: " << endl;
	wrapper w;
	// detector() 0000020BD43439F0 x = 0
	// wrapper() 000000F6992FF678 p_d = 0000020BD43439F0

	cout << endl << "Construct wrapper w2 using copy constructor: " << endl;
	wrapper w2(w); // similar to wrapper w2 = w; which are the same for machine code
	// detector() 0000020BD4343B30 x = 1
	// wrapper() 000000F6992FF6A8 p_d = 0000020BD4343B30

	cout << endl << "This is ending of main" << endl;
	// Becasue of the deep copy construction: 4 objects were created; 4 objects were destroyed
	//~wrapper() 000000F6992FF6A8 p_d = 0000020BD4343B30
	//~detector() 0000020BD4343B30 x = 1
	//~wrapper() 000000F6992FF678 p_d = 0000020BD43439F0
	//~detector() 0000020BD43439F0 x = 0
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
