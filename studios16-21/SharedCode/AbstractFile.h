#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <iostream>
#include <vector>
#include <string>

class AbstractFileVisitor; // Forward declaration to fix cycle in include

// Studio 16 -> Question 2
class AbstractFile {
public:
	
	//virtual void read() = 0;			  // Studio 19 -> Question 2a. Update the AbstractFile read function
	virtual std::vector<char> read() = 0; // Studio 19 -> Question 2a. Update the AbstractFile read function
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;

	virtual void accept(AbstractFileVisitor*) = 0; // Studio 19 -> Question 3b. Update the interface of files to allow visited by a vistor

	//virtual ~AbstractFile() = 0;
	virtual AbstractFile* clone(std::string) = 0; // Lab 5 -> Question 6.
};

