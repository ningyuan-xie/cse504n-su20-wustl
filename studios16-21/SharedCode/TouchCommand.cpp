//  define the TouchCommand class here

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "Enum.h"
#include "PasswordProxy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>


using namespace std;

// Studio 21 -> Question 4
// Touch needs to create file, so compared to other commands, it also needs a pointer to abstractfilefactory
TouchCommand::TouchCommand(AbstractFileSystem* p_1, AbstractFileFactory* p_2): pointer_to_abstractfilesystem(p_1), pointer_to_abstractfilefactory(p_2) {}

// a.
void TouchCommand::displayInfo() {
	cout << "touch creates a file; touch can be invoked with the command: touch <filename> " << endl;
	cout << "touch creates a file with password; touch can be invoked with the command: touch <filename> -p " << endl;
}

// b.
int TouchCommand::execute(string s) {
	
	if (s.length() >= 20) { // Lab 5.1: Assume file names are less than 20 characters
		cout << "Assume file names are less than 20 characters. Please input a file name that is less than 20 characters." << endl;
		return touch::file_not_created;
	}

	// Case 1: No '-p' option is included
	if (s.find("-p") == string::npos)
	{
		// ask the file factory to create a file with the provided filename
		auto result_1 = this->pointer_to_abstractfilefactory->createFile(s);

		// if the file is created successfully
		if (result_1 != nullptr) {

			// added to the file system object by calling addFile
			int result_2 = this->pointer_to_abstractfilesystem->addFile(s, result_1);

			// the file was not added to the file correctly
			if (result_2 != 0) {
				delete result_1;
				return touch::file_not_added;
			}
			else {
				return touch::success_3;
			}

		}
		// if the file was not created successfully
		else {
			return touch::file_not_created;
		}
	}

	// Lab 5.3
	// Case 2: Added '-p' option to create passpord protected file
	else {
	
		istringstream iss(s);
		string file_name;
		iss >> file_name; // extract once to only extract the file name

		string pass_word;
		cout << " What is the password ? " << endl;
		getline(cin, pass_word); // Get password from keyboard input
		
		auto result_3 = this->pointer_to_abstractfilefactory->createFile(file_name);
		if (result_3 != nullptr) // If successfully created file
		{
			AbstractFile* password_protected_file = new PasswordProxy(result_3, pass_word);

			// Added for password 
			int result_4 = this->pointer_to_abstractfilesystem->addFile(file_name, password_protected_file);
			// the file was not ADDED to the file correctly
			if (result_4 == touch::file_not_added)
			{
				delete result_3;
				return touch::file_not_added;

			}
			else return touch::success_3;
		}
	
		else {
			return touch::file_not_created; // if the file was not CREATED successfully
		}
			
	}

}

