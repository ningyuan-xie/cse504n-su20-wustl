// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include  "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandTest.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/CatDsStrategy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	// Studio 21 -> Question 4. SET UP FILE SYSTEM
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();

	CommandPrompt* Command_Prompt = new CommandPrompt();
	Command_Prompt->setFileSystem(sfs); // configure it with the file system
	Command_Prompt->setFileFactory(sff); // configure it with the file factory


	// Studio 21 -> Question 4.(CommandTest is a command simply for testing purpose)
	CommandTest* ct = new CommandTest(sfs);
	string commandname = "test";
	Command_Prompt->addCommand(commandname, ct);


	// Lab 5 -> Question 3. TouchCommand
	TouchCommand tc(sfs, sff); // TouchCommand object (configured with the file system and file factory objects)
	string commandname_3 = "touch";
	Command_Prompt->addCommand(commandname_3, &tc);


	//  Lab 5 -> Question 1. LSCommand Test
	LSCommand lsc(sfs);
	string commandname_1 = "ls";
	Command_Prompt->addCommand(commandname_1, &lsc);


	//  Lab 5 -> Question 2. RemoveCommand test
	RemoveCommand rmc(sfs);
	string commandname_2 = "rm";
	Command_Prompt->addCommand(commandname_2, &rmc);


	//  Lab 5 -> Question 4. CatCommand test
	CatCommand catc(sfs);
	string commandname_4 = "cat";
	Command_Prompt->addCommand(commandname_4, &catc);


	//  Lab 5 -> Question 5. DisplayCommand test
	DisplayCommand dsc(sfs);
	string commandname_5 = "ds";
	Command_Prompt->addCommand(commandname_5, &dsc);


	//  Lab 5 -> Question 6. CopyCommand test
	CopyCommand cpc(sfs);
	string commandname_6 = "cp";
	Command_Prompt->addCommand(commandname_6, &cpc);

	
	//Lab 5 -> Question 7+8  Macro Command
	MacroCommand* mc = new MacroCommand(sfs); // create a MacroCommand object
	string commandname_7 = "rn";
	Command_Prompt->addCommand(commandname_7, mc);

	RenameParsingStrategy* rps = new RenameParsingStrategy; // a RenameParsingStrategy object
	mc->setParseStrategy(rps); // MacroCommand object configured with a RenameParsingStrategy object as its AbstractParsingStrategy
	mc->addCommand(&cpc); // CopyCommand as its command objects
	mc->addCommand(&rmc); // RemoveCommand object as its command objects


	// Lab 5 -> Extra credit c. We tried out Cat + ds here
	MacroCommand* mc_1 = new MacroCommand(sfs); // create a MacroCommand object
	string commandname_extra_c_1 = "catds";
	Command_Prompt->addCommand(commandname_extra_c_1, mc_1);

	CatDsStrategy* cds = new CatDsStrategy; // a CatDsStrategy object
	mc_1->setParseStrategy(cds); // MacroCommand object configured with a CatDsStrategy object as its AbstractParsingStrategy
	mc_1->addCommand(&catc); // CatCommand as its command objects
	mc_1->addCommand(&dsc);	// DisplayCommand as its command objects


	// Run the CommandPrompt
	Command_Prompt->run();

	// Studio 21 -> Question 4. Check after the user input "q" to quit the run() functions and the run() returns a value,
	//the file system object can still be accessed (the user input "touch abc.txt").

	if (sfs->openFile("abc.txt") != nullptr) {

		cout << "The user input 'q' to quit. After the user inputs 'touch abc.txt' to create the file and inputs'q' to quit (then the run() function returns a value), the file 'abc.txt' can still be accessed in main()." << endl;
	}
	/*
	else {  //Studio 21 -> Question 4

		cout << "The user input 'q' to quit. Either the user does not inputs 'touch abc.txt' or after the user inputs 'touch abc.txt' to create the file and inputs'q' to quit (then the run() function returns a value), the file 'abc.txt' cannot be accessed in main()." << endl;
	}
    */

}
