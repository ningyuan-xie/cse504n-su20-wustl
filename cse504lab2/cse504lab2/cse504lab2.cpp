// cse504lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include "game_board.h"
#include "game_pieces.h"

#include "Extra_Credit.h"

using namespace std;


// Step 14. Implement the main function for Lab 2
int main(int argc, char* argv[])
{	
	// Step 14.1: check that exactly one argument has been passed to it
	int g_argc; // use argc as global variable
	g_argc = argc; // use argc as global variable

	if (g_argc != index::expected_number_of_command_line_arguments) {
		usage_message_function(argv[program_name], " <input_file_name>");
		return open::no_file_name_given;
	}

	// Step 14.2: Use the argument passed to the program to construct and open an input file stream
	string name_of_the_file = argv[index::input_file_name];
	ifstream ifs_main;
	ifs_main.open(name_of_the_file);

	if (!ifs_main.is_open()) {
		cout << "File open failed; no matching file was found. " << endl; // print out error message
		return open::file_open_failed;
	}

	// Step 14.3: Declared two unsigned integers and extract the game board dimensions
	unsigned int width_of_the_game_board;
	unsigned int height_of_the_game_board;
	read_dimensions(ifs_main, width_of_the_game_board, height_of_the_game_board); 
	// these integers will be defined from the "read_dimensions" function

	// Step 14.4: Declare a vector of game pieces, and push back empty game pieces
	vector<Game_Piece> vector_of_game_pieces;
	Game_Piece Empty_Square(piece_color::no_color, " ", " "); // empty game pieces

	// Repeatedly puch back empty square on the board
	for (unsigned int i = 0; i < width_of_the_game_board * height_of_the_game_board; ++i) {
		vector_of_game_pieces.push_back(Empty_Square);
	}

	// Read the subsequent lines (game pieces) from the game board
	read_subsequent_lines(ifs_main, vector_of_game_pieces, width_of_the_game_board, height_of_the_game_board);

	// Step 14.5: Prints out the game board
	print_game_board(vector_of_game_pieces, width_of_the_game_board, height_of_the_game_board);

	// ------------------------------------------------------------------------------------------------------------------------
	// ------------------------------------------------------------------------------------------------------------------------

	// Step 21: Call the new function "print_game_board_Extra" and print out game pieces and their neighbors
	print_game_board_Extra(vector_of_game_pieces, width_of_the_game_board, height_of_the_game_board);

	return open::success;
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
