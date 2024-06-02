#pragma once

class Name {

public: // member functions
	Name(); // default constructor
	Name(const Name&); // copy constructor
	int getX() const; // accessor x
	int getY() const; // accessor y
	Name& setX(int); // setter x
	Name& setY(int); // setter y

private: // member variables
	//Name();
	int x;
	int y;
};

Name byValue(Name);
Name& byReference(Name&);