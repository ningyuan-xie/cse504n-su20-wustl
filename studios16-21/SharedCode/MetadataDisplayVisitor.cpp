// definitions of metadata visitor here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h"
#include "../SharedCode/BasicDisplayVisitor.h"
#include "../SharedCode/MetadataDisplayVisitor.h" // Studio 19 -> Question 5

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Studio 19 -> Question 5. Define visit function: display a file's name, size, and type
void MetadataDisplayVisitor::visit_TextFile(TextFile* TF) {

	int file_name_number_of_characters = TF->getName().length();
	int number_of_spaces = 25 - file_name_number_of_characters;
	cout << TF->getName();
	for (int t = 1; t <= number_of_spaces; ++t) {
		cout << " ";
	}
	cout << "text" << "      " << TF->getSize() << endl;
	
}

// Studio 19 -> Question 5. Define visit function
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* IGF) {

	int file_name_number_of_characters = IGF->getName().length();
	int number_of_spaces = 25 - file_name_number_of_characters;
	cout << IGF->getName();
	for (int t = 1; t <= number_of_spaces; ++t) {
		cout << " ";
	}
	cout << "image" << "     " << IGF->getSize() << endl;
}
