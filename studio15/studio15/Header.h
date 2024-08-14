#pragma once
#pragma once

class detector
{
public:
	detector();
	~detector();
	static unsigned int y;

private:
	unsigned int x;
};


class wrapper {
	
public:
	wrapper(); // default constructor
	~wrapper(); // destructor
	
	wrapper(const wrapper& p); // Copy constructor
	wrapper& operator= (const wrapper& p); // Copy-Assignment operator=

	wrapper(wrapper&& p); // Move constructor 
	wrapper& operator= (wrapper&& p); // Move-Assignment operator=

private:
	detector* p_d; // a private member variable that is a pointer to an object of the detector class type
	bool b_m_v; // a Boolean member variable, only needed for shallow copy
};
