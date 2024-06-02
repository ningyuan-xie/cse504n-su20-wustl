
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

#include "common.h"
#include "game.h"

using namespace std;

// Define an insertion operator for TicTacToe (<<)
ostream& operator<< (ostream& o, const tictactoe_game& tg) {

	std::cout << endl;
	std::cout << "- Game Board -" << endl;
	std::cout << "--------------" << endl;

	// Step 7. Modify the handling of symbols for displaying game pieces
	// Step 9. Modify ostream<< to print the board out correctly (with numbers on y-axis)
	// first row needs to adjust one string right
	o << " " << tg.tall - 1 << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << endl;
	o << tg.tall - 2 << setw(tg.longest_display_string_length) << " " << tg.v_3[1] << " " << tg.v_3[2] << " " << tg.v_3[3] << " " << setw(tg.longest_display_string_length) << endl;
	o << tg.tall - 3 << setw(tg.longest_display_string_length) << " " << tg.v_2[1] << " " << tg.v_2[2] << " " << tg.v_2[3] << " " << setw(tg.longest_display_string_length) << endl;
	o << tg.tall - 4 << setw(tg.longest_display_string_length) << " " << tg.v_1[1] << " " << tg.v_1[2] << " " << tg.v_1[3] << " " << setw(tg.longest_display_string_length) << endl;
	o << tg.tall - 5 << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << " " << setw(tg.longest_display_string_length) << endl;

	// print out the number on x-axis
	o << " " << tg.wide - 5 << " " << tg.wide - 4 << " " << tg.wide - 3 << " " << tg.wide - 2 << " " << tg.wide - 1 << endl;
	std::cout << "--------------" << endl;

	return o;
}

// Step 11. Override the virtual print() method
void tictactoe_game::print() {
	cout << *this << endl;
}

// Define a public non-static done() method
bool tictactoe_game::done() {
	// horizontal
	if ((this->v_3[1] == "X" && this->v_3[2] == "X" && this->v_3[3] == "X") || (this->v_3[1] == "O" && this->v_3[2] == "O" && this->v_3[3] == "O")) {
		return true;
	}
	if ((this->v_2[1] == "X" && this->v_2[2] == "X" && this->v_2[3] == "X") || (this->v_2[1] == "O" && this->v_2[2] == "O" && this->v_2[3] == "O")) {
		return true;
	}
	if ((this->v_1[1] == "X" && this->v_1[2] == "X" && this->v_1[3] == "X") || (this->v_1[1] == "O" && this->v_1[2] == "O" && this->v_1[3] == "O")) {
		return true;
	}
	// vertical
	if ((this->v_3[1] == "X" && this->v_2[1] == "X" && this->v_1[1] == "X") || (this->v_3[1] == "O" && this->v_2[1] == "O" && this->v_1[1] == "O")) {
		return true;
	}
	if ((this->v_3[2] == "X" && this->v_2[2] == "X" && this->v_1[2] == "X") || (this->v_3[2] == "O" && this->v_2[2] == "O" && this->v_1[2] == "O")) {
		return true;
	}
	if ((this->v_3[3] == "X" && this->v_2[3] == "X" && this->v_1[3] == "X") || (this->v_3[3] == "O" && this->v_2[3] == "O" && this->v_1[3] == "O")) {
		return true;
	}
	// diagonal
	if ((this->v_3[1] == "X" && this->v_2[2] == "X" && this->v_1[3] == "X") || (this->v_3[1] == "O" && this->v_2[2] == "O" && this->v_1[3] == "O")) {
		return true;
	}
	if ((this->v_3[3] == "X" && this->v_2[2] == "X" && this->v_1[1] == "X") || (this->v_3[3] == "O" && this->v_2[2] == "O" && this->v_1[1] == "O")) {
		return true;
	}

	return false;
}

// Define a public non-static draw() method
bool tictactoe_game::draw() {

	if (game_count < 9 || this->done() == true) {
		return false;
	}
	else {
		return true;
	}
}

