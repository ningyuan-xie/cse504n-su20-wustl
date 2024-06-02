#pragma once
//  declare the DisplayCommand class here

#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Lab 5 -> Question 5
class DisplayCommand : public AbstractCommand {

public:
	DisplayCommand(AbstractFileSystem*);

	virtual void displayInfo();
	virtual int execute(std::string);

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;

};