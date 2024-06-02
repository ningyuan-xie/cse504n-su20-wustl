// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include "../../SharedCode/MetadataDisplayVisitor.h" // Studio 19 -> Question 5

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{	
	// Studio 19 -> Question 2c.

	// Create a file and read the file
	TextFile* tf_1 = new TextFile("test.txt");

	// read a file and store the files contents into a local variable
	vector<char> store = tf_1->read();
	
	// make an edit to the file's contents
	store.push_back('h');
	store.push_back('e');
	store.push_back('l');
	store.push_back('l');
	store.push_back('o');

	// rewrite the file with the modified contents
	tf_1->write(store);

	// Studio 19 -> Question 4.

	// Create a few files 
	TextFile* tf_2 = new TextFile("test.txt");
	ImageFile* img_2 = new ImageFile("test.img");
	
	// Create a variable of type BasicDisplayVisitor
	BasicDisplayVisitor* basic = new BasicDisplayVisitor();

	// Call accept on the file objects
	tf_2->accept(basic);
	img_2->accept(basic);


	
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
