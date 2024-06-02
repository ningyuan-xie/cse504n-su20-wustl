#pragma once
// declaration of BasicDisplayVisitor here

#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/TextFile.h"
#include "../SharedCode/ImageFile.h"

#include "../SharedCode/AbstractFileVisitor.h"

#include <iostream>
#include <vector>
#include <string>

// Lab 5 -> Question 5
class BasicDisplayVisitor2 : public AbstractFileVisitor {

public:
	virtual void visit_TextFile(TextFile*);		// Lab 5 -> 5
	virtual void visit_ImageFile(ImageFile*);   // Lab 5 -> 5
};