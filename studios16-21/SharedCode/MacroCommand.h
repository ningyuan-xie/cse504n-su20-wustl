#pragma once
//  declare the MacroCommand class here

#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;
class AbstractParsingStrategy;

// Lab 5 -> Question 7
class MacroCommand : public AbstractCommand {

public:
	MacroCommand(AbstractFileSystem*);
	
	virtual void displayInfo();
	virtual int execute(std::string);

	// As a MacroCommand is a composite object in the composite pattern
	// it needs to provide a function for adding individual commands to its vector of commands.
	void addCommand(AbstractCommand*);

	// Add a function to set the macro command’s parsing strategy as well
	void setParseStrategy(AbstractParsingStrategy*);

private:
	AbstractFileSystem* pointer_to_abstractfilesystem;

	std::vector<AbstractCommand*> vector_of_ac;
	AbstractParsingStrategy* pointer_to_aps;
};