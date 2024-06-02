//  define the RenameParsingStrategy class here

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
#include "RemoveCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "MacroCommand.h"
#include "AbstractParsingStrategy.h"
#include "RenameParsingStrategy.h"
#include "CatDsStrategy.h"
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Extra credit c.
vector<string> CatDsStrategy::parse(string s) // s = <existing_file>
{

	vector<string> v_o_s;
	if (s.find(" ") != string::npos) {

		throw exception("too many inputs");
		return v_o_s;
	}
	else
	{
		istringstream iss(s);

		string original_file; // extract once to extract the existing file name

		iss >> original_file;

		v_o_s.push_back(original_file); // in index 0, used by the copy command
		v_o_s.push_back(original_file); // in index 1, used by the display command

		return v_o_s;

	}
}
