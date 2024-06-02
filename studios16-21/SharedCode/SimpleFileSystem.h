#pragma once
// declaration of SimpleFileSystem class goes here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"
#include "../SharedCode/AbstractFileSystem.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

// Studio 17 -> Question 4
class SimpleFileSystem : public AbstractFileSystem {

public:
	virtual int addFile(std::string, AbstractFile*);
	//virtual int createFile(std::string); // remove it in Studio 18 -> Question 5
	virtual int deleteFile(std::string);			 
	virtual AbstractFile* openFile(std::string);	 
	virtual int closeFile(AbstractFile*);
	
	// Lab 5 1.
	virtual std::set<std::string> getFileNames();

private:
	std::map<std::string, AbstractFile*> map_of_SimpleFileSystem; // a. This map include files in the file sytem.
	std::set<AbstractFile*> set_of_SimpleFileSystem;			  // b. Currently-opened files are stored in the set
};

