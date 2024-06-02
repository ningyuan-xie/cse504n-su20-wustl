// definition of ImageFile class here
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h" // Studio 19 -> Question 3c.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Studio 17 -> Question 2
ImageFile::ImageFile(string s) : name(s), size_of_the_image(0) //initialize size member = 0
{}


// a. getSize
unsigned int ImageFile::getSize() {
	return (unsigned int)contents.size();
}


// b. getName
string ImageFile::getName() {
	return name;
}


// c. write
int ImageFile::write(vector<char> v)
{
	size_t size_of_v = v.size(); // 10
	size_t size_index = size_of_v - 1; // 9
	this->size_of_the_image = v[size_index] - 48; // set the size member variable

	size_t converted_size_of_the_image = (size_t)this->size_of_the_image; // 3

	// copy the previous contents of the vector into the vector<char> member variable
	size_t previous_content_index = size_of_v - 2; // 8

	// check if size mismatch
	if ((converted_size_of_the_image * converted_size_of_the_image) != size_index) {
		this->contents.clear();
		this->size_of_the_image = 0;

		cout << "size mismatch" << endl; // debugging
		return 1;
	}

	// check if pixel mismatch
	for (int i = 0; i <= previous_content_index; ++i) {
		if (v[i] != 'X' && v[i] != ' ') {
			this->contents.clear();
			this->size_of_the_image = 0;

			cout << "pixel mismatch" << endl; // debugging
			return 2;
		}
		else {
			this->contents.push_back(v[i]);
		}
	}
	return 0; // the write was successful

}


// d. append
int ImageFile::append(vector<char> v)
{
	return 2; // an image file should not support append
}


// e. read (include a helper function)

// Studio 19 -> Question 2b. Update the concrete class read function
/*
int ImageFile::read_helper(int x, int y) {
	return (y * this->size_of_the_image + x);
}

void ImageFile::read() {

	int height = this->size_of_the_image - 1;
	int wide = this->size_of_the_image - 1;

	for (int j = height; j >= 0; j--) {
		for (int i = 0; i <= wide; i++) {
			int index = read_helper(i, j);

			cout << this->contents[index] << " ";
		}
		cout << endl;
	}
}
*/


// Studio 19 -> Question 2b. Update the concrete class read function
vector<char> ImageFile::read() {

	return this->contents;

}

// Studio 19 -> Question 3c. Define "accept" in concrete file class
void ImageFile::accept(AbstractFileVisitor* AFV) {

	AFV->visit_ImageFile(this);

}

// Lab 5 -> Question 6.
AbstractFile* ImageFile::clone(string s) {

	//return new ImageFile(*this);
	string temp = this->name;

	this->name = s;

	AbstractFile* tf = new ImageFile(*this);

	this->name = temp;

	return tf;

}