#pragma once

#include "game_pieces.h"

using namespace std;

// Step 11. Declare a function to read the dimensions of a game board
int read_dimensions(ifstream& ifs, unsigned int& i_1, unsigned int& i_2);

// Step 11. Declare an enumeration for different success and failure values for "read_dimenstion"
enum read_dimension { extract_dimensions_success = 0, dimension_open_failed = 1, cannot_extract_dimensions = 2 };


// Step 12. Declare a function to read the subsequent lines of a game board
int read_subsequent_lines(ifstream& ifs, vector<Game_Piece>& v_gamepiece, unsigned int& columns, unsigned int& rows);

// Step 12. Declare an enumeration for different success and failure values for "read_subsequent_lines"
enum read_subsequent_lines { extract_subsequent_success = 0, subsequent_open_failed = 1, cannot_extract_subsequent = 2 };


// Step 13. Declare a function to print out the pieces on a game board a game board
int print_game_board(vector<Game_Piece>& v_gamepiece, unsigned int& columns, unsigned int& rows);

// Step 13. Declare an enumeration for different success and failure values for "print_game_board"
enum print_game_board { print_game_board_success = 0, print_game_board_failed = 1 };


