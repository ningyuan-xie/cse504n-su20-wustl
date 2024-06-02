// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>


using namespace std;

int main()
{
    
	// Studio 17 -> Question 2
	vector<char> vector_1 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	ImageFile image_file_1("test");
	image_file_1.write(vector_1);
	
	cout << "read starts here" << endl;
	image_file_1.read();
	cout << endl << endl;
	cout << "read ends here" << endl << endl;

	// Studio 17 -> Question 4

	// 1. test addFile()
	SimpleFileSystem simple_file_system;
	simple_file_system.addFile("File_1.img", &image_file_1); // add an existing image file


	// 2. test creatFile()
	simple_file_system.createFile("File_2.txt"); // create a new text file
	simple_file_system.createFile("File_3.img"); // create an new image file


	// 3. test openFile() and write(), read() it

	// 3.1 test the opened text file 
	auto text_file_1 = simple_file_system.openFile("File_2.txt"); // open the newly created text file
	vector<char> vector_2 = { 'h', 'e', 'l', 'l', 'o' };
	text_file_1->write(vector_2);

	cout << "read starts here" << endl;
	text_file_1->read();
	cout << "read ends here" << endl << endl;

	// 3.2 test the opened image file
	auto image_file_2 = simple_file_system.openFile("File_3.img"); // open the newly created image file
	vector<char> vector_3 = { 'X', ' ', ' ', 'X', '2' };
	image_file_2->write(vector_3);

	cout << "read starts here" << endl;
	image_file_2->read();
	cout << endl << endl;
	cout << "read ends here" << endl << endl;
	

	// 4. test deleteFile()

	// 4.1 First close the two files
	simple_file_system.closeFile(text_file_1);
	simple_file_system.closeFile(image_file_2);
	
	// 4.2 Then delete "File_2.txt"
	simple_file_system.deleteFile("File_2.txt");
	
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
