Ningyuan Xie CSE 504N Lab 3

Errors/warnings：

1. I did not run into any major error/warnings during the lab. There are cases like typo, forgetting a ";" at the end of the 
   line, accidently calling the same method twice, etc.

2. I often forgot the "quit" my program in console before rebuilding my project. Therefore, I frequently encounter an error:
   "LNK1168 cannot open H:\CSE_504N_Lab3\cse504lab3\Debug\cse504lab3.exe for writing"


Test cases I run:

1. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe"
   I did not correctly input a argument name. The program correctly printed out an instruction: 
   "usage: cse504lab3.exe <TicTacToe>"


2. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe test"
   I did not input the right argument name. Again, the program correctly printed out an instruction: 
   "usage: cse504lab3.exe <TicTacToe>"


3. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe TicTacToe"
   I correctly input the right argument name. The program opens the game and asks for input:

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

After the program started the game:

4. If I input correctly formatted input <x,y>, program will move a game piece to the right square. For example, I typed in
   <2,2>:

	- Game Board -
	--------------
	4
	3
	2    X
	1
	0
	 0 1 2 3 4
	--------------

	Player X: 2, 2;

	Now it's O's turn.
	What do you want to input next? Type <x,y> to input a piece; or type <quit> to esc.
	Input:


5. If I did not input a correctly formatted input <x,y>, for example: <2-2>, an instruction will pop out:
   "Please input in the format of <x,y>."


6. If I typed a coordinate outside of the game board, for example: <1,4>, an instruction will pop out:
   "Please enter a y coordinate between 1 and 3."


7. If I typed <quit> after 1 move during the game, the game will quit immediately with an instruction:
   "1 turn(s) were played, and user has asked to quit."


8. If under some situations, player X or O won the game, the result will be:

	- Game Board -
	--------------
	4
	3  X   X
	2    X
	1  O O O
	0
	 0 1 2 3 4
	--------------

	Player O: 1, 1; 2, 1; 3, 1;

	Player O has won the game!


9. If under some situations, the game reaches a draw, the result will be:

	- Game Board -
	--------------
	4
	3  O X X
	2  X O O
	1  X O X
	0
	 0 1 2 3 4
	--------------

	Player X: 1, 1; 1, 2; 2, 3; 3, 1; 3, 3;

	9 turns were played, and no winning moves remain.


------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------

Extra Credit Section


Design and Implementation:

	I created three new functions: auto_player(), turn_auto(), play_auto(). The last two functions are based on my 
	previous turn() and play() functions. These functions are defined in "Extra_Credit.cpp".

	The auto_player() is the most complex function, because it acts as "AI" to counter user's play by determining 
	the optimal move for any turn to win the game. For simplicity, I only designed auto_player() to act as 
	"Player O". Because "Player O" moves second, in theory it cannot win against perfect "Player X" (only win 
	if "Player X" makes mistakes), so it should try its best to draw.

	Specifically, "Player O" has four turns:

	Turn 2: "Player O" should take the center if possible. If not, it should at least take a corner (taking edge 
	will inevitable lose, so it is not an optimal move).

	Turn 4: "Player O" should block any square that allows "Player X" to triple.

	Turn 6: "Player O" should first check if it has any chance to triple. If not, it should block any square that 
	allows "Player X" to triple (same as Turn 4).

	Turn 8: Same as Turn 6.

	For Turn 4-Turn 8, I used pencil and paper to manually determine what is "Player O" 's optimal move under all 
	kinds of situations, before writing them as code. I admit that due to time constraint, I might not cover all 
	the situations perfectly. 

	Finally, the perfect result should be: the user should never win against "Player O"; if the user plays 
	perfectly, "Player O" should never win against user. Therefore, the game should always results in draw.


Test and Results

1. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe"
   command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe test"
   command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe TicTacToe test"
   
   In these cases, I did not correctly input a name; I did not input the 1st argument correctly;
   I did not input the 2nd argument correctly. The program will prints out an instruction: 
   "usage: cse504lab3.exe <TicTacToe>
    usage(auto player): cse504lab3.exe <TicTacToe> <auto_player>"


2. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe TicTacToe"
   I only input the 1st argument correctly. The program will execute the default version of the game:

	You are now playing 'TicTacToe' created by Ningyuan Xie. Enjoy!
	---------------------------------------------------------------
	You chose version 1 (manual) of the game.
	-----------------------------------------

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


3. command line: "H:\CSE_504N_Lab3\cse504lab3\Debug>cse504lab3.exe TicTacToe auto_player" 
   I input both arguments correctly. The program will execute the second version of the game:

	You are now playing 'TicTacToe' created by Ningyuan Xie. Enjoy!
	---------------------------------------------------------------
	You chose version 2 (auto player) of the game.
	----------------------------------------------

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


4. Below is a case where "Player O" beats me. Notice that "Player O" can block and counter-act towards my
   every move.

	Now it's O's turn.

	- Game Board -
	--------------
	4
	3  X   X
	2  X X O
	1  O O O
	0
	 0 1 2 3 4
	--------------

	Player O has won the game!


5. Below is a case where "Player O" and I draw. Same as last time, "Player O" can block and counter-act towards 
   my every move.

	- Game Board -
	--------------
	4
	3  O O X
	2  X X O
	1  O X X
	0
	 0 1 2 3 4
	--------------

	Player X: 2, 2; 3, 1; 1, 2; 3, 3; 2, 1;

	9 turns were played, and no winning moves remain.


6. Aother case where "Player O" beats me:

	Now it's O's turn.

	- Game Board -
	--------------
	4
	3  O   X
	2    O
	1  X X O
	0
	 0 1 2 3 4
	--------------

	Player O has won the game!


7. I did not manage to beat my "Player O" yet, which is a positive sign that my program is good at determining
   the optimal move for every turn. You are welcome to try and enjoy my game!
