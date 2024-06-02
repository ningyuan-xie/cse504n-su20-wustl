#pragma once
//  declare the TouchCommand class here

//#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"
//#include "AbstractCommand.h"
#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Studio 21 -> Question 4
class TouchCommand: public AbstractCommand {

public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);

	virtual void displayInfo();			// a.
	virtual int execute(std::string);   // b.

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;
	AbstractFileFactory* pointer_to_abstractfilefactory;
};