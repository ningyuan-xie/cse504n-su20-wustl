// define methods of SimpleFileSystem class here
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/SimpleFileSystem.h"
#include "../SharedCode/Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// Studio 17 -> Question 4

// c. addFile
int SimpleFileSystem::addFile(string s, AbstractFile* AFp) {

	// check the map of files to ensure the file does not already exist
	if (this->map_of_SimpleFileSystem.count(s) == 1) {
		return 1;
	}

	// ensure the AbstractFile pointer passed to the function is not a nullptr
	if (AFp == 0) {
		return 2;
	}

	// insert a std::pair containing name and pointer into the map member variable of the class
	this->map_of_SimpleFileSystem[s] = AFp;
	return touch::success_3;
}


// d. createFile // remove it in Studio 18 -> Question 5
/* 
int SimpleFileSystem::createFile(string s) {

	// ensure a file with the same name does not already exist
	if (this->map_of_SimpleFileSystem.count(s) == 1) {
		cout << "The file already exists. createFile failed." << endl;
		return 1;
	}

	// use the file extension to determine which type of file to create
	string file_extension_txt = "txt";
	string file_extension_img = "img";

	// if the string contains "txt"
	if (s.find(file_extension_txt) != string::npos) {
		map_of_SimpleFileSystem[s] = new TextFile(s);
		cout << "Text File created!" << endl;
		return 0;
	}

	// if the string contains "img"
	if (s.find(file_extension_img) != string::npos) {
		map_of_SimpleFileSystem[s] = new ImageFile(s);
		cout << "Image File created!" << endl;
		return 0;	
	}
}
*/

// e. openFile
AbstractFile* SimpleFileSystem::openFile(string s) {

	// check to see if the filename passed exists by searching the map of files
	if (this->map_of_SimpleFileSystem.count(s) == 1) { // the file exists

		// check to ensure it is not already open
		if (this->set_of_SimpleFileSystem.count(this->map_of_SimpleFileSystem[s]) == 1) { // the file is already open
			return 0; // return nullptr
		}
		else { // the file is not open
			this->set_of_SimpleFileSystem.insert(this->map_of_SimpleFileSystem[s]);
			return map_of_SimpleFileSystem[s]; // return a pointer to the file
		}
	}

	return 0; // return nullptr
}


// f. closeFile
int SimpleFileSystem::closeFile(AbstractFile* AFp) {

	// search the set of open files for the AbstractFile pointer passed to this function
	if (this->set_of_SimpleFileSystem.count(AFp) == 1) { // the file is already open
		set_of_SimpleFileSystem.erase(AFp);	// remove it from the set of open files
		return 0; // success
	}
	else {
		return 1; // not success
	}
}


// g. deleteFile
int SimpleFileSystem::deleteFile(string s) {

	// check that the file exists
	if (this->map_of_SimpleFileSystem.count(s) == 1) { // the file exists

		// ensure that it is not currently open
		if (this->set_of_SimpleFileSystem.count(this->map_of_SimpleFileSystem[s]) == 1) { // the file is already open
			return 1; // the file is already open
		}
		else { // the file exists but is not open
			AbstractFile* location = this->map_of_SimpleFileSystem.at(s); // Saving the location: a pointer to the file
			this->map_of_SimpleFileSystem.erase(s); // remove the file from the map of files
			delete location; // call delete on the pointer to the file to avoid memory leaks

			return 0; // success
		}
	}
	else { // the file does not exist
		return 2;
	}
}

// Lab 5 1.
set<string> SimpleFileSystem::getFileNames() {

	set<string> set_of_string;
	for (auto i = this->map_of_SimpleFileSystem.begin(); i != map_of_SimpleFileSystem.end(); ++i) {
		set_of_string.insert(i->first);

	}

	return set_of_string;
}
