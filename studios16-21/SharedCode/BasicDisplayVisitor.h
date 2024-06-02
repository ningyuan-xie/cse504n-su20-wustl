#pragma once
// declaration of BasicDisplayVisitor here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h"

#include <iostream>
#include <vector>
#include <string>

// Studio 19 -> Question 4
class BasicDisplayVisitor: public AbstractFileVisitor {

public:
	virtual void visit_TextFile(TextFile*);		// Studio 19 -> Question 4. Declare visit function
	virtual void visit_ImageFile(ImageFile*);   // Studio 19 -> Question 4. Declare visit function

};