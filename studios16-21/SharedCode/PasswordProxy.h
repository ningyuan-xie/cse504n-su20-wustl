#pragma once

#include "AbstractFile.h"

#include <iostream>
#include <vector>
#include <string>

// Studio 20 -> Question 2.
class PasswordProxy : public AbstractFile {

public:
	PasswordProxy(AbstractFile* p, std::string s); // c. a constructor takes in a pointer to an AbstractFile and a string representing password
	~PasswordProxy();							   // d. a destructor that deletes the pointer to the real file

	// Studio 20 -> Question 3. Inherit all of the public functions declared in the AbstractFile class
	virtual std::vector<char> read();			   // a. read
	virtual int write(std::vector<char>);		   // b. write
	virtual int append(std::vector<char>);		   // c. append
	virtual unsigned int getSize();				   // d. getSize
	virtual std::string getName();				   // e. getName
	virtual void accept(AbstractFileVisitor*);     // f. accept
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual AbstractFile* clone(std::string); // Lab 5 -> Question 6.

protected:
	virtual std::string passwordPrompt();		   // e. a protected method passwordPrompt that returns a string
	virtual bool helper_check(std::string);		   // f. a helper function checking whether a string matches the password member variable

private:
	AbstractFile* pointer_to_an_abstractfile;	   // a. a private pointer to an AbstractFile
	std::string password;						   // b. a private string - this will be the password for the real life
};