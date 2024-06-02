// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/SimpleFileFactory.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{	
	// Studio 18 -> Question 4

	// Initialize a pointer to an AbstractFileSystem pointing to a dynamically allocated SimpleFileSystem
	AbstractFileSystem* pointer_to_abstract_system = new SimpleFileSystem();

	// Configure a variable pointer to an AbstractFileFactory pointing to a dynamically allocated SimpleFileFactory
	AbstractFileFactory* pointer_to_abstract_factory = new SimpleFileFactory();

	// Create a few files via the factory object
	AbstractFile* pointer_to_abstract_file = pointer_to_abstract_factory->createFile("Text_File_1.txt");

	// Add the files to the file system
	SimpleFileSystem simple_file_system;
	simple_file_system.addFile("Text_File_1.txt", pointer_to_abstract_file);

	// Open the file
	auto text_file_1 = simple_file_system.openFile("Text_File_1.txt");

	// Write the file
	vector<char> vector_2 = { 'h', 'e', 'l', 'l', 'o' };
	text_file_1->write(vector_2);

	// Read the file
	cout << "read starts here" << endl;
	text_file_1->read();
	cout << endl << "read ends here" << endl;

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
