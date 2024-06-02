// cse504lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

#include "common.h"
#include "game.h"

using namespace std;

// Step 7.
int main(int argc, char* argv[])
{	
	// Step 7.1
	int g_argc;
	g_argc = argc; // use argc as global variable

	// Check whether the user has input something
	if (g_argc < index_enum::expected_number_of_command_line_arguments) {		// argc < 2
		usage_message_function(argv[index_enum::program_name], "<TicTacToe>");
		return open_enum::no_argument_name_given;
	}

	// Initialize the 1st input
	string input_argument_name_1 = argv[index_enum::input_argument_name_1]; // argv[1]
	
	// Initialize the 2nd input
	string input_argument_name_2;
	if (g_argc == index_enum::input_argument_name_2) { // argc == 3
		input_argument_name_2 = argv[index_enum::expected_number_of_command_line_arguments]; // argv[2]
	}

	// Check the 1st input to see if it is "TicTacToe"
	if (input_argument_name_1 != "TicTacToe") {
		usage_message_function(argv[program_name], " <TicTacToe>");
		return open_enum::wrong_argument_name_given;
	}
	// If it exists, check the 2nd input to see if it is "auto_player"
	else if (g_argc == index_enum::input_argument_name_2 && input_argument_name_2 != "auto_player") {
		usage_message_function(argv[program_name], " <TicTacToe>");
		return open_enum::wrong_argument_name_given;
	}
	else {
		cout << endl;
		cout << "You are now playing 'TicTacToe' created by Ningyuan Xie. Enjoy! " << endl;
		cout << "--------------------------------------------------------------- " << endl;
	}
	
	// Step 7.2 Declare an object of the TicTacToe
	tictactoe_game Game;
	int main_result;

	if (g_argc == 2) {
		cout << "You chose version 1 (manual) of the game. " << endl;
		cout << "----------------------------------------- " << endl;

		// Step 7.3 Call the object's play() method, and use the result returned as the program's return value
		main_result = Game.play();
	}
	else {
		cout << "You chose version 2 (auto player) of the game. " << endl;
		cout << "---------------------------------------------- " << endl;

		main_result = Game.play_auto();
	}
	
	// Step 7.4 Check for non-zero values returned, and return an appropraite unique non-zero value
	if (main_result == play_enum::PLAY_SUCCESS) {
		return 0;
	}
	else if (main_result == play_enum::PLAY_DRAW) {
		return main_enum::MAIN_DRAW;
	}
	else {
		return main_enum::MAIN_QUIT;
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
