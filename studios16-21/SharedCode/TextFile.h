#pragma once

#include "AbstractFile.h"
#include "AbstractFileVisitor.h" // Studio 19 -> Question 3c.

#include <vector>
#include <string>

// TextFile declaration goes here

// Studio 16 -> Question 3
class TextFile :public AbstractFile {
public:
	TextFile(std::string s);

	//virtual void read();			  // Studio 19 -> Question 2b. Update the concrete class read function
	virtual std::vector<char> read(); // Studio 19 -> Question 2b. Update the concrete class read function

	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();

	virtual void accept(AbstractFileVisitor*); // Studio 19 -> Question 3c. Declare "accept" in concrete file class

	virtual AbstractFile* clone(std::string); // Lab 5 -> Question 6.

private:
	std::vector<char> contents;
	std::string name;
};