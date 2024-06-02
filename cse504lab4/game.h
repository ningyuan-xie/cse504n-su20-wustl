#pragma once

// Step 6. Refactor tictactoe_game from Lab 3 into a base class
class game_base {

public:
	virtual void print() = 0;						// Step 10. Declare a pure virtual print() method
	virtual bool done() = 0;						// Step 12. Declare a pure virtual done() method
	virtual bool draw() = 0;						// Step 13. Declare a pure virtual draw() method
	int prompt(unsigned int&, unsigned int&);		// Step 14. Move the prompt() method to the base class
	virtual int turn() = 0;							// Step 15. Declare a pure virtual turn() method
	int play();										// Step 16. Move the play() method to the base class

	static game_base* check_argument(int argc, char* argv[]);	// Step 17. Add a static method to the base class

protected:
	int wide = 0;												// The game board's wide
	int tall = 0;												// The game board's tall
	std::string game_piece_1;
	std::string game_piece_2;

	std::vector<std::string> v_4 = { " ", " ", " ", " ", " " }; // The game board's piece (empty)
	std::vector<std::string> v_3 = { " ", " ", " ", " ", " " };	// The game board's piece
	std::vector<std::string> v_2 = { " ", " ", " ", " ", " " };	// The game board's piece
	std::vector<std::string> v_1 = { " ", " ", " ", " ", " " };	// The game board's piece
	std::vector<std::string> v_0 = { " ", " ", " ", " ", " " };	// The game board's piece (empty)

	int game_count = 0;

	int longest_display_string_length = 1; // Step 8. Remembers the longest display string length

};

// Step 6. A class derived from that base class through public inheritance
class tictactoe_game: public game_base {
	// Declare the insertion operator to be a friend
	friend std::ostream& operator<<(std::ostream&, const tictactoe_game&);

public:
	virtual void print() override;				// Step 11. Override the virtual print() method 
	virtual bool done();						// Step 12. Make the done() method virtual
	virtual bool draw();						// Step 13. Make the draw() method virtual
	virtual int turn();							// Step 15. Make the turn() method virtual

protected:
	unsigned int wide = 5;						// The game board's wide
	unsigned int tall = 5;						// The game board's tall
	
	std::string game_piece_1 = "X";
	std::string game_piece_2 = "O";

	std::string board[4][4];

	int longest_display_string_length = 2; // because TictacToe needs 1 digit num + 1 space
};

// Step 20. Declare a Gomoku game class
class gomoku_game : public game_base {

	// Step 22. Declare the insertion operator to be a friend
	friend std::ostream& operator<<(std::ostream&, const gomoku_game&);

public:
	gomoku_game(int i_1, int i_2);				// Override constructor (Extra Credit)

	virtual void print() override;				// Step 23. Override the virtual print() method 
	virtual bool done();						// Step 24. Make the done() method virtual
	virtual bool draw();						// Step 25. Make the draw() method virtual
	virtual int turn();							// Step 26. Make the turn() method virtual

protected:
	unsigned int wide = 19;						// The game board's wide
	unsigned int tall = 19;						// The game board's tall
	std::string game_piece_1 = "B";
	std::string game_piece_2 = "W";

	std::vector<std::vector<std::string> > board{
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 1
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 2
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 3
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 4
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 5
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 6
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 7
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 8
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 9
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 10
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 11
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 12
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 13
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 14
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 15
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 16
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 17
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // 18
		{ " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}  // 19
	};
	
	int longest_display_string_length = 3; // because Gomoku needs 2 digit num + 1 space

	// Extra credit
	int number_of_connecting_pieces_needed_to_win = 5;
};


// Declare an insertion operator for TicTacToe (<<)
std::ostream& operator<<(std::ostream&, const tictactoe_game&);

// Step 22. Declare an insertion operator for Gomoku (<<)
std::ostream& operator<<(std::ostream&, const gomoku_game&);



// Declare an enumeration for prompt() method
enum prompt_enum { PROMPT_COMPLETED = 0, PROMPT_QUIT = 5 };

// Declare an enumeration for turn() method
enum turn_enum { TURN_COMPLETED = 0, TURN_DRAW = 6, TURN_QUIT = 7 };

// Declare an enumeration for play() method
enum play_enum { PLAY_SUCCESS = 0, PLAY_DRAW = 8, PLAY_QUIT = 9 };

