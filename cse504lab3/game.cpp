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

// Step 6.4 Define an insertion operator (<<)
ostream& operator<< (ostream& o, const tictactoe_game& tg) {
	
	std::cout << endl;
	std::cout << "- Game Board -" << endl;
	std::cout << "--------------" << endl;
	o << tg.tall - 1 << tg.v_4[0] << " " << tg.v_4[1] << " " << tg.v_4[2] << " " << tg.v_4[3] << " " << tg.v_4[4] << endl;
	o << tg.tall - 2 << tg.v_3[0] << " " << tg.v_3[1] << " " << tg.v_3[2] << " " << tg.v_3[3] << " " << tg.v_3[4] << endl;
	o << tg.tall - 3 << tg.v_2[0] << " " << tg.v_2[1] << " " << tg.v_2[2] << " " << tg.v_2[3] << " " << tg.v_2[4] << endl;
	o << tg.tall - 4 << tg.v_1[0] << " " << tg.v_1[1] << " " << tg.v_1[2] << " " << tg.v_1[3] << " " << tg.v_1[4] << endl;
	o << tg.tall - 5 << tg.v_0[0] << " " << tg.v_0[1] << " " << tg.v_0[2] << " " << tg.v_0[3] << " " << tg.v_0[4] << endl;

	o << " " << tg.wide - 5 << " " <<  tg.wide - 4 << " " <<  tg.wide - 3 << " " << tg.wide - 2 << " " << tg.wide-1 << endl;
	std::cout << "--------------" << endl;

	return o;
}


// Step 6.5 Define a public non-static done() method
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


// Step 6.6 Define a public non-static draw() method
bool tictactoe_game::draw() {

	if (game_count < 9 || this->done() == true) {
		return false;
	}
	else {
		return true;
	}
}


// Step 6.7 Define a public non-static prompt() method
int tictactoe_game::prompt(unsigned int& x_coordinate, unsigned int& y_coordinate) {
	std::cout << "What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc." << endl;
	std::cout << "Input: ";
	
	string user_input;
	START: cin >> user_input;

	// Check whether the input is "quit":
	if (user_input == "quit") {
		//std::cout << "User has asked to quit." << endl;	// I leave this line for debugging
		return prompt_enum::PROMPT_QUIT;
	}
	
	// Check whether the input has comma and has the correct size = 3:
	if (user_input.find(',') != string::npos && user_input.size()==3) {
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
			
			if (x_coordinate > 3 || x_coordinate < 1) {
				std::cout << "Please enter a x coordinate between 1 and 3. " << endl;
				std::cout << "Input: ";
				goto START; // return to the beginning of the function
			}

			//cout << "x is " << x_coordinate << "; "<< endl; // I leave this line for debugging
		}

		if (count == 2) {
			iss_1 >> y_coordinate;

			if (y_coordinate > 3 || y_coordinate < 1) {
				std::cout << "Please enter a y coordinate between 1 and 3. " << endl;
				std::cout << "Input: ";
				goto START; // return to the beginning of the function
			}

			//cout << "y is " << y_coordinate << "; " << endl; // I leave this line for debugging
			break;
		}
	}
	
	return prompt_enum::PROMPT_COMPLETED;
}

// Step 6.8 Define a public non-static turn() method
int tictactoe_game::turn() {

	// printing out the initial game board:
	std::cout << *this << endl << endl;

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

// Step 6.9 Define a public non-static play() method
int tictactoe_game::play() {
	
	int play_result = this->turn(); // In this step, turn() method will repeately call done() method and draw() method  
	
	// Situation (3)
	if (play_result == turn_enum::TURN_QUIT) {
		cout << this->game_count - 1 << " turn(s) were played, and user has asked to quit." << endl;
		return play_enum::PLAY_QUIT;
	}
	// Situation (1)
	else if (play_result == turn_enum::TURN_COMPLETED) {
		if (this->game_count % 2 != 0) {
			cout << "Player X has won the game!" << endl;
		}
		if (this->game_count % 2 == 0) {
			cout << "Player O has won the game!" << endl;
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