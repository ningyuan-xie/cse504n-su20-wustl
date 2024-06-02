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

// Step 11. Define a function to read the dimensions of a game board
int read_dimensions(ifstream& ifs, unsigned int& columns, unsigned int& rows) {
	
	if (!ifs.is_open()) {
		cout << "File open failed; no matching file was found. " << endl; // helpful error message indicating the problem
		return read_dimension::dimension_open_failed;				      // return the appropriate enumeration label
	}

	if (ifs.is_open()) {
		cout << "File is successfully opened!" << endl;

		string line_1;						// format: 3 3
		size_t success_time = 0;			// initialize success time = 0
		
		// extract a line until it is not empty
		while (line_1.empty()) {
			getline(ifs, line_1); 			// extract a line
		}
		success_time += 1;					// success time = 1
		
		size_t count = 0;					// initialize count = 0
		if (!line_1.empty()) {				// ignore empty strings
			istringstream iss_1(line_1);	// Push formatted values into stream

			while (iss_1) {					// iterate through the non-empty string
				count += 1;					// count = 1
				
				if (count == 1) { // 1st parameter: columns
					iss_1 >> columns;
					cout << "Columns = " << columns << endl; // extract a value into the 1st unsigned integer
					success_time += 1; // success time = 2
				}
				
				if (count == 3) { // 2nd parameter: rows
					iss_1 >> rows;
					cout << "Rows = " << rows << endl; // extract a value into the 2nd unsigned integer
					success_time += 1; // success time = 3
					break;
				}
			}
		}

		// summary whether the extraction is successful or not
		if (success_time == 3) {
			cout << "Dimension extraction successfully completed!" << endl;
			cout << endl;
			return read_dimension::extract_dimensions_success;
		}

		else {
			cout << "Cannot extract dimensions." << endl;
			cout << endl;
			return read_dimension::cannot_extract_dimensions;
		}

		return read_dimension::cannot_extract_dimensions;
	}

	return read_dimension::cannot_extract_dimensions;

}


// Step 12. Define a function to read the subsequent lines of a game board
int read_subsequent_lines(ifstream& ifs, vector<Game_Piece>& v_gamepiece, unsigned int& columns, unsigned int& rows) {

	int program_success_or_not = 0;

	//string name_of_the_file_1 = "tic-tac-toe.txt";
	//string name_of_the_file_2 = "gomoku.txt";
	//ifs.open(name_of_the_file_1);

	if (!ifs.is_open()) {
		cout << "File open failed; no matching file was found. " << endl; // helpful error message indicating the problem
		return read_subsequent_lines::subsequent_open_failed;										  // return the appropriate enumeration label
	}

	else if (ifs.is_open()) {
		cout << "File is successfully opened!" << endl;

		string line_1;

		LOOP: while (getline(ifs, line_1)) {			// getline will return false when it cannot extract another string from the file
		size_t count = 0;			// initialize count as index through the non-empty string
		size_t success_time = 0;	// initialize success time through the non-empty string

		string color_of_the_game_piece;		// 1
		string name_of_the_game_piece;		// 2
		string displayed_game_piece;		// 3
		unsigned int horizontal_position;	// 4
		unsigned int vertical_position;		// 5

		piece_color converted_color_value;			// 1.1
		int index_of_vector;				// columns * y + x

		if (!line_1.empty()) {				// ignore empty strings

			cout << "New Line starts here: " << endl;
			istringstream iss_1(line_1);

			while (iss_1) { // iterate through the non-empty string
				// ignore the dimension part
				if (isdigit(line_1[0])) {
					goto LOOP;
				}
				count += 1; // count increases by 1 as we iterate through the string
				
				// extract 1st value
				if (count == 1) {
					iss_1 >> color_of_the_game_piece;
					cout << "Color = " << color_of_the_game_piece << endl;
					success_time += 1;

					converted_color_value = color_element_function(color_of_the_game_piece);
					cout << "Converted value: " << converted_color_value << endl;
					if (converted_color_value == piece_color::invalid_color) {
						cout << "Skip this line." << endl;
						cout << endl;
						goto LOOP; // skip over this line and continue to process subsequent lines
					}
				}

				// extract 2nd value
				if (count == 3) {
					iss_1 >> name_of_the_game_piece;
					cout << "Name = " << name_of_the_game_piece << endl;
					success_time += 1;
				}

				// extract 3rd value
				if (count == 5) {
					iss_1 >> displayed_game_piece;
					cout << "Displayed = " << displayed_game_piece << endl;
					success_time += 1;
				}

				// extract 4th value x
				if (count == 7) {
					iss_1 >> horizontal_position;
					cout << "Horizontal position = " << horizontal_position << endl;
					success_time += 1;

					if (horizontal_position >= columns) {
						cout << "Game piece beyond columns; skip this line." << endl;
						cout << endl;
						goto LOOP; // skip over this line and continue to process subsequent lines
					}
				}

				// extract 5th value y
				if (count == 9) {
					iss_1 >> vertical_position;
					cout << "Vertical position = " << vertical_position << endl;
					success_time += 1;

					if (vertical_position >= rows) {
						cout << "Game piece beyond rows; skip this line." << endl;
						cout << endl;
						goto LOOP; // skip over this line and continue to process subsequent lines
					}

				}

				// Summarize success or not
				if (count == 9 && success_time < 5) { // five values were successfully extracted
					cout << "Not enough success times; skip this line." << endl;
					cout << endl;
					goto LOOP; // skip over this line and continue to process subsequent lines
				}

				// The Game piece is well formed; finished this line
				if (count == 9) {
					Game_Piece Game_Piece_In_This_Line(converted_color_value, name_of_the_game_piece, displayed_game_piece);
					index_of_vector = columns * vertical_position + horizontal_position; // width * row (y) + column (x)
					v_gamepiece[index_of_vector] = Game_Piece_In_This_Line;				 // For the game piece at that index in the vector

					cout << "The Game piece is well formed; index is " << index_of_vector << "; finished this Line. " << endl;
					cout << endl;
					program_success_or_not += 1;

					goto LOOP;
				}

			}

		}

	}

		if (program_success_or_not > 0) {
			cout << "Extraction completed." << endl;
			return read_subsequent_lines::extract_subsequent_success;
		}
	
	}
	
	return read_subsequent_lines::cannot_extract_subsequent;
}


// Step 13. Define a function to print out the pieces on a game board
int print_game_board(vector<Game_Piece>& v_gamepiece, unsigned int& columns, unsigned int& rows) {

	int printing_success = 0;

	cout << endl;
	cout << "----------- Game Board -----------" << endl;
	cout << "----------------------------------" << endl;
	// print a vector of game piece into a 2D game board
	for (int i = rows - 1; i >= 0; --i) {			 // print out the y dimension in descending order; each i prints out a new row
		for (unsigned int j = 0; j < columns; ++j) { // print out the x dimension in ascending order; each j prints out a new column
			int index = columns * i + j;			 // width * row (y) + column (x)

			//cout << "[Game_Piece (" << index << ") color: " << color_name_function(v_gamepiece[index].enumerated_type) << "; name: " << v_gamepiece[index].name_of_the_piece << "; display: " << v_gamepiece[index].display_of_the_piece << "] ";
			cout << v_gamepiece[index].display_of_the_piece << " "; // display is either X or O or empty square from main

			printing_success += 1;
		}
		// two empty lines here for new row on the game board
		cout << endl;
		cout << endl;
	}
	cout << "-----------------------------------" << endl;

	if (printing_success == 0) {
		return print_game_board::print_game_board_failed;
	}
	else {
		return print_game_board::print_game_board_success;
	}
}


