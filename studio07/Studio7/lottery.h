#pragma once
/* lottery.h
Author: Jon Shidal
Purpose: declarations for lottery functionality such as generating winning numbers and calculating payouts
*/

// #pragma once achieves the same result as header guards, so leaving them out this time
#include<vector>

// the possible outcomes from a single round
enum struct outcomes { NOTAWINNER, WINNER, JACKPOT, INCORRECTUSAGE = -1 };
enum struct params { MAXNUMBER = 100, WINNINGNUMBERS = 20, USERNUMBERS = 5 }; // update winning num from 10 to 20 to increase win rates

// called if a user runs the program incorrectly, displays correct usage of the program
void usage(char * program_name);

// randomly generates WINNINGNUMBERS numbers from 1-MAXNUMBER
void generate_winning_numbers(std::vector<int> & v);

// displays the number of matching numbers and results. returns 0 if not a winner (user matched <= half their numbers), 1 if a winner
// (user matched > half their numbers, but < USERNUMBERS numbers, 2 if usermatched all their numbers
outcomes print_results(unsigned int matching, std::vector<int> & winning_numbers, std::vector<int> & user_numbers);
