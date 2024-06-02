#pragma once
// studio 18 - file factory interface declared here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/SimpleFileSystem.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

// Studio 18 -> Question 3.a
class AbstractFileFactory {

public:
	virtual AbstractFile* createFile(std::string s) = 0; // a.
};