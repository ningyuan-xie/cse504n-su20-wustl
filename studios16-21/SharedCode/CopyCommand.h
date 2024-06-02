#pragma once
//  declare the CopyCommand class here

#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Lab 5 -> Question 6
class CopyCommand : public AbstractCommand {

public:
	CopyCommand(AbstractFileSystem*);

	virtual void displayInfo();
	virtual int execute(std::string);

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;

};

