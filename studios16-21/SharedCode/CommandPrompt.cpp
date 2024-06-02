// define the CommandPrompt class here

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Studio 21 -> Question 3
// d. A public default constructor()
CommandPrompt::CommandPrompt(): pointer_to_abstractfilesystem(nullptr), pointer_to_abstractfilefactory(nullptr){}


// f. A public method setFileSystem()
void CommandPrompt::setFileSystem(AbstractFileSystem* AFS) {
	
	this->pointer_to_abstractfilesystem = AFS;

}

// g. A public method setFileFactory()
void CommandPrompt::setFileFactory(AbstractFileFactory* AFF) {

	this->pointer_to_abstractfilefactory = AFF;

}

// h. A public method addCommand()
int CommandPrompt::addCommand(std::string s, AbstractCommand* ACD) {

	this->map_string_and_pointer_to_abstractcommand.insert(pair<string, AbstractCommand*>(s, ACD));

	if (this->map_string_and_pointer_to_abstractcommand.count(s) == 1) {
		return 0; // return success
	}
	else {
		return 1; // return a non zero value
	}

}


// i. A protected method listCommands()
void CommandPrompt::listCommands() {

	for (auto i = map_string_and_pointer_to_abstractcommand.begin(); i != map_string_and_pointer_to_abstractcommand.end(); ++i) {
		
		// i->first will be the string within the map
		cout << i->first << endl;
	}

}

// j. A protected method prompt()
string CommandPrompt::prompt() {

	cout << endl;
	cout << "Enter a command" << endl;
	cout << "q to quit" << endl;
	cout << "help for a list of commands" << endl;
	cout << "help <command name> for details about a specific command" << endl;

	cout << "$  ";
	string input;

	// read a line of input from the standard input (usually the keyboard) into the input string
	getline(cin, input);

	return input;
}


// k. A public method int run()
int CommandPrompt::run() {

	while (1) {
		string input = prompt(); // from the standard input (usually the keyboard) into the input string 

		if (input == "q") {			// i.
			return 1;
		}

		else if (input == "help") {	// ii.
			this->listCommands();
		}

		else if (input.find(' ') == string::npos){ // iii. Check that the input is only 1 word long: E.g. ls

			// iv. Search the map of commands for the command that matches the input
			auto result_1 = this->map_string_and_pointer_to_abstractcommand.find(input);
			
			// if a command is found, result_1 will be an iterator pointing to the map element
			if (result_1 != this->map_string_and_pointer_to_abstractcommand.end()) {
				
				// invoke the command by calling “execute” on it with an empty string as argument
				// result_1->first will be the string that matches the input: E.g. ls; rm
				// result_1->second is a pointer to the AbstractCommand object: E.g. *DisplayCommand; *RemoveCommand
				int result_2 = (result_1->second)->execute(""); // E.g. result_2 = *DisplayCommand->execute("");

				// if the command returns an error
				if (result_2 != 0) {
					cout << "Command failed." << endl;
				}
			}

			else {
				cout << "command is not found" << endl;
			}
		}

		// v. if the input is longer than 1 word: E.g. help ls; ls -m
		else {

			istringstream iss(input);
			string first_word;
			iss >> first_word; // extract once: only extract the first word

			// v.1 If the first word is “help”
			if (first_word == "help") {
				string second_word; // extract a second string
				iss >> second_word; // extract a second time: extract the second word

				// Search for this command in the map of commands
				auto result_3 = this->map_string_and_pointer_to_abstractcommand.find(second_word);
				
				// if this command exists, call displayInfo() on it
				if (result_3 != this->map_string_and_pointer_to_abstractcommand.end()) {

					// result_3->second is a pointer to the AbstractCommand object
					result_3->second->displayInfo();
				}

				// if this command does not exist
				else {
					cout << "command does not exist." << endl;
				}
			}

			// v.2 the 1st word is not help, but is a command name: E.g. ls -m
			else {

				// Search for the command in the map of commands
				auto result_4 = this->map_string_and_pointer_to_abstractcommand.find(first_word);
				
				// if this command exist
				if (result_4 != this->map_string_and_pointer_to_abstractcommand.end()) {

					// passing the remaining input (everything after the first ' ') as the string parameter
					// substr(starting index, word length)
					string remaining = input.substr(first_word.size()+1, input.size()-first_word.size());

					// call execute on it 
					// result_4->second is a pointer to the AbstractCommand object
					int result_5 = (result_4->second)->execute(remaining); // E.g. -m

					// if the command returns an error
					if (result_5 != 0) { // returns an error
						cout << "Command failed." << endl;
					}
					else {
						cout << "A command is found." << endl;
					}
				}

				//if the command does not exist
				else {
					cout << "command is not found" << endl;
				}
			}

		}

	}


}






