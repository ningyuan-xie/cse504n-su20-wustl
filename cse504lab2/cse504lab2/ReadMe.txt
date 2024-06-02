Ningyuan Xie CSE 504N Lab 2

Errors/warnings：

I did not run into as many errors/wanings as I expected in this lab, as I created my codes and tested them 
step by step immediately, so by the time I reach "main", most of the steps seem to work out. This time,
most of my time was used to understand what the instructions mean.

1. In Step 11, initially I did not understand how to use ifstream& as a function parameter, so I ran into
   an error and cannot open my txt file. Eventually I figured that out.

2. During Step 12, my server broke down and it said "No space left on device" and I cannot build my project
   anymore. I asked that question on Piazza and was told by Professor Shidal to disconnect, so I went to 
   sleep and continue my work tomorrow.

3. In Step 13 where I should print out the game board (essentially a vector containing my object 
   <Game_Pieces>), I ran into an error called "no operator << match these operands", because I forgot 
   that vector can only print out member variables of an object, and I was trying to print out the whole
   object directly.


Test cases I run:

1. command line: "H:\CSE_504N_Lab2\cse504lab2\x64\Debug>cse504lab2.exe"
   I did not correctly input a file name. The program correctly printed out an instruction: 
   "usage: cse504lab2.exe <input_file_name>"

2. command line: "H:\CSE_504N_Lab2\cse504lab2\x64\Debug>cse504lab2.exe tic-tac-toe.txt"
   I tested the standard file "tic-tac-toe.txt". The program correctly printed out:
   ----------- Game Board -----------
   ----------------------------------
   X X X

     X

   X

   -----------------------------------

3. command line: "H:\CSE_504N_Lab2\cse504lab2\x64\Debug>cse504lab2.exe gomoku.txt"
   I tested the standard file "gomoku.txt". The program correctly printed out:

	----------- Game Board -----------
	----------------------------------
	  O   O   O   O

	O   O   O   O

	  O   O   O   O





	X   X   X   X

	  X   X   X   X

	X   X   X   X

	-----------------------------------

4. command line: "H:\CSE_504N_Lab2\cse504lab2\x64\Debug>cse504lab2.exe Test_1.txt"
   I tested a non-standard file of "tic-tac-toe.txt", where I added blanks/spaces within and between original
   lines. My program managed to skip all the blanks/spaces and print the same result as before.

5. command line: "H:\CSE_504N_Lab2\cse504lab2\x64\Debug>cse504lab2.exe Test_2.txt"
   I tested another non-standard file of "tic-tac-toe.txt", where I modified some coordinates so that they
   reach out of the dimensions, and I modified some name so that they are invalid.
   My program correctly ignored all the wrong game pieces and only printed the legal ones.
   

------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------

Extra Credit Section

1. Design and Implementation:

   I designed the function "print_game_board_Extra" based on the previous function "print_game_board".

   To begin with, instead of printing out "display", this function first prints out every non-empty game pieces 
   along with their coordinates, colors, and names. The print out order is: lower-left, lower, lower-right, left, 
   right, top-left, top, top right.

   Next, after a game piece is printed and before it prints the next one, this function checks its 8 neighbors also 
   in the order of: lower-left, lower, lower-right, left, right, top-left, top, top right. For each neighbor, if its 
   coordinates are within the game board and is not an empty square, this neighbor will be printed out.

2. Test 

   To ensure that the program is rigorous, I tested it with cases involving squares in the corners, on the edges, 
   and in the middle of the board. Therefore, I use the "tic-tac-toe.txt" file, because it contains all three cases 
   mentioned above:

   ----------- Game Board -----------
   ----------------------------------
   X X X

     X

   X

   -----------------------------------

   My function "print_game_board_Extra" printed out:

   -------------------- Game Board (Extra Credit) ----------------------
   ---------------------------------------------------------------------
   0,0 red Xs: 1,1 red Xs;
   1,1 red Xs: 0,0 red Xs; 0,2 red Xs; 1,2 red Xs; 2,2 red Xs;
   0,2 red Xs: 1,1 red Xs; 1,2 red Xs;
   1,2 red Xs: 1,1 red Xs; 0,2 red Xs; 2,2 red Xs;
   2,2 red Xs: 1,1 red Xs; 1,2 red Xs;
   ----------------------------------------------------------------------

   Finally, I verify the printed result with the actual game board: 
   In the original game board, there are 5 red game pieces at: (0,0),(1,1),(0,2),(1,2),(2,2), which is correctly 
   printed. For each of these 5 game pieces, we can manully check that:
   
   (0,0) has 1 neighbor at top right(1,1);
   (1,1) has 4 neighbors at lower-left(0,0), top-left(0,2), top(1,2), and top-right(2,2);
   (0,2) has 2 neighbors at lower-right(1,1), right(1,2);
   (1,2) has 3 neighbors at lower(1,1), left(0,1),right(2,2);
   (2,2) has 2 neighbors at lower-left(1,1), left(1,2);

   These results match what what my function "print_game_board_Extra" printed out. Therefore, this function works
   correctly with cases involving squares in the corners, on the edges, and in the middle of the board.
