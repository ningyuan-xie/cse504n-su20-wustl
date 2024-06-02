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
#include "CatCommand.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* p_1) : pointer_to_abstractfilesystem(p_1) {}


void CatCommand::displayInfo() {
	cout << "cat writes a file; cat can be invoked with the command: cat <filename> " << endl;
	cout << "cat appends a file; cat can be invoked with the command: cat <filename> -a " << endl;
}


int CatCommand::execute(string s) {

	bool check = false;
	string user_input;
	vector <char> v;

	if (s == "")
	{
		return redundant_input;
	}

	size_t input = s.find_first_of(" "); // Find the space in the command
	
	// Case 1. Optional input: cat file.txt -a
	if (input != string::npos)  // OPTION "-a" INCLUDED
	{
		istringstream iss(s);
		string file_name;
		string option;
		// Find the file name and option
		iss >> file_name; // extract once to extract the file name
		iss >> option; // extract twice to extract the option

		// Make sure cat command does not work on img files
		if (file_name.substr(file_name.find_last_of(".") + 1) == "img")
		{
			return cat::img_not_allowed;
		}

		AbstractFile* af = this->pointer_to_abstractfilesystem->openFile(file_name);
		if (af == nullptr)  // No file exist, or wrong input file
		{
			cout << " File does not exist " << endl;
			return rm::file_not_exist;
		}
		else // If open file successfully
		{
			if (option == "-a") // Display the content of the file
			{
				vector<char> content = af->read();
				cout << file_name << endl;
				for (auto i = 0; i < content.size(); ++i)
				{
					cout << content[i];
				}
				cout << endl;

				// Start to APPEND to file
				cout << "Enter what you would like to write to the file. " << endl;
				cout << "Or enter :wq to save the file and exit" << endl;
				cout << "Or enter :q to exit without saving" << endl;
				while (1)
				{
					// prompt_user()
					getline(cin, user_input);
					if (user_input == ":q") // 1.1 User quit without saving
					{
						v.clear();
						user_input.clear();
						break;
					}
					else if (user_input == ":wq")  // 1.2 APPEND and Save and Quit
					{
						af->append(v); // APPEND here
						user_input.clear();
						break;
					}
					
					// 1.3 If the line is not “:wq” or “:q”, the data should be saved temporarily
					for (size_t i = 0; i < user_input.size(); ++i)
					{
						v.push_back(user_input[i]); // Saving data temporarily
					}
				}
				// after "break", Quit 
				this->pointer_to_abstractfilesystem->closeFile(af);
			}
			else return wrong_option_followed_by; // Not "-a" 
		}
		return cat::success_4;
	}
	
	// Case 2. Default input: cat file.txt
	else   // NO OPTION INCLUDED
	{
		cout << s << endl;
		AbstractFile* af1 = this->pointer_to_abstractfilesystem->openFile(s);
		v.clear();
		//Start to OVER-WRITE the file
		if (af1 == nullptr)  // No file exist, or wrong input file
		{
			cout << " File does not exist " << endl;
			return rm::file_not_exist;
		}
		else //If open file successfully
		{
			//Start to WRITE to file
			cout << "Enter what you would like to write to the file." << endl;
			cout << "Or enter :wq to save the file and exit." << endl;
			cout << "Or enter :q to exit without saving." << endl;
			while (1)
			{
				// prompt_user()
				getline(cin, user_input);
				if (user_input == ":q") // 2.1 User quit without saving
				{
					v.clear();
					user_input.clear();
					break;
				}
				else if (user_input == ":wq")  // 2.2 Write and Save and Quit
				{
					if (v.size() == 0) { // current saved data is empty
						af1->write(v); // Clear the current content and over-write
						user_input.clear();
						this->pointer_to_abstractfilesystem->closeFile(af1); // Quit
						return cat::success_4;
					}
					v.pop_back();  // Remove the last element: Pop the empty line last added below from "Down 1 line"
					af1->write(v);  // Clear the current content and over-write
					user_input.clear();
					break;
				}
				
				// 2.3 If the line is not “:wq” or “:q”, the data should be saved temporarily
				for (size_t i = 0; i < user_input.size(); ++i)
				{
					v.push_back(user_input[i]); // Saving data temporarily
				}
				v.push_back('\n'); // Down 1 line
			}
			// after "break", Quit 
			this->pointer_to_abstractfilesystem->closeFile(af1);
		}
		return cat::success_4;
	}
	return cat::success_4;
}