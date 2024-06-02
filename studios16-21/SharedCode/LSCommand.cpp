//  define the LSCommand class here

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"
#include "AbstractCommand.h"
#include "MetadataDisplayVisitor.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "LSCommand.h"
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {}


void LSCommand::displayInfo() {
	cout << "ls displays the name of all files currently in the file system; ls can be invoked with the command: ls " << endl;
}


int LSCommand::execute(string s) {

	// from SimpleFileSystem: return a set of string
	set<string> file_names = this->pointer_to_abstractfilesystem->getFileNames(); 
	
	// Case 1. Default version: $ ls
	if (s == "") {
		
		int count = 0;
		for (auto i = file_names.begin(); i != file_names.end(); ++i) {
			
			// Every second file name (0, 2, 4, etc.) is printed followed by spaces to align them neatly in columns
			if (count % 2 == 0) { // such as 0, 2, 4
				cout <<*i ;

				// add spaces to make the file names print out in an appropriate way 
				int name_length = (*i).length();
				int number_of_spaces = 25 - name_length;
				for (int t = 1; t <= number_of_spaces; ++t) { // Print the file name and add spaces to make each line 25 characters long
					cout << " ";
				}
			}
			
			// the other file names (1, 3, 5, etc.) are printed normally and followed by a newline character
			else { // such as 1, 3, 5
				cout << *i << endl;
			}
			++count;
		}
		cout << endl;
		
		return ls::success_1;
	}

	// Case 2. Optional version: $ ls -m
	else if (s == "-m") {

		MetadataDisplayVisitor mdv;

		for (auto i = file_names.begin(); i != file_names.end(); ++i) {

			// For each file name, the file is opened using the openFile method of the file system
			AbstractFile* af = this->pointer_to_abstractfilesystem->openFile(*i);
			
			// the MetadataDisplayVisitor instance visits the file to display its metadata
			af->accept(&mdv);
			
			// After the visitor has done its work, the file is closed using the closeFile method of the file system
			this->pointer_to_abstractfilesystem->closeFile(af);

		}
		cout << endl;
		
		return ls::success_1;
	}

	else {
		return ls::redundant_input;
	}
	
}