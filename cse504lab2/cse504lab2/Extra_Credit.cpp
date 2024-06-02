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

// Step 20. Define a function to print out game pieces and their neighbors
int print_game_board_Extra(vector<Game_Piece>& v_gamepiece, unsigned int& columns, unsigned int& rows) {

	int printing_sucess = 0;

	cout << endl;
	cout << "-------------------- Game Board (Extra Credit) ----------------------" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < rows; ++i) {		 // print out the y dimension in descending order
		for (unsigned int j = 0; j < columns; ++j) { // print out the x dimension in ascending order
			int index = columns * i + j;			 // width * row (y) + column (x)

			if (color_name_function(v_gamepiece[index].enumerated_type) != "no color") {
				cout << j << "," << i << " " << color_name_function(v_gamepiece[index].enumerated_type) << " " << v_gamepiece[index].name_of_the_piece << ": ";
				
				// 1. Lower Left: (0, 0)
				if (i - 1 >= 0 && i - 1 < rows && j - 1 >= 0 && j - 1 < columns) {
					int index_0_0 = columns * (i-1) + (j-1);

					if (color_name_function(v_gamepiece[index_0_0].enumerated_type) != "no color") {
						cout << j-1 << "," << i-1 << " " << color_name_function(v_gamepiece[index_0_0].enumerated_type) << " " << v_gamepiece[index_0_0].name_of_the_piece << "; ";
					}
				}

				// 2. Lower: (1, 0)
				if (i - 1 >= 0 && i - 1 < rows && j >= 0 && j < columns) {
					int index_1_0 = columns * (i - 1) + (j);

					if (color_name_function(v_gamepiece[index_1_0].enumerated_type) != "no color") {
						cout << j << "," << i-1 << " " << color_name_function(v_gamepiece[index_1_0].enumerated_type) << " " << v_gamepiece[index_1_0].name_of_the_piece << "; ";
					}
				}

				// 3. Lower Right: (2, 0)
				if (i - 1 >= 0 && i - 1 < rows && j + 1 >= 0 && j + 1 < columns) {
					int index_2_0 = columns * (i - 1) + (j + 1);

					if (color_name_function(v_gamepiece[index_2_0].enumerated_type) != "no color") {
						cout << j + 1 << "," << i - 1 << " " << color_name_function(v_gamepiece[index_2_0].enumerated_type) << " " << v_gamepiece[index_2_0].name_of_the_piece << "; ";
					}
				}

				// 4. Left: (0, 1)
				if (i >= 0 && i < rows && j - 1 >= 0 && j - 1 < columns) {
					int index_0_1 = columns * (i) + (j - 1);

					if (color_name_function(v_gamepiece[index_0_1].enumerated_type) != "no color") {
						cout << j - 1 << "," << i << " " << color_name_function(v_gamepiece[index_0_1].enumerated_type) << " " << v_gamepiece[index_0_1].name_of_the_piece << "; ";
					}
				}

				// 5. Right: (2, 1)
				if (i >= 0 && i < rows && j + 1 >= 0 && j + 1 < columns) {
					int index_2_1 = columns * (i)+(j + 1);

					if (color_name_function(v_gamepiece[index_2_1].enumerated_type) != "no color") {
						cout << j + 1 << "," << i << " " << color_name_function(v_gamepiece[index_2_1].enumerated_type) << " " << v_gamepiece[index_2_1].name_of_the_piece << "; ";
					}
				}

				// 6. Top Left: (0, 2)
				if (i + 1 >= 0 && i + 1 < rows && j - 1 >= 0 && j - 1 < columns) {
					int index_0_2 = columns * (i + 1)+(j - 1);

					if (color_name_function(v_gamepiece[index_0_2].enumerated_type) != "no color") {
						cout << j - 1 << "," << i + 1 << " " << color_name_function(v_gamepiece[index_0_2].enumerated_type) << " " << v_gamepiece[index_0_2].name_of_the_piece << "; ";
					}
				}

				// 7. Top Left: (1, 2)
				if (i + 1 >= 0 && i + 1 < rows && j >= 0 && j < columns) {
					int index_1_2 = columns * (i + 1) + (j);

					if (color_name_function(v_gamepiece[index_1_2].enumerated_type) != "no color") {
						cout << j << "," << i + 1 << " " << color_name_function(v_gamepiece[index_1_2].enumerated_type) << " " << v_gamepiece[index_1_2].name_of_the_piece << "; ";
					}
				}

				// 8. Top Right: (2, 2)
				if (i + 1 >= 0 && i + 1 < rows && j + 1 >= 0 && j + 1< columns) {
					int index_2_2 = columns * (i + 1) + (j + 1);

					if (color_name_function(v_gamepiece[index_2_2].enumerated_type) != "no color") {
						cout << j + 1 << "," << i + 1 << " " << color_name_function(v_gamepiece[index_2_2].enumerated_type) << " " << v_gamepiece[index_2_2].name_of_the_piece << "; ";
					}
				}

				cout << endl;
			}
			
			
			printing_sucess += 1;
		}
	}
	cout << "----------------------------------------------------------------------" << endl;

	if (printing_sucess == 0) {
		return print_game_board::print_game_board_failed;
	}
	else {
		return print_game_board::print_game_board_success;
	}
}