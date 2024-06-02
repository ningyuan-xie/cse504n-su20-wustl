#pragma once
//  declare the CommandPrompt class here

//#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"
//#include "AbstractCommand.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Studio 21 -> Question 3
class CommandPrompt {

public:
	CommandPrompt();								// d. A public default constructor()
	void setFileSystem(AbstractFileSystem*);		// f. A public method setFileSystem()
	void setFileFactory(AbstractFileFactory*);		// g. A public method setFileFactory()
	int addCommand(std::string, AbstractCommand*);  // h. A public method addCommand()
	int run();										// k. A public method int run()

protected:
	void listCommands();							// i. A protected method listCommands()
	std::string prompt();							// j. A protected method prompt()

private:
	std::map<std::string, AbstractCommand*> map_string_and_pointer_to_abstractcommand; // a. A map
	AbstractFileSystem* pointer_to_abstractfilesystem;								   // b. A pointer
	AbstractFileFactory* pointer_to_abstractfilefactory;							   // c. A pointer
};