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
#include "CopyCommand.h"
#include "Enum.h"
#include "PasswordProxy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Question 6
CopyCommand::CopyCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {}


void CopyCommand::displayInfo() {
	cout << "cp copies a file; cp can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension> " << endl;
}


int CopyCommand::execute(string s) { // E.g. cp file.txt file_copy

	bool password_check = false;
	if (s.find(" ") == string::npos) {
		return copy::not_enough_input;
	}

	else {
		istringstream iss(s);
		string original_file;
		string copied_file;
		iss >> original_file; // extract once to extract the original file name
		iss >> copied_file; // extract twice to extract the copied file name

		// opens the original_file
		AbstractFile* p_to_original_file = this->pointer_to_abstractfilesystem->openFile(original_file);

		// Error: no original file here
		if (p_to_original_file == nullptr) {
			return copy::no_original_file;
		}

		// Check if the file has password
		PasswordProxy* proxy_original = dynamic_cast<PasswordProxy*>(p_to_original_file);

		if (proxy_original != nullptr) { password_check = true; }	

		// Add extensions to the copied file name
		string extended_copied_file;
		if (original_file.find("txt") != string::npos) {
			extended_copied_file = copied_file + ".txt";
		}
		if (original_file.find("img") != string::npos) {
			extended_copied_file = copied_file + ".img";
		}

		// copy a new file here
		AbstractFile* p_to_copied_file = p_to_original_file->clone(extended_copied_file);

		// close the original file
		this->pointer_to_abstractfilesystem->closeFile(p_to_original_file);

		// add that copied file to the system
		if (this->pointer_to_abstractfilesystem->addFile(extended_copied_file, p_to_copied_file) == touch::success_3)
		{
			if (password_check)  // If password exists on the copy file
			{			
				// add that copied proxy file to the system
				AbstractFile* proxy_copy = proxy_original->clone(extended_copied_file);
				this->pointer_to_abstractfilesystem->addFile(proxy_copy->getName(), proxy_copy);
			}
			return copy::success_6;
		}
		else {
			return copy::add_to_system_failed;
		}

	}

	return copy::success_6;
}
