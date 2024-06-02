#pragma once

// Step 7. Declare an enumeration for different colors
enum piece_color { invalid_color, no_color, red, black, white };

// Step 8. Declare a function that returns color names
std::string color_name_function(piece_color i);

// Step 9. Define a function that transfers "string color" to "enum piece_color color" 
piece_color color_element_function(std::string& s);

// Step 10. Declare a struct to represent a game piece
struct Game_Piece {
	Game_Piece(piece_color, std::string, std::string);
	piece_color enumerated_type;
	std::string name_of_the_piece;
	std::string display_of_the_piece;
};
