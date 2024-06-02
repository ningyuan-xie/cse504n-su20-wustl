// cse504lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include <iomanip>
#include <memory>

#include "common.h"
#include "game.h"

using namespace std;

// Step 18. Modify main program
int main(int argc, char* argv[])
{	
	
	game_base* pointer_returned = game_base::check_argument(argc, argv);
	int main_result;

	if (pointer_returned == 0) {
		main_result = usage_message_function(argv[index_enum::program_name], "<TicTacToe>or<Gomoku> <3-19>(extra) <3-12>(extra)");
		delete pointer_returned;
		return main_result;
	}
	else {
		main_result = pointer_returned->play();
		delete pointer_returned;
		return main_result; // If success, return play_enum::PLAY_SUCCESS = 0
	}

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
