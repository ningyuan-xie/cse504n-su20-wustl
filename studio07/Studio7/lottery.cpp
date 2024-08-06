// lottery.cpp : Defines the entry point for the console application.
// Author: Jon Shidal
// Purpose: define lottery related functions and main. This program takes in 5 arguments
// that should all be integers between 1-100. The program then generates 10 winning numbers
// and compares the user selected numbers against the winning numbers to decide how much the 
// user wins, if any.
//

#include "lottery.h"
#include "algorithms.h"
#include<iostream>
#include<vector>
#include<stdlib.h> // for srand() and rand()
#include<time.h> // for time()

using namespace std;

int main(int argc, char * argv[])
{
	// some constants to help with command line parsing
	const int program_name = 0;
	const int expected_args = (int)params::USERNUMBERS + 1; // expected_args = 5 + 1 = 6
	
	if (argc != expected_args) {
		usage(argv[program_name]);
		return (int)outcomes::INCORRECTUSAGE;
	}

	vector<int> winning_numbers;
	generate_winning_numbers(winning_numbers);
	vector<int> user_numbers;
	for (int i = 1; i < argc; ++i) {
		user_numbers.push_back(atoi(argv[i])); // converts the input string to an int or to 0 if the conversion fails
	} // atoi (ASCII to integer): string to int

	insertion_sort(winning_numbers); // sort the winning numbers in ascending order to make binary search work

	unsigned int matches = 0;
	for (unsigned int i = 0; i < user_numbers.size(); ++i) {
		if (binary_search(winning_numbers, user_numbers[i])) {
			++matches;
		}
	}
    return (int)print_results(matches, winning_numbers, user_numbers);
}

void usage(char * program_name) {
	cout << "This program compares " << (int)params::USERNUMBERS << " numbers (from 1-" << (int)params::MAXNUMBER << ") taken as input and compares them with " << (int)params::WINNINGNUMBERS << " randomly generated winning numbers" << endl;
	cout << "Usage: " << program_name;
	for (unsigned int i = 0; i < (int)params::USERNUMBERS; ++i) {
		cout << " <(1-" << (int)params::MAXNUMBER << ")>"; // <(1-100)> <(1-100)> <(1-100)> <(1-100)> <(1-100)>
	}
	cout << endl;
}

void generate_winning_numbers(std::vector<int> & v) {
	srand(time(0)); // seed the random number generator
	for (unsigned int i = 0; i < (int)params::WINNINGNUMBERS; ++i) {
		v.push_back((rand() % (int)params::MAXNUMBER) + 1); // generates a random integer between (0 and 99) + 1
	} // "%" is modulus operator, which returns the remainder of the division
}

outcomes print_results(unsigned int matching, vector<int> & winning_numbers, vector<int> & user_numbers) {
	cout << "Winning numbers:";
	for (unsigned int i = 0; i < (int)params::WINNINGNUMBERS; ++i) {
		cout << " " << winning_numbers[i];
	}
	cout << endl;
	
	cout << "Your numbers:";
	for (unsigned int i = 0; i < (int)params::USERNUMBERS; ++i) {
		cout << " " << user_numbers[i];
	}
	cout << endl;

	if (matching < (unsigned int)params::USERNUMBERS / 2 + 1) { // lose if you matched half or less 
		cout << "Sorry, you only matched " << matching << " numbers. Better luck next time!" << endl;
		return outcomes::NOTAWINNER;
	}
	else if (matching < (unsigned int)params::USERNUMBERS) { // win if more than half of your numbers are winners
		cout << "Congratulations, you won! You matched " << matching << " numbers." << endl;
		return outcomes::WINNER;
	}
	else { // jackpot if all numbers are matching
		cout << "You hit the Jackpot!!! You matched all 5 numbers." << endl;
		return outcomes::JACKPOT;
	}
}
