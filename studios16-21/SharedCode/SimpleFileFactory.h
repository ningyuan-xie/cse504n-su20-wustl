#pragma once
// studio 18 - simplefilefactory class declaration goes here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/SimpleFileSystem.h"

#include "../SharedCode/AbstractFileFactory.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

// Studio 18 -> Question 3.b
class SimpleFileFactory : public AbstractFileFactory {

public:
	virtual AbstractFile* createFile(std::string s);
};



