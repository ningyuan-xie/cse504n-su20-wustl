//  Define the TextFile class here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h" // Studio 19 -> Question 3c.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Studio 16 -> Question 3
TextFile::TextFile(string s) :name(s) {}

unsigned int TextFile::getSize() {
	return (unsigned int)contents.size();
}

std::string TextFile::getName() {
	return name;
}

int TextFile::write(std::vector<char> v) {
	contents = v;
	return 0;
}

int TextFile::append(std::vector<char> v) {

	//contents.push_back('\n');
	for (int i = 0; i < v.size(); ++i) {
		contents.push_back(v[i]);
		//contents.push_back("\n");
	}
	return 0;
}


// Studio 19 -> Question 2b. Update the concrete class read function
/*
void TextFile::read() {

	for (int i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
}
*/

// Studio 19 -> Question 2b. Update the concrete class read function
vector<char> TextFile::read() {

	return this->contents;

}

// Studio 19 -> Question 3c. Define "accept" in concrete file class
void TextFile::accept(AbstractFileVisitor* AFV) {
	
	AFV->visit_TextFile(this);

}

// Lab 5 -> Question 6.
AbstractFile* TextFile::clone(string s) {
	
	string temp = this->name;

	this->name = s;

	AbstractFile* tf = new TextFile (*this);

	this->name = temp;

	return tf;

}