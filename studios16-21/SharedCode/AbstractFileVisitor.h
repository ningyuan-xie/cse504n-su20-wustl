#pragma once
// declaration of the file visitor interface here

class TextFile;  //forward declare to fix cycle #include
class ImageFile; //forward declare to fyx cycle #include

#include <iostream>
#include <vector>
#include <string>

// Studio 19 -> Question 3a.
class AbstractFileVisitor {

public:
	virtual void visit_TextFile(TextFile*) = 0;		// Studio 19 -> 3a. takes a pointer to TextFile
	virtual void visit_ImageFile(ImageFile*) = 0;	// Studio 19 -> 3a. takes a pointer to ImageFile
};