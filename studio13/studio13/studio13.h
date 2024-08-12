
#pragma once

class detector
{
public:
	detector();
	~detector();

private:
	unsigned int x;
	// static: Shared across all instances of a class; maintains a single shared state for all objects of the class.
	static unsigned int y;
};