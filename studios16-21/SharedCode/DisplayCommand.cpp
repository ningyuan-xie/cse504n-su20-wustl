//  define the DisplayCommand class here

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
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Question 5
DisplayCommand::DisplayCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {}


void DisplayCommand::displayInfo() {
	cout << "ds displays a file; ds can be invoked with the command: ds <filename> " << endl;
	cout << "ds displays a file unformattly; ds can be invoked with the command: ds <filename> -d " << endl;
}


int DisplayCommand::execute(string s) {

	if (s == "")
	{
		return ds::no_input;
	}

	// displays its contents
	// Case 1. Default input: ds image.img
	if (s.find(" ") == string::npos) { // formatted

		// opens a file
		AbstractFile* af = this->pointer_to_abstractfilesystem->openFile(s);

		if (af == nullptr) {
			return ds::file_not_exist_ds;
		}

		BasicDisplayVisitor bdv;

		af->accept(&bdv);

		this->pointer_to_abstractfilesystem->closeFile(af);

		return ds::success_5;
	}

	// Case 2. Optional input: ds image.img -d
	else { // unformatted
		
		istringstream iss(s);
		string file_name;
		string option;
		// Find the file name and option
		iss >> file_name; // extract once to extract the file name
		iss >> option; // extract twice to extract the option

		if (option == "-d") {

			// opens a file
			AbstractFile* af = this->pointer_to_abstractfilesystem->openFile(file_name);

			if (af == nullptr) {
				return ds::file_not_exist_ds;
			}

			BasicDisplayVisitor2 bdv2; // note that BasicDisplayVisitor2 from BasicDisplayVisitor above

			af->accept(&bdv2);

			this->pointer_to_abstractfilesystem->closeFile(af);

			return ds::success_5;
		}

		else {
			cout << "redundant input" << endl;
			return ds::wrong_additional_input;

		}
	}

}