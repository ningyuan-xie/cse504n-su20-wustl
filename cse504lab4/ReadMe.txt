Ningyuan Xie CSE 504N Lab 4

I chose to do this Lab alone.

Errors/warnings：

   Built upon my previous Lab 3, I did not run into many errors/warnings.

1. Initially I chose 2D array[][] as data structure for "Gomoku" game board. I encountered errors where I cannot simply
   assign "array[19][19] = ' ' " to represent empty game board, because the error states that "a value of type "char" cannot 
   be used to initialize an entity of type std::string[19][19]". So, eventually I chose 2D vector as data structure instead.

2. There were warnings stating that I should not compare "unsigned int" with "int". I fixed it by changing the "int" into 
   "unsigned int".


Test cases I run: 

1. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe"
   I did not correctly input a argument name. The program correctly printed out an instruction: 
   "usage: cse504lab4.exe <TicTacToe> or <Gomoku>"


2. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe test"
   I did not input the right argument name. Again, the program correctly printed out an instruction: 
   "usage: cse504lab4.exe <TicTacToe> or <Gomoku>"


3. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe TicTacToe"
   I correctly input the right argument name <TicTacToe>. The program opens the game and asks for input:

	You are now playing 'TicTacToe' created by Ningyuan Xie. Enjoy!
	---------------------------------------------------------------

	- Game Board -
	--------------
	 4
	 3
	 2
	 1
	 0
	  0 1 2 3 4
	--------------

	Now it's X's turn.
	What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc.
	Input:


4. Just like it did in Lab 3, "TicTacToe" can handle valid and invalid inputs and keep on playing, can identifies successful
   completion, and unsuccessful completion:

   If I typed <2-2>, the program will correctly print: "Please input in the format of <x,y>."

   if I typed <4,1>, the program will correctly print: "Please enter a x coordinate between 1 and 3."

   If I typed an input of a non-empty square, the program will correctly print: "This is not an empty square. Please choose an empty square." 

   If I typed <quit> anytime, the program will correctly print: "1 turn(s) were played, and user has asked to quit."

   If the game has one winner, the program will correctly print: "Player 1 has won the game!"

   If the game ends in draw, the program will correctly print: "9 turns were played, and no winning moves remain."


5. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe Gomoku"
   I correctly input the right argument name <Gomoku>. The program opens the game and asks for input:

	You are now playing 'Gomoku' created by Ningyuan Xie. Enjoy!
	---------------------------------------------------------------

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
	--------------------------------------------------------------


6. Just like "TicTacToe", "Gomoku" can also handle valid and invalid inputs and keep on playing, can identifies successful
   completion, and unsuccessful completion:

   If I typed <2-2>, the program will correctly print: "Please input in the format of <x,y>."

   if I typed <20,20>, the program will correctly print: "Please enter a x coordinate between 1 and 19."

   If I typed an input of a non-empty square, the program will correctly print: "This is not an empty square. Please choose an empty square." 

   If I typed <quit> anytime, the program will correctly print: "1 turn(s) were played, and user has asked to quit."

   If the game has one winner, the program will correctly print: "Player 1 has won the game!"


7. Below is one game play of Gomoku where Player White won:

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6           B     B  W
	  5              B  W
	  4           W  W  B  B
	  3           W        B
	  2        W
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
	--------------------------------------------------------------

	Player White: 4, 4; 6, 5; 5, 4; 4, 3; 7, 6; 3, 2;

	Player 2 has won the game!


------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------

Extra Credit Section


Design and Implementation:

   The function I modified the most is the "check argument" function. Previously, I only consider when one
   input is correctly typed; now I added two "else if" to consider cases when two and three inputs are correctly
   typed:

   When two inputs are typed, I check whether the game is "Gomoku", then I check whether the addition input is 
   between 3 and 19 (due to time constraint and display constraint, I limit my "arbitrary" choice between 3 and
   19). If both are correct, I pass that additional input into "wide" and "tall" used to construct "gomoku_game".
   Because my other functions such as print(), turn() are all coded using member variables "wide" and "tall",
   no major changes are needed in other functions.

   When three inputs are typed, I will check the first two as before, then I check the 3rd input whether it is 
   between 3 and 12 (due to time constraint and display constraint, I limit my "arbitrary" choice between 3 and
   12). If all the arguments are correct, I pass that additional input into a new member variable I created in
   "gomoku_game" class: "int number_of_connecting_pieces_needed_to_win". Normally if no 3rd input, this value is 
   by default 5; now it will represent a reasonable input value. Therefore, for this step I also modified my
   "gomoku_game" constructor: previously it can be constructed using "wide" and "tall" only; now it also sets
   "number_of_connecting_pieces_needed_to_win" when constructed.

   Tn addtion, I also added more wining situations in done() to accomodate more possibilities. Detailed tests
   can be seen below.

   Finally, I test my program multiple times on all kinds of situations. I did not list every possible results, 
   but I believe it is quite rigorous now. Again, you are welcome to try and enjoy my game!


Test and Results

1. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe"
   command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe test"
   command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe TicTacToe 2"
   command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe Gomoku 10 1"

   In these cases, I did not correctly input a name; I did not input the 1st argument correctly;
   I did not input the 2nd argument correctly...The program will print out an instruction: 
   "usage: cse504lab4.exe <TicTacToe>or<Gomoku> <3-19>(extra) <3-12>(extra)"


2. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe Gomoku"
   
   I input the 1st argument correctly. The program will execute the default version of the game as before:

	You are now playing 'Gomoku' created by Ningyuan Xie. Enjoy!
	---------------------------------------------------------------

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
	--------------------------------------------------------------

	Now it's Black's turn.
	What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc.
	Input:


3. Blow is a case where one player wins in the default version:

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2  W  W  W  W
	  1  B  B  B  B  B
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
	--------------------------------------------------------------

	Player Black: 1, 1; 2, 1; 3, 1; 4, 1; 5, 1;

	Player 1 has won the game!


4. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe Gomoku 8"

   I input the first two arguments correctly. The program will execute the 2nd version of the game with
   the custom game board size:

	You are now playing 'Gomoku' (arbitrary size) created by Ningyuan Xie. Enjoy!
	-----------------------------------------------------------------------------

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8
	--------------------------------------------------------------

	Now it's Black's turn.
	What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc.
	Input:


5. In the above test, I did not input the 3rd argument, so the player will also win with 5 pieces.
   Blow is a case where one player wins in this game version:

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	  8
	  7
	  6
	  5
	  4
	  3
	  2  W  W  W  W
	  1  B  B  B  B  B
	  X  1  2  3  4  5  6  7  8
	--------------------------------------------------------------

	Player Black: 1, 1; 2, 1; 3, 1; 4, 1; 5, 1;

	Player 1 has won the game!


6. command line: "H:\CSE_504N_Lab4\cse504lab4\Debug>cse504lab4.exe Gomoku 10 4"

   I input the first three arguments correctly. The program will execute the 3rd version of the game with
   the custom game board size:

	You are now playing 'Gomoku' (arbitrary size & arbitrary connecting number) created by Ningyuan Xie. Enjoy!
	-----------------------------------------------------------------------------------------------------------

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10
	--------------------------------------------------------------


7. In the above test, I input the 3rd argument, so the player will now win with 4 pieces only.
   Blow is a case where one player wins in this game version:

	----------------------- Game Board ---------------------------
	--------------------------------------------------------------
	 10
	  9
	  8
	  7
	  6              W  W  W
	  5              B  B  B  B
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10
	--------------------------------------------------------------

	Player Black: 5, 5; 6, 5; 7, 5; 8, 5;

	Player 1 has won the game!

