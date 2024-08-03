// cse504N_studio_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// static means internal linkage: the function is only visible in the current file
static void mySwap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
	cout << "mySwap version 1" << endl;
	return;
}

int main()
{
	int num_1 = 1;
	int num_2 = 2;

	int* p_1 = &num_1; // p_1 is a pointer to the location of num_1
	int* p_2 = &num_2; // p_2 is a pointer to the location of num_2

	mySwap(num_1, num_2);

	cout << "num_1: " << num_1 << ", num_2: " << num_2 << endl; // 2, 1
	cout << "*p_1: " << *p_1 << ", *p_2: " << *p_2 << endl; // Dereference: 2, 1

	return 0;
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
