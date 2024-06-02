// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/SimpleFileFactory.h"

#include "../../SharedCode/AbstractFileVisitor.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	string fileName = "FileName.img";

	// Studio 20 -> Question 4

	// dynamically allocate an AbstractFile
	ImageFile* i = new ImageFile("File.img");

	// PasswordProxy for that file 
	PasswordProxy* p = new PasswordProxy(i, "123456");

	// Reading the file
	cout << "Reading the file:" << endl;
	cout << "Password:";
	p->read();

	// Writing the file
	cout << "Writing the file:" << endl;
	cout << "Password:";
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	p->write(v);

	// Displaying the file via the proxy object
	cout << "Reading the file:" << endl;
	cout << "Password:";
	BasicDisplayVisitor bdv;
	p->accept(&bdv);
	
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
