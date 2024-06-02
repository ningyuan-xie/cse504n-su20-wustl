#pragma once
// Image file class declaration here

#include "AbstractFile.h"
#include "AbstractFileVisitor.h" // Studio 19 -> Question 3c.

#include <vector>
#include <string>



// Studio 17 -> Question 2
class ImageFile : public AbstractFile {

	friend class BasicDisplayVisitor;
	friend class BasicDisplayVisitor2; // for Lab 5 -> Question 5

public:
	ImageFile(std::string s);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);

	//virtual void read();			  // Studio 19 -> Question 2b. Update the concrete class read function
	virtual std::vector<char> read(); // Studio 19 -> Question 2b. Update the concrete class read function

	virtual void accept(AbstractFileVisitor*); // Studio 19 -> Question 3c. Declare "accept" in concrete file class

	virtual AbstractFile* clone(std::string); // Lab 5 -> Question 6.

private:
	std::string name;						// a.
	std::vector<char> contents;				// b.
	char size_of_the_image;					// c.
	//int read_helper(int x, int y); a helper function for Question 2e of studio 17

};