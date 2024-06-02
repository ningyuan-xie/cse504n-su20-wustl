// studio 18 - simple file factory definitions

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/SimpleFileSystem.h"

#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/SimpleFileFactory.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// Studio 18 -> Question 3.b
AbstractFile* SimpleFileFactory:: createFile(string s) {
	
	// use the file extension to determine which type of file to create
	string file_extension_txt = ".txt";
	string file_extension_img = ".img";

	// if the string contains "txt"
	if (s.find(file_extension_txt) != string::npos) {
		return new TextFile(s);
	}

	// if the string contains "img"
	if (s.find(file_extension_img) != string::npos) {
		return new ImageFile(s);
	}

	else {
		return nullptr;
	}
}
