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
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Question 8
vector<string> RenameParsingStrategy::parse(string s) // s = <existing_file> <new_name_with_no_extension>
{
	
	vector<string> v_o_s;
	if (s.find(" ") == string::npos) {

		throw exception("not enough input");
		return v_o_s;
	}
	else
	{
		istringstream iss(s);
		string original_file;
		string renamed_file;
		iss >> original_file; // extract once to extract the original file name
		iss >> renamed_file; // extract twice to extract the renamed file name
		
		string temp = original_file + " " + renamed_file;
		v_o_s.push_back(temp); // in index 0, used by the copy command
		v_o_s.push_back(original_file); // in index 1, used by the remove command
		return v_o_s;
	}
}
