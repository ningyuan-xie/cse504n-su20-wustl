//  define the MacroCommand class here

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"
#include "AbstractCommand.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "BasicDisplayVisitor2.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "LSCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "MacroCommand.h"
#include "RenameParsingStrategy.h"
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Question 7
MacroCommand::MacroCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {

}

void MacroCommand::displayInfo() {
	cout << "This is a MacroCommand; it should be invoked according to its strategy." << endl;
	cout << "For example: rn renames a file; rn can be invoked with the command: rn <existing_file> <new_name_with_no_extension> " << endl;
}


void MacroCommand::addCommand(AbstractCommand* ac) {
	this->vector_of_ac.push_back(ac); // vector_of_ac[0] = AbstractCommand *CopyCommand
									  // vector_of_ac[1] = AbstractCommand *RemoveCommand
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps) {
	this->pointer_to_aps = aps;
}

int MacroCommand::execute(string s) // when execute(<existing_file> <new_name_with_no_extension>), v becomes vos from RenameParsingStrategy
{
	// Lab 5 - 7.a Ask the ParsingStrategy object to parse the input provided to the macro command’s execute function
	vector<string> v = this->pointer_to_aps->parse(s); // s = <existing_file> <new_name_with_no_extension>
	cout << v[0] << " " << v[1] << endl;			   // for copy: v[0] = <existing_file> <new_name>; 
													   // for remove: v[1] = <existing_file>
	
	// Lab 5 - 7.b For each individual command the MacroCommand is composed of, 
	// call the individual command’s execute function with the corresponding input from the vector<string> returned by the ParsingStrategy
	for (auto i  = 0; i < vector_of_ac.size(); ++i)
	{
		int result = vector_of_ac[i]->execute(v[i]); // result = AbstractCommand *CopyCommand->execute(<existing_file> <new_name>); 
													 // result = AbstractCommand *RemoveCommand->execute(<existing_file>);
		if (result != success_mc)
		{
			return mc_not_execute;
		}
	}
	return success_mc;

}