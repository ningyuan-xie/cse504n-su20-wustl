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

// Step 8. Define a function that transfer "enum piece_color color" to "string color"
string color_name_function(piece_color i) {
	string color;

	if (i == piece_color::red) {
		color = "red";
	}
	if (i == piece_color::black) {
		color = "black";
	}
	if (i == piece_color::white) {
		color = "white";
	}
	if (i == piece_color::invalid_color) {
		color = "invalid color";
	}
	if (i == piece_color::no_color) {
		color = "no color";
	}

	return color;
}

// Step 9. Define a function that transfers "string color" to "enum piece_color color"; used while reading strings from input file in Step 12 to build struct <Game_Piece>
piece_color color_element_function(string& s) {

	// finds the first character in the string s that is not contained in the string "\t\n "
	if (s.find_first_not_of("\t\n ") == string::npos) { // string::npos = "not found"
		cout << "This is an empty string." << endl; // If there are no such characters, it means the string consists only of whitespace
		return piece_color::no_color;
	}
	else if (s == "red") {
		return piece_color::red;
	}
	else if (s == "black") {
		return piece_color::black;
	}
	else if (s == "white") {
		return piece_color::white;
	}
	else {
		cout << "This is an invalid color." << endl;
		return piece_color::invalid_color;
	}
}

// Step 10. Define a struct to represent a game piece
Game_Piece::Game_Piece(piece_color a, string b, string c)
	: enumerated_type(a), name_of_the_piece(b), display_of_the_piece(c)
{
	cout << "constructed a Game_Piece with color " << a << " with name " << b << " and display " << c << endl;
}

