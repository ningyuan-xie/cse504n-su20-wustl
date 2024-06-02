#pragma once
// declaration of the interface all file systems provide goes here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include <iostream>
#include <vector>
#include <string>
#include <set>

// Studio 17 -> Question 3
class AbstractFileSystem {

public:
	virtual int addFile(std::string, AbstractFile*) = 0; // a.
	//virtual int createFile(std::string) = 0;			 // b. // remove it in Studio 18 -> Question 5
	virtual int deleteFile(std::string) = 0;			 // c.
	virtual AbstractFile* openFile(std::string) = 0;	 // d.
	virtual int closeFile(AbstractFile*) = 0;			 // e.

	// Lab 5 1.
	virtual std::set<std::string> getFileNames() = 0;
};