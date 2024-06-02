#pragma once

class tictactoe_game {
	// Step 6.4 Declare the insertion operator to be a friend, so that it can access the private member variables of the game object
	friend std::ostream& operator<<(std::ostream&, const tictactoe_game&);

public:
	bool done();												// Step 6.5 Declare a public non-static done() method
	bool draw();												// Step 6.6 Declare a public non-static draw() method
	int prompt(unsigned int&, unsigned int&);					// Step 6.7 Declare a public non-static prompt() method
	int turn();													// Step 6.8 Declare a public non-static turn() method
	int play();													// Step 6.9 Declare a public non-static play() method

	int auto_player();											// Step 13 Declare an auto_player() method
	int turn_auto();											// Step 13 Declare an updated turn_auto() method
	int play_auto();											// Step 13 Declare an updated play_auto() method

private:
	int wide = 5;												// Step 6.1 The game board's wide
	int tall = 5;												// Step 6.1 The game board's tall
						
	std::vector<std::string> v_4 = { " ", " ", " ", " ", " " };	// Step 6.2 The game board's piece (empty)
	std::vector<std::string> v_3 = { " ", " ", " ", " ", " " };	// Step 6.2 The game board's piece
	std::vector<std::string> v_2 = { " ", " ", " ", " ", " " };	// Step 6.2 The game board's piece
	std::vector<std::string> v_1 = { " ", " ", " ", " ", " " };	// Step 6.2 The game board's piece
	std::vector<std::string> v_0 = { " ", " ", " ", " ", " " };	// Step 6.2 The game board's piece (empty)

	int game_count = 0;
};

// Step 6.4 Declare an insertion operator (<<)
std::ostream& operator<<(std::ostream&, const tictactoe_game&);

// Step 6.7 Declare an enumeration for prompt() method
enum prompt_enum { PROMPT_COMPLETED = 0, PROMPT_QUIT = 1 };

// Step 6.8 Declare an enumeration for turn() method
enum turn_enum { TURN_COMPLETED = 0, TURN_DRAW = 1, TURN_QUIT = 2 };

// Step 6.9 Declare an enumeration for play() method
enum play_enum{ PLAY_SUCCESS = 0, PLAY_DRAW = 1, PLAY_QUIT = 2 };