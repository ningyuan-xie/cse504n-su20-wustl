#pragma once
//  declare the LSCommand class here

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

// Lab 5 1.
class LSCommand : public AbstractCommand {

public:
	LSCommand(AbstractFileSystem*);

	virtual void displayInfo();			
	virtual int execute(std::string);

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;

};

