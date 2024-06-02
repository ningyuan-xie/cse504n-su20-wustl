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

// Step 13 Define an auto_player() method
int tictactoe_game::auto_player() {

	// Player O's 1st step: Take position.
	if (this->game_count == 2) {
		if (v_2[2] == " ") {
			v_2[2] = "O"; // 1. Always take the center if possible
		}
		else {
			v_1[1] = "O"; // 2. If the center is not possible, pick the lower-left corner (must be corner, otherwise lose)
		}
	}

	//------------------------------------------------------------------------------------------

	// Player O's 2nd step: Block Player X's 2nd step.
	if (this->game_count == 4) {

		if (v_2[2] == "O") { // 1. If "O" has taken the center, there are 28 situations:

			if ((v_3[1] == "X" && v_3[3] == "X") || (v_3[1] == "X" && v_2[3] == "X") || (v_3[3] == "X" && v_2[1] == "X")) {
				v_3[2] = "O"; // 1.1 Block the upper
			}
			if ((v_1[1] == "X" && v_1[3] == "X") || (v_1[1] == "X" && v_2[3] == "X") || (v_1[3] == "X" && v_2[1] == "X")) {
				v_1[2] = "O"; // 1.2 Block the lower
			}
			if ((v_1[1] == "X" && v_3[1] == "X") || (v_3[1] == "X" && v_1[2] == "X") || (v_1[1] == "X" && v_3[2] == "X") || (v_1[3] == "X" && v_3[1] == "X")) {
				v_2[1] = "O"; // 1.3 Block the left
			}
			if ((v_1[3] == "X" && v_3[3] == "X") || (v_1[3] == "X" && v_3[2] == "X") || (v_1[2] == "X" && v_3[3] == "X") || (v_1[1] == "X" && v_3[3] == "X")) {
				v_2[3] = "O"; // 1.4 Block the right
			}
			if ((v_3[1] == "X" && v_3[2] == "X") || (v_1[3] == "X" && v_2[3] == "X") || (v_2[3] == "X" && v_3[2] == "X")) {
				v_3[3] = "O"; // 1.5 Block the upper right
			}
			if ((v_3[2] == "X" && v_3[3] == "X") || (v_1[1] == "X" && v_2[1] == "X") || (v_2[1] == "X" && v_3[2] == "X") || (v_1[2] == "X" && v_3[2] == "X")) {
				v_3[1] = "O"; // 1.6 Block the upper left
			}
			if ((v_2[1] == "X" && v_3[1] == "X") || (v_1[2] == "X" && v_1[3] == "X") || (v_1[2] == "X" && v_2[1] == "X") || (v_2[1] == "X" && v_2[3] == "X")) {
				v_1[1] = "O"; // 1.7 Block the lower left
			}
			if ((v_1[1] == "X" && v_1[2] == "X") || (v_3[3] == "X" && v_2[3] == "X") || (v_1[2] == "X" && v_2[3] == "X")) {
				v_1[3] = "O"; // 1.8 Block the lower right
			}

		}

		if (v_1[1] == "O") { // 2. If "O" has taken the lower-left corner ("X" has taken center in 1st step), there are 7 situations:
			if (v_3[1] == "X") {
				v_1[3] = "O"; // 2.1 Block the lower right
			}
			if (v_3[2] == "X") {
				v_1[2] = "O"; // 2.2 Block the lower
			}
			if (v_2[1] == "X") {
				v_2[3] = "O"; // 2.3 Block the right
			}
			if (v_2[3] == "X" || v_3[3] == "X") { // does not need to block X's triple here 
				v_2[1] = "O"; // 2.4 Block the left
			}
			if (v_1[3] == "X") {
				v_3[1] = "O"; // 2.5 Block the upper
			}
			if (v_1[2] == "X") {
				v_3[2] = "O"; // 2.6 Block the upper left
			}
		}

	}

	//------------------------------------------------------------------------------------------ 

	// Player O's 3rd step: triple or block Player X's 3rd step. 
	if (this->game_count == 6) {

		if (v_2[2] == "O") { // 1. If "O" has taken the center:
			if (v_3[1] == "X" && v_3[2] == "O" && v_3[3] == "X") { // 1.1
				if (v_1[2] == "X") {
					v_2[1] = "O"; // 1.1.1 Block the left
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_3[2] == "O" && v_2[3] == "X") { // 1.1
				if (v_1[2] == "X") {
					v_1[1] = "O"; // 1.1.2 Block the lower left
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_2[1] == "X" && v_3[2] == "O" && v_3[3] == "X") { // 1.1
				if (v_1[2] == "X") {
					v_1[3] = "O"; // 1.1.3 Block the lower right
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}

			else if (v_1[1] == "X" && v_1[2] == "O" && v_1[3] == "X") { // 1.2
				if (v_3[2] == "X") {
					v_2[1] = "O"; // 1.2.1 Block the left
				}
				else {
					v_3[2] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "X" && v_1[2] == "O" && v_2[3] == "X") { // 1.2
				if (v_3[2] == "X") {
					v_3[1] = "O"; // 1.2.2 Block the upper left
				}
				else {
					v_3[2] = "O"; // form a triple
				}
			}
			else if (v_2[1] == "X" && v_1[2] == "O" && v_1[3] == "X") { // 1.2
				if (v_3[2] == "X") {
					v_3[3] = "O"; // 1.2.3 Block the upper right
				}
				else {
					v_3[2] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[1] == "X") { // 1.3
				if (v_2[3] == "X") {
					v_3[2] = "O"; // 1.3.1 Block the upper
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_2[1] == "O" && v_1[1] == "X") { // 1.3
				if (v_2[3] == "X") {
					v_1[3] = "O"; // 1.3.2 Block the lower right
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[2] == "X") { // 1.3
				if (v_2[3] == "X") {
					v_3[3] = "O"; // 1.3.3 Block the upper right
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[3] == "X") { // 1.3
				if (v_2[3] == "X") {
					v_3[3] = "O"; // 1.3.4 Block the upper right
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}

			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[3] == "X") { // 1.4
				if (v_2[1] == "X") {
					v_3[2] = "O"; // 1.4.1 Block the upper
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_2[3] == "O" && v_1[3] == "X") { // 1.4
				if (v_2[1] == "X") {
					v_1[1] = "O"; // 1.4.2 Block the lower left
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[2] == "X") { // 1.4
				if (v_2[1] == "X") {
					v_3[1] = "O"; // 1.4.3 Block the upper left
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[1] == "X") { // 1.4
				if (v_2[1] == "X") {
					v_3[1] = "O"; // 1.4.4 Block the upper left
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_3[2] == "X" && v_3[3] == "O") { // 1.5
				if (v_1[1] == "X") {
					v_2[1] = "O"; // 1.5.1 Block the left
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "O" && v_2[3] == "X" && v_1[3] == "X") { // 1.5
				if (v_1[1] == "X") {
					v_1[2] = "O"; // 1.5.2 Block the lower
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_3[3] == "O" && v_2[3] == "X") { // 1.5
				if (v_1[1] == "X") {
					v_3[1] = "O"; // 1.5.3 Block the left
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "O" && v_3[2] == "X" && v_3[3] == "X") { // 1.6
				if (v_1[3] == "X") {
					v_2[3] = "O"; // 1.6.1 Block the right
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_2[1] == "X" && v_1[1] == "X") { // 1.6
				if (v_1[3] == "X") {
					v_1[2] = "O"; // 1.6.2 Block the lower
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_3[2] == "X" && v_2[3] == "X") { // 1.6
				if (v_1[3] == "X") {
					v_3[3] = "O"; // 1.6.3 Block the upper right
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_3[2] == "X" && v_1[2] == "X") { // 1.6
				if (v_1[3] == "X") {
					v_1[1] = "O"; // 1.6.4 Block the lower left
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_2[1] == "X" && v_1[1] == "O") { // 1.7
				if (v_3[3] == "X") {
					v_3[2] = "O"; // 1.7.1 Block the upper
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_1[2] == "X" && v_1[3] == "X") { // 1.7
				if (v_3[3] == "X") {
					v_2[3] = "O"; // 1.7.2 Block the right
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_2[1] == "X" && v_1[2] == "X") { // 1.7
				if (v_3[3] == "X") {
					v_1[3] = "O"; // 1.7.3 Block the lower right
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_2[1] == "X" && v_2[3] == "X") { // 1.7
				if (v_3[3] == "X") {
					v_1[3] = "O"; // 1.7.4 Block the lower right
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}

			else if (v_1[1] == "X" && v_1[2] == "X" && v_1[3] == "O") { // 1.8
				if (v_3[1] == "X") {
					v_2[1] = "O"; // 1.8.1 Block the left
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "X" && v_1[3] == "O") { // 1.8
				if (v_3[1] == "X") {
					v_3[2] = "O"; // 1.8.2 Block the upper
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}
			else if (v_2[3] == "X" && v_1[2] == "X" && v_1[3] == "O") { // 1.8
				if (v_3[1] == "X") {
					v_3[3] = "O"; // 1.8.3 Block the upper right
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}
		}

		if (v_1[1] == "O") { // 2. If "O" has taken the lower-left corner ("X" has taken center in 1st step):

			// Check if "O" can triple first: there are 4 situations
			if (v_1[3] == "O" && v_1[2] == " ") {
				v_1[2] = "O"; // form a triple
			}
			if (v_1[2] == "O" && v_1[3] == " ") {
				v_1[3] = "O"; // form a triple
			}
			if (v_3[1] == "O" && v_2[1] == " ") {
				v_2[1] = "O"; // form a triple
			}
			if (v_2[1] == "O" && v_3[1] == " ") {
				v_3[1] = "O"; // form a triple
			}

			// Block X's triple: there are 15 situations
			if (v_3[1] == "X") { // 2.1
				if (v_1[2] == "X") { 
					v_3[2] = "O"; // 2.1.1 Block the upper
				}
			}
			if (v_3[2] == "X") { // 2.2
				if (v_1[3] == "X") { 
					v_3[1] = "O"; // 2.2.1 Block the upper left
				}
			}
			if (v_2[1] == "X") { // 2.3
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.3.1 Block the lower right
				}
				if (v_3[2] == "X") {
					v_1[2] = "O"; // 2.3.2 Block the lower
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.3.3 Block the upper left
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.3.4 Block the upper
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.3.5 Block the upper left
				}
			}
			if (v_3[3] == "X" || v_2[3] == "X") { // 2.4
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.4.1 Block the upper left
				}
			}
			if (v_1[3] == "X") { // 2.5
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.5.1 Block the right
				}
			}
			if (v_1[2] == "X") { // 2.6
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.6.1 Block the lower right
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.6.2 Block the upper left
				}
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.6.3 Block the right
				}
				if (v_2[3] == "X") {
					v_2[1] = "O"; // 2.6.4 Block the left
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.6.5 Block the upper left
				}
			}

		}
	}

	//------------------------------------------------------------------------------------------

	// Player O's 4th step
	if (this->game_count == 8) {
		
		if(v_2[2] == "O") { // 1. If "O" has taken the center:
			
			if (v_3[1] == "X" && v_3[2] == "O" && v_3[3] == "X" && v_2[1] == "O" && v_1[2] == "X") { // 1.1.1
				if (v_2[3] == "X") {
					v_1[1] = "O"; // 1.1.1.1 Block the lower left
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_3[2] == "O" && v_2[3] == "X" && v_1[1] == "O" && v_1[2] == "X") { // 1.1.2
				if (v_3[3] == "X") {
					v_1[3] = "O"; // 1.1.2.1 Block the lower left
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}
			else if (v_2[1] == "X" && v_3[2] == "O" && v_3[3] == "X" && v_1[2] == "X" && v_1[3] == "O") { // 1.1.3
				if (v_3[1] == "X"){
					v_1[1] = "O"; // 1.1.3.1 Block the lower left
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}

			else if (v_1[1] == "X" && v_1[2] == "O" && v_1[3] == "X" && v_2[1] == "O" && v_3[2] == "X") { // 1.2.1
				if (v_2[3] == "X") {
					v_3[3] = "O"; // 1.2.1.1 Block the upper right
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "X" && v_1[2] == "O" && v_2[3] == "X" && v_3[1] == "O" && v_3[2] == "X") { // 1.2.2
				if (v_1[3] == "X") {
					v_3[3] = "O"; // 1.2.2.1 Block the upper right
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}
			else if (v_2[1] == "X" && v_1[2] == "O" && v_1[3] == "X" && v_3[2] == "X" && v_3[3] == "O") { // 1.2.3
				if (v_1[1] == "X") {
					v_3[1] = "O"; // 1.2.3.1 Block the upper left
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[1] == "X" && v_3[2] == "O" && v_2[3] == "X") { // 1.3.1
				if (v_1[2] == "X") {
					v_1[3] = "O"; // 1.3.1.1 Block the lower right
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_2[1] == "O" && v_1[1] == "X" && v_2[3] == "X" && v_1[3] == "X") { // 1.3.2
				if (v_3[1] == "X") {
					v_3[3] = "O"; // 1.3.2.1 Block the lower right
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[2] == "X" && v_3[3] == "O" && v_2[3] == "X") { // 1.3.3
				if (v_1[1] == "X") {
					v_1[3] = "O"; // 1.3.3.1 Block the lower right
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "X" && v_2[1] == "O" && v_1[3] == "X" && v_3[3] == "O" && v_2[3] == "X") { // 1.3.4
				if (v_1[1] == "X") {
					v_1[2] = "O"; // 1.3.4.1 Block the lower
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}

			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[3] == "X" && v_3[2] == "O" && v_2[1] == "X") { // 1.4.1
				if (v_1[2] == "X") {
					v_1[1] = "O"; // 1.4.1.1 Block the lower left
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_2[3] == "O" && v_1[3] == "X" && v_2[1] == "X" && v_1[1] == "O") { // 1.4.2
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 1.4.2.1 Block the upper left
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[2] == "X" && v_3[1] == "O" && v_2[1] == "X") { // 1.4.3
				if (v_1[3] == "X") {
					v_1[1] = "O"; // 1.4.3.1 Block the lower left
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "O" && v_1[1] == "X" && v_3[1] == "O" && v_2[1] == "X") { // 1.4.4
				if (v_1[3] == "X") {
					v_1[2] = "O"; // 1.4.4.1 Block the lower
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_3[2] == "X" && v_3[3] == "O" && v_2[1] == "O" && v_1[1] == "X") { // 1.5.1
				if (v_2[1] == "X") {
					v_1[3] = "O"; // 1.5.1.1 Block the lower right
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "O" && v_2[3] == "X" && v_1[3] == "X" && v_1[1] == "X" && v_1[2] == "O") { // 1.5.2
				if (v_3[2] == "X") {
					v_3[1] = "O"; // 1.5.2.1 Block the upper left
				}
				else {
					v_3[2] = "O"; // form a triple
				}
			}
			else if (v_3[2] == "X" && v_3[3] == "O" && v_2[3] == "X" && v_3[1] == "O" && v_1[1] == "X") { // 1.5.3
				if (v_1[3] == "X") {
					v_1[2] = "O"; // 1.5.3.1 Block the lower
				}
				else {
					v_1[3] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "O" && v_3[2] == "X" && v_3[3] == "X" && v_2[3] == "O" && v_1[3] == "X") { // 1.6.1
				if (v_2[1] == "X") {
					v_1[1] = "O"; // 1.6.1.1 Block the lower left
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_2[1] == "X" && v_1[1] == "X" && v_1[2] == "O" && v_1[3] == "X") { // 1.6.2
				if (v_3[2] == "X") {
					v_3[3] = "O"; // 1.6.2.1 Block the upper right
				}
				else {
					v_3[2] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_3[2] == "X" && v_2[3] == "X" && v_3[3] == "O" && v_1[3] == "X") { // 1.6.3
				if (v_1[1] == "X") {
					v_1[2] = "O"; // 1.6.3.1 Block the lower
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}
			else if (v_3[1] == "O" && v_3[2] == "X" && v_1[2] == "X" && v_1[1] == "O" && v_1[3] == "X") { // 1.6.4
				if (v_3[3] == "X") {
					v_2[3] = "O"; // 1.6.4.1 Block the right
				}
				else {
					v_3[3] = "O"; // form a triple
				}
			}

			else if (v_3[1] == "X" && v_2[1] == "X" && v_1[1] == "O" && v_3[2] == "O" && v_3[3] == "X") { // 1.7.1
				if (v_1[2] == "X") {
					v_1[3] = "O"; // 1.7.1 Block the lower right
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_1[2] == "X" && v_1[3] == "X" && v_3[3] == "X" && v_2[3] == "O") { // 1.7.2
				if (v_2[1] == "X") {
					v_3[1] = "O"; // 1.7.2.1 Block the upper left
				}
				else {
					v_2[1] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_2[1] == "X" && v_1[2] == "X" && v_3[3] == "X" && v_1[3] == "O") { // 1.7.3
				if (v_3[1] == "X") {
					v_3[2] = "O"; // 1.7.3.1 Block the upper
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}
			else if (v_1[1] == "O" && v_2[1] == "X" && v_2[3] == "X" && v_3[1] == "X" && v_1[3] == "O") { // 1.7.4
				if (v_3[1] == "X") {
					v_3[2] = "O"; // 1.7.4.1 Block the upper
				}
				else {
					v_3[1] = "O"; // form a triple
				}
			}

			else if (v_1[1] == "X" && v_1[2] == "X" && v_1[3] == "O" && v_3[1] == "X" && v_2[1] == "O") { // 1.8.1
				if (v_2[3] == "X") {
					v_3[3] = "O"; // 1.8.1.1 Block the upper right
				}
				else {
					v_2[3] = "O"; // form a triple
				}
			}
			else if (v_3[3] == "X" && v_2[3] == "X" && v_1[3] == "O" && v_3[1] == "X" && v_3[2] == "O") { // 1.8.2
				if (v_1[2] == "X") {
					v_1[1] = "O"; // 1.8.2.1 Block the lower left
				}
				else {
					v_1[2] = "O"; // form a triple
				}
			}
			else if (v_2[3] == "X" && v_1[2] == "X" && v_1[3] == "O" && v_3[1] == "X" && v_3[3] == "O") { // 1.8.3
				if (v_1[1] == "X") {
					v_2[1] = "O"; // 1.8.3.1 Block the left
				}
				else {
					v_1[1] = "O"; // form a triple
				}
			}
		}

		if (v_1[1] == "O") { // 2. If "O" has taken the lower-left corner ("X" has taken center in 1st step):

			if (v_3[1] == "X" && v_3[2] == "O" && v_1[2] == "X" && v_1[3] == "O") { // 2.1.1
				if ((v_3[3] == "X") || (v_2[3] == "X")) {
					v_2[1] = "O"; // 2.1.1.1 & 2.1.1.3
				}
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.1.1.2
				}
			}
			if (v_3[1] == "O" && v_3[2] == "X" && v_1[2] == "O" && v_1[3] == "X") { // 2.2.1
				if ((v_3[3] == "X") || (v_2[3] == "X")) {
					v_2[1] = "O"; // 2.2.1.1 & 2.2.1.3
				}
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.2.1.2
				}
			}
			if (v_3[1] == "X" && v_2[1] == "X" && v_2[3] == "O" && v_1[3] == "O") { // 2.3.1
				if (v_3[2] == "X") {
					v_3[3] = "O"; // 2.3.1.1
				}
				if (v_3[3] == "X") {
					v_1[2] = "O"; // 2.3.1.2
				}
				if (v_1[2] == "X") {
					v_3[3] = "O"; // 2.3.1.3
				}
			}
			if (v_3[2] == "X" && v_2[1] == "X" && v_1[2] == "O" && v_2[3] == "O") { // 2.3.2
				if (v_3[1] == "X") {
					v_3[3] = "O"; // 2.3.2.1
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.3.2.2
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.3.2.3
				}
			}
			if (v_3[1] == "O" && v_2[1] == "X" && v_3[3] == "X" && v_2[3] == "O") { // 2.3.3
				if (v_3[2] == "X") {
					v_1[2] = "O"; // 2.3.3.1
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.3.3.2
				}
				if (v_1[3] == "X") {
					v_3[2] = "O"; // 2.3.3.3
				}
			}
			if (v_2[1] == "X" && v_3[2] == "O" && v_1[2] == "X" && v_2[3] == "O") { // 2.3.4
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.3.4.1
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.3.4.2
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.3.4.3
				}
			}
			if (v_3[1] == "O" && v_2[1] == "X" && v_2[3] == "O" && v_1[3] == "X") { // 2.3.5
				if (v_3[2] == "X") {
					v_1[2] = "O"; // 2.3.5.1
				}
				if (v_3[3] == "X") {
					v_3[2] = "O"; // 2.3.5.2
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.3.5.3
				}
			}
			if (v_3[1] == "X" && v_2[1] == "O" && v_3[3] == "X" && v_1[3] == "O") { // 2.4.1
				if (v_2[3] == "X") {
					v_1[2] = "O"; // 2.4.1.1
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.4.1.2
				}
			}
			if (v_3[1] == "X" && v_2[1] == "O" && v_2[3] == "X" && v_1[3] == "O") { // 2.4.2
				if (v_3[2] == "X") {
					v_3[3] = "O"; // 2.4.2.1
				}
				if (v_3[3] == "X") {
					v_3[2] = "O"; // 2.4.2.2
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.4.2.3
				}
			}
			if (v_3[1] == "O" && v_2[1] == "X" && v_2[3] == "O" && v_1[3] == "X") { // 2.5.1
				if (v_3[2] == "X") {
					v_1[2] = "O"; // 2.5.1.1
				}
				if (v_3[3] == "X") {
					v_3[2] = "O"; // 2.5.1.2
				}
				if (v_1[2] == "X") {
					v_3[2] = "O"; // 2.5.1.3
				}
			}
			if (v_3[1] == "X" && v_3[2] == "O" && v_1[2] == "X" && v_1[3] == "O") { // 2.6.1
				if (v_3[3] == "X") {
					v_2[1] = "O"; // 2.6.1.1
				}
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.6.1.2
				}
				if (v_2[3] == "X") {
					v_2[1] = "O"; // 2.6.1.3
				}
			}
			if (v_3[1] == "O" && v_3[2] == "O" && v_3[3] == "X" && v_1[2] == "X") { // 2.6.2
				if (v_2[1] == "X") {
					v_2[3] = "O"; // 2.6.2.1
				}
				if (v_2[3] == "X") {
					v_2[1] = "O"; // 2.6.2.2
				}
				if (v_1[3] == "X") {
					v_2[1] = "O"; // 2.6.2.3
				}
			}
			if (v_3[2] == "O" && v_2[1] == "X" && v_1[2] == "X" && v_2[3] == "O") { // 2.6.3
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.6.3.1
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.6.3.2
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.6.3.3
				}
			}
			if (v_3[2] == "O" && v_2[1] == "O" && v_1[2] == "X" && v_2[3] == "X") { // 2.6.4
				if (v_3[1] == "X") {
					v_1[3] = "O"; // 2.6.4.1
				}
				if (v_3[3] == "X") {
					v_3[1] = "O"; // 2.6.4.2
				}
				if (v_1[3] == "X") {
					v_3[1] = "O"; // 2.6.4.3
				}
			}
			if (v_3[1] == "O" && v_3[2] == "O" && v_1[2] == "X" && v_1[3] == "X") { // 2.6.5
				if (v_3[3] == "X") {
					v_2[1] = "O"; // 2.6.5.1
				}
				if (v_2[1] == "X") {
					v_3[3] = "O"; // 2.6.5.2
				}
				if (v_2[3] == "X") {
					v_3[3] = "O"; // 2.6.5.3
				}
			}
		}
	}

	return turn_enum::TURN_COMPLETED;
}



	


// Step 13 Define an updated turn_auto() method
int tictactoe_game::turn_auto() {

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

			auto_player();
			
			std::cout << *this << endl;
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
int tictactoe_game::play_auto() {

	int play_result = this->turn_auto(); // In this step, turn() method will repeately call done() method and draw() method  

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