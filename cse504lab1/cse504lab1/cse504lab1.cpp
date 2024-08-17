// cse504lab1.cpp : This file contains the 'main' function and two of my defined functions. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Step 8. Include the header file in my main program source file
#include "headerEnum.h" // "" means self-created header file; copy and paste all the content

using namespace std;
using namespace two_enum;


// Step 9. Declare and define a function for parsing an input file; I use global variable of main so I declare the function at main
int g_argc; // use argc as global variable

int parsing_function(vector<string>& v, char* argv[]) {
	
	//---------------------------- function starts here ----------------------------
	
	if (g_argc != expected_number_of_command_line_arguments) {
		cout << "No file name given; please enter a file name." << endl; // helpful error message indicating the problem
		return no_file_name_given;										 // return the appropriate enumeration label
	}
	
	string name_of_the_file = argv[input_file_name];
	
	// Option 1: use absolute path, when the txt file is in the same directory as source file .cpp
	//string open_name_of_the_file = "H:\\CSE_504N_Lab1\\cse504lab1\\cse504lab1\\" + name_of_the_file; 

	// Option 2: use relative path, when the txt file is in the same directory as source file .cpp
	//string open_name_of_the_file = "..\\cse504lab1\\"+ name_of_the_file;

	// Option 3: txt file is in the same directory as exe file
	string open_name_of_the_file = name_of_the_file;

	ifstream ifs;
	ifs.open(open_name_of_the_file);

	if (!ifs.is_open()) {
		cout << "File open failed; no matching file was found. " << endl; // helpful error message indicating the problem
		return file_open_failed;										  // return the appropriate enumeration label
	}

	else if (ifs.is_open()) {
		cout << "File is successfully opened!" << endl;

		string line_1;							// declares a string variable used to store each line read from the file			   
		while (getline(ifs, line_1)) {			// getline reads one line at a time from the stream (ifs) and stores it in line_1
												// getline will return false when it cannot extract another string from the file
			if (!line_1.empty()) {				// ignore empty strings
				v.push_back(line_1);			// push back the string into the vector that was passed as the first parameter
			}
		}
		cout << "Extraction completed." << endl;
		return success;
	}

	else {
		return success;
	}
	
	//---------------------------- function ends here ----------------------------
}


// Step 10. Declare and define a helpful "usage message" function. I declare it at main because it only serves as a "instruction".
int usage_message_function(string const s) {
	
	cout << "usage: " << s << " <input_file_name>" << endl;

	return no_file_name_given; // returns the enumeration label corresponding to the failure return value 
							   // for having the wrong number of command line arguments
}


// Step 11.1 Modify the signature of main function
int main(int argc, char* argv[])
{
	g_argc = argc; // use argc as global variable

	// Step 11.2: check that exactly one argument has been passed to it
	if (g_argc != expected_number_of_command_line_arguments) {
		usage_message_function(argv[program_name]);
		
		return no_file_name_given;
	}

	// Step 11.3: declare a vector of C++ stype strings of type vector<string> as parameter for parsing function
	vector<string> vector_of_string;

	// and pass that vector and the first program argument to the function that parses the input file
	if (parsing_function(vector_of_string, argv) == file_open_failed) { // if the function returns an enumeration value other than success
		return file_open_failed;
	} // parsing_function will run once in the if-statement, so by this point "vector_of_string" is already filled
	
	// Step 11.4: declare a vector of integers of type vector<int> to store the integers that are extracted from the strings
	vector<int> vector_of_int;
	
	// iterate through the vector of strings
	cout << " " << endl;
	cout << "-------------------------" << endl;
	cout << "vector_of_string's output: " << endl;
	cout << " " << endl;
	for (size_t s = 0; s < vector_of_string.size(); ++s) {
		string string_in_vector = vector_of_string[s]; // every single string in "vector_of_string"

		size_t count = 0;										// initialize count
		for (size_t i = 0; i < string_in_vector.size(); ++i) {	// iterate through every char of the string
			
			if (isdigit(string_in_vector[i])) {					// test each one to see if it contains only numeric digit characters 
				count += 1;
			}
		}

		// Case 1: string contains only numeric digit characters
		if (count == string_in_vector.size()) {				
			count = 0;										// initialize count
			istringstream iss(string_in_vector);			// wrap the string in an input string stream
			int converted_integer;
			iss >> converted_integer;						// use the stream's extraction (>>) operator to convert it to an integer

			vector_of_int.push_back(converted_integer);		// push that integer back into the vector of integers
		}

		// Case 2: For each string that contains any other (non-digit) characters, print the string to the standard output stream.
		else {
			count = 0;										// initialize count

			// print the string to the standard output stream
			cout << string_in_vector << endl;				
		}
		
	}
	cout << "-------------------------" << endl;
	cout << "  " << endl;

	// Step 11.5: Then, iterate through the vector of integers and print out each integer in it
	cout << " " << endl;
	cout << "-------------------------" << endl;
	cout << "vector_of_int's output: " << endl;
	cout << " " << endl;
	
	for (size_t s = 0; s < vector_of_int.size(); ++s) {
		cout << vector_of_int[s] << endl;
	}
	
	cout << "-------------------------" << endl;
	cout << "  " << endl;

	// Step 11.6: The program return an enumeration label (that has value 0) to indicate success
	return success;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
