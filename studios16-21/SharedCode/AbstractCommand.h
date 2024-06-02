#pragma once
//  declare the AbstractCommand class here

#include <iostream>
#include <vector>
#include <string>

// Studio 21 -> Question 2
class AbstractCommand {

public:

	virtual ~AbstractCommand() = default; // declare a virtual destructor
	virtual int execute(std::string) = 0; // a. the parameter will hold any information passed to the command
	virtual void displayInfo() = 0;		  // b. a usage message for the command
	

};