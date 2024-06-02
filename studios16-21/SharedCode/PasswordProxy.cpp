//  Define the PasswordProxy class here

#include "AbstractFile.h"
#include "PasswordProxy.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Studio 20 -> Question 2

// c. a constructor takes in a pointer to an AbstractFile and a string representing password
PasswordProxy::PasswordProxy(AbstractFile* p, std::string s): pointer_to_an_abstractfile(p), password(s) {}


// d. a destructor that deletes the pointer to the real file
PasswordProxy::~PasswordProxy() {

	delete this->pointer_to_an_abstractfile;

}


// e. a protected method passwordPrompt that returns a string
string PasswordProxy::passwordPrompt( ) {
	
	string result;
	cin >> result;

	return result;
}


 // f. a helper function checking whether a string matches the password member variable
bool PasswordProxy::helper_check(string s) {

	if (s == this->password) {
		return true;
	}
	else {
		return false;
	}
}


// Studio 20 -> Question 3

// a. read
vector<char> PasswordProxy::read() {

	// prompt the user for password using passwordPrompt
	string user_input_password = passwordPrompt(); 

	// if the password is correct
	if (helper_check(user_input_password) == true) {
		
		// return the results of calling read on the actual txt/img file
		return this->pointer_to_an_abstractfile->read();
	}

	// if the password is wrong
	else {

		// return an empty vector
		//cout << "Wrong password!" << endl;
		vector<char> empty_vector = {};
		return empty_vector; 
	}

}


// b. write
int PasswordProxy::write(std::vector<char> v) {

	// prompt the user for password using passwordPrompt
	string user_input_password = passwordPrompt();

	// if the password is correct
	if (helper_check(user_input_password) == true) {

		// return the resuls of calling write on the actual txt/img file
		return this->pointer_to_an_abstractfile->write(v);
	}

	// if the password is wrong
	else {

		// return a unique non-zero error value
		//cout << "Wrong password!" << endl;
		return 1;
	}

}


// c. append
int PasswordProxy::append(std::vector<char> v) {

	// prompt the user for password using passwordPrompt
	string user_input_password = passwordPrompt();

	// if the password is correct
	if (helper_check(user_input_password) == true) {

		// return the resuls of calling append on the actual txt/img file
		return this->pointer_to_an_abstractfile->append(v);
	}

	// if the password is wrong
	else {

		// return a unique non-zero error value
		return 1;
	}

}


// d. getSize
unsigned int PasswordProxy::getSize() {

	// return the results of calling getSize on the private member variable
	return this->pointer_to_an_abstractfile->getSize(); 
}


// e. getName
string PasswordProxy::getName() {
	
	// return the results of calling getName on the private member variable
	return this->pointer_to_an_abstractfile->getName(); 
}


// f. accept
void PasswordProxy::accept(AbstractFileVisitor* AFV) {

	// prompt the user for password using passwordPrompt
	string user_input_password = passwordPrompt();

	// if the password is correct
	if (helper_check(user_input_password) == true) {
		
		// call accept on the actual file
		this->pointer_to_an_abstractfile->accept(AFV);
	}	

}

// Lab 5 -> Question 6.
AbstractFile* PasswordProxy::clone(string s) {

	AbstractFile* temp = pointer_to_an_abstractfile->clone(s);  // Fix clone password
	return new PasswordProxy(temp, password);

}


