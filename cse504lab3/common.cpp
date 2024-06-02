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

using namespace std;

// Define a helpful "usage message" function
int usage_message_function(string const s1, string const s2) {

	cout << "usage: " << s1 << " " << s2 << endl;
	cout << "usage(auto player): " << s1 << " " << s2 << " " << "<auto_player>" << endl;

	return open_enum::no_argument_name_given; // returns the enumeration label corresponding to the failure return value 
											  // for having the wrong number of command line arguments
}