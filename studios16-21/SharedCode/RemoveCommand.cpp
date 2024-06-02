//  define the RemoveCommand class here

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"
#include "AbstractCommand.h"
#include "MetadataDisplayVisitor.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "RemoveCommand.h"
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {}


void RemoveCommand::displayInfo() {
	cout << " rm removes a file; rm can be invoked with the command: rm <filename> " << endl;
}


int RemoveCommand::execute(string s) { // E.g. rm file.txt (remember: string s = file.txt; "rm" will be called from CommandPrompt.cpp)

	if (s == "") { // E.g. rm
		return ls::redundant_input;
	}

	int result = this->pointer_to_abstractfilesystem->deleteFile(s);

	if (result == rm::success_2)
	{
		cout << " Deleted " << endl;
		return rm::success_2;
	}
	else if (result == rm::file_not_exist)
	{
		return rm::file_not_exist;
	}
	else return rm::file_is_open;

}