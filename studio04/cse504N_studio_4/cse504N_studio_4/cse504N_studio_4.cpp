// cse504N_studio_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	unsigned int arr[2][3][5] = {0}; // 3-dimensional 2 by 3 by 5 array

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; j++) {
			for (int h = 0; h < 5; h++) {
				arr[i][j][h] = i * j * h;
				cout << "i = " << i << ", j= " << j << ", h= " << h<< endl;
				cout << "array's current value of cell = " << arr[i][j][h] << endl;
			}
		}
	}

	vector<string> v;

	for (int i = 0; i < argc; i++) {
		v.push_back(argv[i]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << "v = " << v[i] << endl;
	}


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
