#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

#include "common.h"
#include "game_board.h"
#include "game_pieces.h"

using namespace std;

// Step 5. Define a helpful "usage message" function
int usage_message_function(string const s1, string const s2 = " <input_file_name>") {

	cout << "usage: " << s1 << s2 << endl;

	return no_file_name_given; // returns the enumeration label corresponding to the failure return value 
							   // for having the wrong number of command line arguments
}

// Step 6. Define a lower_case function
string lower_case_function(string s) {

	string result;
	for (auto i : s) {
		if (i >= 65 && i <= 92) { // Check for uppercase letters
			i += 32;			  // Convert to lowercase by adding the ASCII difference
		}
		result.push_back(i);
	}

	return result;
}