// Define a public non-static prompt() method
int game_base::prompt(unsigned int& x_coordinate, unsigned int& y_coordinate) {
	std::cout << "What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc." << endl;
	std::cout << "Input: ";

	string user_input;
START: cin >> user_input;

	// Check whether the input is "quit":
	if (user_input == "quit") {
		//std::cout << "User has asked to quit." << endl;	// I leave this line for debugging
		return prompt_enum::PROMPT_QUIT;
	}

	// Check whether the input has comma and has the correct size = 3 or 4 or 5:
	if (user_input.find(',') != string::npos && (user_input.size() == 3 || user_input.size() == 4 || user_input.size() == 5)) {
		replace(user_input.begin(), user_input.end(), ',', ' '); // find the comma and replace it with a space character
	}
	else {
		std::cout << "Please input in the format of <x,y>." << endl;
		std::cout << "Input: ";
		goto START;
	}

	istringstream iss_1(user_input); // transfer user's input into an input string stream

	size_t count = 0;
	while (iss_1) {					// iterate through the non-empty string. Standard input is (1,1)
		count += 1;

		if (count == 1) {
			iss_1 >> x_coordinate;
		}

		if (count == 2) {
			iss_1 >> y_coordinate;
			break;
		}
	}

	return prompt_enum::PROMPT_COMPLETED;
}

