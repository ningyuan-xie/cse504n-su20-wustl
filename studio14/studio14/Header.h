#pragma once

class detector
{
public:
	detector();
	~detector();

private:
	unsigned int x;
	static unsigned int y;
};

class wrapper {
public:
	wrapper(); // default constructor
	~wrapper(); // destructor
	wrapper(const wrapper& p); // copy constructor

private:
	detector* p_d; // a private member variable that is a pointer to an object of the detector class type
	bool b_m_v; // a Boolean member variable, only used by default constructor

};