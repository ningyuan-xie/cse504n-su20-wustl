#pragma once
//  declare the CatDsStrategy class here

#include "CommandPrompt.h"
#include "AbstractParsingStrategy.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class AbstractFileSystem;
class AbstractFileFactory;
class AbstractCommand;

// Lab 5 -> Extra credit c.
class CatDsStrategy : public AbstractParsingStrategy {

public:
	virtual std::vector<std::string> parse(std::string);

};