// Define a public non-static turn() method
int tictactoe_game::turn() {

	unsigned int int_x;
	unsigned int int_y;
	//size_t count = 0;

	string player_x = "Player X: ";
	string player_o = "Player O: ";

	while (this->done() != true && this->draw() != true) {

		this->game_count += 1;


		if (this->game_count % 2 != 0) {
			std::cout << "Now it's X's turn." << endl;

			ERROR_CONTROL_X: if (this->prompt(int_x, int_y) == prompt_enum::PROMPT_QUIT) { // test if the user wants to quit
				return turn_enum::TURN_QUIT;											   // user has typed <quit>
			}

			else {

				if (int_x > this->tall-2 || int_x < 1) {
					std::cout << "Please enter a x coordinate between 1 and 3. " << endl;
					goto ERROR_CONTROL_X;
				}
				if (int_y > this->wide-2 || int_y < 1) {
					std::cout << "Please enter a y coordinate between 1 and 3. " << endl;
					goto ERROR_CONTROL_X;
				}

				if (int_y == 1) {
					if (v_1[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_X;
					}
					else {
						v_1[int_x] = "X";
					}
				}
				if (int_y == 2) {
					if (v_2[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_X;
					}
					else {
						v_2[int_x] = "X";
					}
				}
				if (int_y == 3) {
					if (v_3[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_X;
					}
					else {
						v_3[int_x] = "X";
					}
				}

				// printing out the updated game board:
				std::cout << *this << endl;

				// printing out player X's past step:
				string player_x_moves = to_string(int_x) + ", " + to_string(int_y) + "; ";
				player_x += player_x_moves;
				std::cout << player_x << endl << endl;
			}

		}

		else {
			std::cout << "Now it's O's turn." << endl;

			ERROR_CONTROL_O: if (this->prompt(int_x, int_y) == prompt_enum::PROMPT_QUIT) { // test if the user wants to quit
				return turn_enum::TURN_QUIT;											   // user has typed <quit>
			}

			else {
				if (int_x > this->tall-2 || int_x < 1) {
					std::cout << "Please enter a x coordinate between 1 and 3. " << endl;
					goto ERROR_CONTROL_O;
				}
				if (int_y > this->wide-2 || int_y < 1) {
					std::cout << "Please enter a y coordinate between 1 and 3. " << endl;
					goto ERROR_CONTROL_O;
				}

				if (int_y == 1) {
					if (v_1[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_O;
					}
					else {
						v_1[int_x] = "O";
					}
				}
				if (int_y == 2) {
					if (v_2[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_O;
					}
					else {
						v_2[int_x] = "O";
					}
				}
				if (int_y == 3) {
					if (v_3[int_x] != " ") {
						std::cout << "This is not an empty square. Please choose an empty square." << endl;
						goto ERROR_CONTROL_O;
					}
					else {
						v_3[int_x] = "O";
					}
				}

				// printing out the game board:
				std::cout << *this << endl;

				// printing out player O's past step:
				string player_o_moves = to_string(int_x) + ", " + to_string(int_y) + "; ";
				player_o += player_o_moves;
				std::cout << player_o << endl << endl;
			}


		}

	}

	if (this->draw() == true) {			// test whether this game ends in draw
		return turn_enum::TURN_DRAW;
	}
	else {
		return turn_enum::TURN_COMPLETED;
	}

}

// Step 16. Modify the play() method to call the print() method
int game_base::play() {

	// Step 16. Modify the play() method to call the print() method
	this->print();

	int play_result = this->turn(); // In this step, turn() method will repeately call done() method and draw() method  

	// Situation (3)
	if (play_result == turn_enum::TURN_QUIT) {
		cout << this->game_count - 1 << " turn(s) were played, and user has asked to quit." << endl;
		return play_enum::PLAY_QUIT;
	}
	// Situation (1)
	else if (play_result == turn_enum::TURN_COMPLETED) {
		if (this->game_count % 2 != 0) {
			cout << "Player 1 has won the game!" << endl;
		}
		if (this->game_count % 2 == 0) {
			cout << "Player 2 has won the game!" << endl;
		}
		return play_enum::PLAY_SUCCESS;
	}
	// Situation (2)
	else if (play_result == turn_enum::TURN_DRAW) {
		cout << this->game_count << " turns were played, and no winning moves remain." << endl;
		return play_enum::PLAY_DRAW;
	}

	return 0;
}

// Step 17. Add a static method to the base class
game_base* game_base::check_argument(int argc, char* argv[]) {
	// First check that exactly one extra argument has been passed to the program
	if (argc == index_enum::expected_number_of_command_line_arguments) { // argc == 2
		string input_argument_name_1 = argv[index_enum::input_argument_name_1]; // argv[1]
		
		// Check that if the string in argv[1] is "TicTacToe"
		if (input_argument_name_1 == "TicTacToe") {

			cout << endl;
			cout << "You are now playing 'TicTacToe' created by Ningyuan Xie. Enjoy! " << endl;
			cout << "--------------------------------------------------------------- " << endl;

			game_base* T_Game = new tictactoe_game;
			return T_Game; // return the address of that object
		}
		
		// Step 21. Check that if the string in argv[1] is "Gomoku"
		else if (input_argument_name_1 == "Gomoku") {

			cout << endl;
			cout << "You are now playing 'Gomoku' created by Ningyuan Xie. Enjoy! " << endl;
			cout << "--------------------------------------------------------------- " << endl;

			game_base* G_Game = new gomoku_game(19, 5); // 1st default version of Gomoku
			return G_Game; // return the address of that object
		}
		
		else {
			game_base* T_Game = 0; // singular pointer
			return T_Game;
		}
	}

	// Extra Credit 1: Then check that exactly two extra argument has been passed to the program
	else if(argc == index_enum::input_argument_name_2) { // arc == 3
		
		string input_argument_name_1 = argv[index_enum::input_argument_name_1]; // argv[1]
		int input_argument_name_2 = stoi(argv[index_enum::expected_number_of_command_line_arguments]); // argv[2]

		// Check that if the string in argv[1] is still "Gomoku" and the extra argument is [3, 19]
		if (input_argument_name_1 == "Gomoku" && input_argument_name_2 >=3 && input_argument_name_2 <= 19) {

			cout << endl;
			cout << "You are now playing 'Gomoku' (arbitrary size) created by Ningyuan Xie. Enjoy! " << endl;
			cout << "----------------------------------------------------------------------------- " << endl;

			// Add a constraint: connecting number <= size
			if (input_argument_name_2 <= 5) {
				game_base* G_Game = new gomoku_game(input_argument_name_2, input_argument_name_2); // 2nd version of Gomoku
				return G_Game; // return the address of that object
			}
			else {
				game_base* G_Game = new gomoku_game(input_argument_name_2, 5); // 2nd version of Gomoku
				return G_Game; // return the address of that object
			}
		}

		else {
			game_base* T_Game = 0; // singular pointer
			return T_Game;
		}
	}

	// Extra Credit 2: Then check that exactly two extra argument has been passed to the program
	else if (argc == index_enum::input_argument_name_3) { // arc == 4

		string input_argument_name_1 = argv[index_enum::input_argument_name_1]; // argv[1]
		int input_argument_name_2 = stoi(argv[index_enum::expected_number_of_command_line_arguments]); // argv[2]
		int input_argument_name_3 = stol(argv[index_enum::input_argument_name_2]); // argv[3]

		// Check that if the string in argv[1] is still "Gomoku" and the extra arguments are [3, 19] and [3, 12]
		// Add a constraint: connecting number <= size
		if (input_argument_name_1 == "Gomoku" && input_argument_name_2 >= 3 && input_argument_name_2 <= 19 && input_argument_name_3 >= 3 && input_argument_name_3 <= 12 && input_argument_name_3 <= input_argument_name_2) {

			cout << endl;
			cout << "You are now playing 'Gomoku' (arbitrary size & arbitrary connecting number) created by Ningyuan Xie. Enjoy! " << endl;
			cout << "----------------------------------------------------------------------------------------------------------- " << endl;

			game_base* G_Game = new gomoku_game(input_argument_name_2, input_argument_name_3); // 3rd version of Gomoku
			return G_Game; // return the address of that object
		}

		else {
			game_base* T_Game = 0; // singular pointer
			return T_Game;
		}
	}


	else {
		game_base* T_Game = 0; // singular pointer
		return T_Game;
	}
}

// Extra Credit: Define a constructor for Gomoku
gomoku_game::gomoku_game(int i_1, int i_2): wide(i_1), tall(i_1), number_of_connecting_pieces_needed_to_win(i_2) {}

// Step 22. Define an insertion operator for Gomuku (<<)
ostream& operator<< (ostream& o, const gomoku_game& gg) {

	int row_count = 1;

	std::cout << endl;
	std::cout << "----------------------- Game Board ---------------------------" << endl;
	std::cout << "--------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < gg.tall; ++i) { // tall = 19
		
		// print out the number on x-axis
		if (row_count == 1) { // first row needs to adjust one string right
			o << setw(gg.longest_display_string_length) << gg.tall - i << setw(gg.longest_display_string_length);
		}
		else { // print out the number on y-axis
			o << gg.tall - i << setw(gg.longest_display_string_length);
		}
		
		// print out the main game 2D board in the middle
		for (unsigned int j = 0; j < gg.wide; ++j) {
			o << gg.board[i][j] << setw(gg.longest_display_string_length);
		}
		o << endl; // one row finished
		row_count += 1; // this is for debugging only
	}
	
	// print out the number on x-axis (bottom row)
	for (unsigned int j = 0; j <= gg.wide; ++j) { // wide = 19
		if (j == 0) { // according to the graph from the instruction: put an X at the lower-left corner
			o << "X" << setw(gg.longest_display_string_length); 
		}
		else { // print out the number on x-axis
			o << j << setw(gg.longest_display_string_length);
		}
	}
	o << endl;
	std::cout << "--------------------------------------------------------------" << endl;

	return o;
}

// Step 23. Override the virtual print() method
void gomoku_game::print() {
	cout << *this << endl;
}

// Step 24. Define a public non-static done() method
bool gomoku_game::done() {

	if (this->number_of_connecting_pieces_needed_to_win == 5) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j+1] == "B" && this->board[i][j+2] == "B" && this->board[i][j+3] == "B" && this->board[i][j+4] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall- (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W") {
					return true;
				}
			}
		}
	}

	// Extra Credit: Defining other winning conditions
	if (this->number_of_connecting_pieces_needed_to_win == 3) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 4) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 6) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 7) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 8) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B" && this->board[i][j + 7] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W" && this->board[i][j + 7] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B" && this->board[i + 7][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W" && this->board[i + 7][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B" && this->board[i + 7][j + 7] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W" && this->board[i + 7][j + 7] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B" && this->board[i + 7][j - 7] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W" && this->board[i + 7][j - 7] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 9) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B" && this->board[i][j + 7] == "B" && this->board[i][j + 8] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W" && this->board[i][j + 7] == "W" && this->board[i][j + 8] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B" && this->board[i + 7][j] == "B" && this->board[i + 8][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W" && this->board[i + 7][j] == "W" && this->board[i + 8][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B" && this->board[i + 7][j + 7] == "B" && this->board[i + 8][j + 8] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W" && this->board[i + 7][j + 7] == "W" && this->board[i + 8][j + 8] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B" && this->board[i + 7][j - 7] == "B" && this->board[i + 8][j - 8] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W" && this->board[i + 7][j - 7] == "W" && this->board[i + 8][j - 8] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 10) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B" && this->board[i][j + 7] == "B" && this->board[i][j + 8] == "B" && this->board[i][j + 9] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W" && this->board[i][j + 7] == "W" && this->board[i][j + 8] == "W" && this->board[i][j + 9] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B" && this->board[i + 7][j] == "B" && this->board[i + 8][j] == "B" && this->board[i + 9][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W" && this->board[i + 7][j] == "W" && this->board[i + 8][j] == "W" && this->board[i + 9][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B" && this->board[i + 7][j + 7] == "B" && this->board[i + 8][j + 8] == "B" && this->board[i + 9][j + 9] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W" && this->board[i + 7][j + 7] == "W" && this->board[i + 8][j + 8] == "W" && this->board[i + 9][j + 9] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B" && this->board[i + 7][j - 7] == "B" && this->board[i + 8][j - 8] == "B" && this->board[i + 9][j - 9] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W" && this->board[i + 7][j - 7] == "W" && this->board[i + 8][j - 8] == "W" && this->board[i + 9][j - 9] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 11) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B" && this->board[i][j + 7] == "B" && this->board[i][j + 8] == "B" && this->board[i][j + 9] == "B" && this->board[i][j + 10] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W" && this->board[i][j + 7] == "W" && this->board[i][j + 8] == "W" && this->board[i][j + 9] == "W" && this->board[i][j + 10] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B" && this->board[i + 7][j] == "B" && this->board[i + 8][j] == "B" && this->board[i + 9][j] == "B" && this->board[i + 10][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W" && this->board[i + 7][j] == "W" && this->board[i + 8][j] == "W" && this->board[i + 9][j] == "W" && this->board[i + 10][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B" && this->board[i + 7][j + 7] == "B" && this->board[i + 8][j + 8] == "B" && this->board[i + 9][j + 9] == "B" && this->board[i + 10][j + 10] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W" && this->board[i + 7][j + 7] == "W" && this->board[i + 8][j + 8] == "W" && this->board[i + 9][j + 9] == "W" && this->board[i + 10][j + 10] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B" && this->board[i + 7][j - 7] == "B" && this->board[i + 8][j - 8] == "B" && this->board[i + 9][j - 9] == "B" && this->board[i + 10][j - 10] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W" && this->board[i + 7][j - 7] == "W" && this->board[i + 8][j - 8] == "W" && this->board[i + 9][j - 9] == "W" && this->board[i + 10][j - 10] == "W") {
					return true;
				}
			}
		}
	}

	if (this->number_of_connecting_pieces_needed_to_win == 12) {
		// horizontal
		for (unsigned int i = 0; i < this->tall; ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i][j + 1] == "B" && this->board[i][j + 2] == "B" && this->board[i][j + 3] == "B" && this->board[i][j + 4] == "B" && this->board[i][j + 5] == "B" && this->board[i][j + 6] == "B" && this->board[i][j + 7] == "B" && this->board[i][j + 8] == "B" && this->board[i][j + 9] == "B" && this->board[i][j + 10] == "B" && this->board[i][j + 11] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i][j + 1] == "W" && this->board[i][j + 2] == "W" && this->board[i][j + 3] == "W" && this->board[i][j + 4] == "W" && this->board[i][j + 5] == "W" && this->board[i][j + 6] == "W" && this->board[i][j + 7] == "W" && this->board[i][j + 8] == "W" && this->board[i][j + 9] == "W" && this->board[i][j + 10] == "W" && this->board[i][j + 11] == "W") {
					return true;
				}
			}
		}
		// vertical
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j] == "B" && this->board[i + 2][j] == "B" && this->board[i + 3][j] == "B" && this->board[i + 4][j] == "B" && this->board[i + 5][j] == "B" && this->board[i + 6][j] == "B" && this->board[i + 7][j] == "B" && this->board[i + 8][j] == "B" && this->board[i + 9][j] == "B" && this->board[i + 10][j] == "B" && this->board[i + 11][j] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j] == "W" && this->board[i + 2][j] == "W" && this->board[i + 3][j] == "W" && this->board[i + 4][j] == "W" && this->board[i + 5][j] == "W" && this->board[i + 6][j] == "W" && this->board[i + 7][j] == "W" && this->board[i + 8][j] == "W" && this->board[i + 9][j] == "W" && this->board[i + 10][j] == "W" && this->board[i + 11][j] == "W") {
					return true;
				}
			}
		}
		// main diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = 0; j < this->wide - (number_of_connecting_pieces_needed_to_win - 1); ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j + 1] == "B" && this->board[i + 2][j + 2] == "B" && this->board[i + 3][j + 3] == "B" && this->board[i + 4][j + 4] == "B" && this->board[i + 5][j + 5] == "B" && this->board[i + 6][j + 6] == "B" && this->board[i + 7][j + 7] == "B" && this->board[i + 8][j + 8] == "B" && this->board[i + 9][j + 9] == "B" && this->board[i + 10][j + 10] == "B" && this->board[i + 11][j + 11] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j + 1] == "W" && this->board[i + 2][j + 2] == "W" && this->board[i + 3][j + 3] == "W" && this->board[i + 4][j + 4] == "W" && this->board[i + 5][j + 5] == "W" && this->board[i + 6][j + 6] == "W" && this->board[i + 7][j + 7] == "W" && this->board[i + 8][j + 8] == "W" && this->board[i + 9][j + 9] == "W" && this->board[i + 10][j + 10] == "W" && this->board[i + 11][j + 11] == "W") {
					return true;
				}
			}
		}
		// off diagonal
		for (unsigned int i = 0; i < this->tall - (number_of_connecting_pieces_needed_to_win - 1); ++i) {
			for (unsigned int j = (number_of_connecting_pieces_needed_to_win - 1); j < this->wide; ++j) {
				if (this->board[i][j] == "B" && this->board[i + 1][j - 1] == "B" && this->board[i + 2][j - 2] == "B" && this->board[i + 3][j - 3] == "B" && this->board[i + 4][j - 4] == "B" && this->board[i + 5][j - 5] == "B" && this->board[i + 6][j - 6] == "B" && this->board[i + 7][j - 7] == "B" && this->board[i + 8][j - 8] == "B" && this->board[i + 9][j - 9] == "B" && this->board[i + 10][j - 10] == "B" && this->board[i + 11][j - 11] == "B") {
					return true;
				}
				if (this->board[i][j] == "W" && this->board[i + 1][j - 1] == "W" && this->board[i + 2][j - 2] == "W" && this->board[i + 3][j - 3] == "W" && this->board[i + 4][j - 4] == "W" && this->board[i + 5][j - 5] == "W" && this->board[i + 6][j - 6] == "W" && this->board[i + 7][j - 7] == "W" && this->board[i + 8][j - 8] == "W" && this->board[i + 9][j - 9] == "W" && this->board[i + 10][j - 10] == "W" && this->board[i + 11][j - 11] == "W") {
					return true;
				}
			}
		}
	}

	return false;
}

