#pragma once
//  declare the RenameParsingStrategy class here

#include "CommandPrompt.h"
#include "AbstractParsingStrategy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Lab 5 -> Question 8
class RenameParsingStrategy : public AbstractParsingStrategy {

public:
	virtual std::vector<std::string> parse(std::string);

};
