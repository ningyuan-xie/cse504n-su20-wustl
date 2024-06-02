#pragma once
// declare the AbstractParsingStrategy interface here

#include "CommandPrompt.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

// Lab 5 -> Question 7
class AbstractParsingStrategy {

public:
	virtual std::vector<std::string> parse(std::string) = 0;
};
