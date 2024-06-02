// definitions of basic display visitor here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h"
#include "../SharedCode/BasicDisplayVisitor.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Studio 19 -> Question 4. Define visit function
void BasicDisplayVisitor::visit_TextFile(TextFile* TF) {
	
	vector<char> TextFile_contents = TF->read();

	for (int i = 0; i < TextFile_contents.size(); ++i) {
		cout << TextFile_contents[i];
	}
	cout << endl;
	
}

// Studio 19 -> Question 4. Define visit function
void BasicDisplayVisitor::visit_ImageFile(ImageFile* IGF) {

	vector<char> ImageFile_contents = IGF->read();
	
	size_t size_of_contents = IGF->getSize(); // 9

	// check if size mismatch
	if (((size_t)IGF->size_of_the_image * IGF->size_of_the_image) != size_of_contents) {
		ImageFile_contents.clear();
		IGF->size_of_the_image = 0;
		cout << "size mismatch in BasicDisplayVisitor" << endl;
	}
	// check if pixel mismatch
	for (int i = 0; i <= (int) size_of_contents - 1; ++i) {
		if (ImageFile_contents[i] != 'X' && ImageFile_contents[i] != ' ') {
			ImageFile_contents.clear();
			IGF->size_of_the_image = 0;
			cout << "pixel mismatch in BasicDisplayVisitor" << endl;
		}
	}

	int height = IGF->size_of_the_image - 1; // 2
	int wide = IGF->size_of_the_image - 1; // 2

	for (int j = height; j >= 0; j--) {
		for (int i = 0; i <= wide; i++) {
			int index = j * IGF->size_of_the_image + i;
	
			cout << ImageFile_contents[index];
		}
		cout << endl;
	}
}