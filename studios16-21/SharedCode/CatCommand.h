#pragma once
//  declare the CatCommand class here

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



// Lab 5 - 4
class CatCommand : public AbstractCommand {

public:
	CatCommand(AbstractFileSystem*);

	virtual void displayInfo();			// a.
	virtual int execute(std::string);   // b.

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;
};