// Step 25. Define a public non-static draw() method
bool gomoku_game::draw() {

	if (game_count < (this->wide * this->tall) || this->done() == true) {
		return false;
	}
	else {
		return true;
	}
}

// Step 27. Define a public non static turn() method
int gomoku_game::turn() {

	unsigned int int_x;
	unsigned int int_y;

	string player_black = "Player Black: ";
	string player_white = "Player White: ";

	while (this->done() != true && this->draw() != true) {

		this->game_count += 1;


		if (this->game_count % 2 != 0) {
			std::cout << "Now it's Black's turn." << endl;

			ERROR_CONTROL_B: if (this->prompt(int_x, int_y) == prompt_enum::PROMPT_QUIT) { // test if the user wants to quit
				return turn_enum::TURN_QUIT;											   // user has typed <quit>
			}

			else {
				if (int_x > this->tall || int_x < 1) {
					std::cout << "Please enter a x coordinate between 1 and " << tall << ". " << endl;
					goto ERROR_CONTROL_B;
				}
				else if (int_y > this->wide || int_y < 1) {
					std::cout << "Please enter a y coordinate between 1 and " << wide << ". " << endl;
					goto ERROR_CONTROL_B;
				}
				else if (this->board[this->tall - int_y][int_x - 1] != " ") {
					std::cout << "This is not an empty square. Please choose an empty square." << endl;
					goto ERROR_CONTROL_B;
				}
				else {
					this->board[this->tall - int_y][int_x - 1] = this->game_piece_1;
				}
				
				// printing out the updated game board:
				std::cout << *this << endl;

				// printing out player black's past step:
				string player_black_moves = to_string(int_x) + ", " + to_string(int_y) + "; ";
				player_black += player_black_moves;
				std::cout << player_black << endl << endl;
			}

		}

		else {
			std::cout << "Now it's White's turn." << endl;

			ERROR_CONTROL_W: if (this->prompt(int_x, int_y) == prompt_enum::PROMPT_QUIT) { // test if the user wants to quit
				return turn_enum::TURN_QUIT;											   // user has typed <quit>
			}

			else {
				if (int_x > this->tall || int_x < 1) {
					std::cout << "Please enter a x coordinate between 1 and 19. " << endl;
					goto ERROR_CONTROL_W;
				}
				else if (int_y > this->wide || int_y < 1) {
					std::cout << "Please enter a y coordinate between 1 and 19. " << endl;
					goto ERROR_CONTROL_W;
				}
				else if (this->board[this->tall - int_y][int_x - 1] != " ") {
					std::cout << "This is not an empty square. Please choose an empty square." << endl;
					goto ERROR_CONTROL_W;
				}
				else {
					this->board[this->tall - int_y][int_x - 1] = this->game_piece_2;
				}

				// printing out the game board:
				std::cout << *this << endl;

				// printing out player O's past step:
				string player_white_moves = to_string(int_x) + ", " + to_string(int_y) + "; ";
				player_white += player_white_moves;
				std::cout << player_white << endl << endl;
			}

		}

	}

	if (this->draw() == true) {			// test whether this game ends in draw
		return turn_enum::TURN_DRAW;
	}
	else {
		return turn_enum::TURN_COMPLETED;
	}

}