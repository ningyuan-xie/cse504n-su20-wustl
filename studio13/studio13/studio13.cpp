// studio13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "studio13.h"
#include <vector>

using namespace std;


shared_ptr<detector> transfer(shared_ptr<detector> spt) // 
{
	cout << "This is beginning of transfer access" << endl;
	shared_ptr<detector> spt2 = spt;
	cout << "This is ending of transfer access" << endl;
	return spt2;
}

int main()
{
	cout << "This is begining of main" << endl;
	
	// 3. Dynamically allocate a detector object and use a C++11 shared_ptr to hold on to it
	cout << endl << "Step 3." << endl;
	shared_ptr<detector> s_pt = make_shared<detector>();
	// detector() 000001EDC9FB5AE0 x = 0

	// 4. Use shared_ptr variables and parameters to transfer access to the dynamically allocated detector object created
	cout << endl << "Step 4." << endl;
	shared_ptr<detector> s_pt2 = transfer(s_pt);
	// When main gets out of scope, the object is deleted only once

	// 5. Declare several more shared_ptr variables and dynamically allocate detector objects for each of them to hold onto
	cout << endl << "Step 5." << endl;
	shared_ptr<detector> s_pt3 = make_shared<detector>(); // detector() 000001EDC9FB5B40 x = 1
	shared_ptr<detector> s_pt4 = make_shared<detector>(); // detector() 000001EDC9FC7AA0 x = 2
	shared_ptr<detector> s_pt5 = make_shared<detector>(); // detector() 000001EDC9FC7A40 x = 3
	// More detector objects are created/destroyed because we declared more objects.
	
	// 6. Declare a vector of shared_ptr objects
	cout << endl << "Step 6." << endl;
	vector<shared_ptr<detector>> v;
	v.push_back(s_pt3);
	v.push_back(s_pt4);
	v.push_back(s_pt5);

	cout << "this is original shared_ptr " << endl;
	cout << s_pt3 << " " << s_pt4 << " " << s_pt5 << endl; // 000001EDC9FB5B40 000001EDC9FC7AA0 000001EDC9FC7A40
	cout << "this is aliased by shared_ptr of the vector " << endl;
	cout << v[0] << " " << v[1] << " " << v[2] << endl; // 000001EDC9FB5B40 000001EDC9FC7AA0 000001EDC9FC7A40
	// the same objects are being aliased by two different sets of shared_ptr variables

	// 7. A vector of pointers to detector objects that were dynamically allocated directly using the new operator
	cout << endl << "Step 7." << endl;
	vector<detector*> v1; // detector() 000001EDC9FB3DB0 x = 4
	v1.push_back(new detector);
	cout << v1[0] << endl; // 000001EDC9FB3DB0
	delete v1[0]; // ~detector() 000001EDC9FB3DB0 x = 4
	// When I explicitly call delete on the pointer to detector object, the "~detector is called".
	// The vector does not clean up memory of what objects that pointers to

	cout << "This is ending of main" << endl;

	// ~detector() 000001EDC9FC7A40 x = 3
	// ~detector() 000001EDC9FC7AA0 x = 2
	//	~detector() 000001EDC9FB5B40 x = 1
	//	~detector() 000001EDC9FB5AE0 x = 0

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
