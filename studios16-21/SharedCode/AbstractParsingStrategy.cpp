//  define the MacroCommand class here

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
#include "MacroCommand.h"
#include "AbstractParsingStrategy.h"
#include "Enum.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Lab 5 -> Question 7
vector<string> AbstractParsingStrategy::parse(string s) {

	vector<string> v_o_s;

	//for (auto i = 0; i < s.size(); ++i) {
	//	v_o_s.push_back(i);
	//}

	return v_o_s;
}
