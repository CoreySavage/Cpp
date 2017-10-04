
Making Change Algorithms
Corey Savage
------------------------------------------------

Uses both a greedy and dynamic programming algorithm for calculating the optimal change 


Usage Instructions
-------------------------------------------------
Compiling - 
	g++ makeChange.cpp -o makeChange

Executing - 
	./makeChange file.txt

Input File -
	Format:
		1 3 5 7 9				- coin values			
		29					- amount to make change
		1 6 9 10 23
		89
		1 2 4 8
		15
		1 3 7 12
		29

	Odd rows must contain list of coin values (1 required to ensure solution)
	Even rows must contain the amount of change required


Results
------------------------------------------------

Output File -
	Filename: <input filename>change.txt
	Format:
		Algorithm changegreedy:
		1 2 4 8 				- Coin value data 
		1 1 1 1 				- number of individual coins required 
		4					- minimum number of coins required
		1 3 7 12 				- Coin value data
		2 1 0 2 				- number of individual coins required 
		5					- minimum number of coins required
		Algorithm changedp:
		1 2 4 8 
		1 1 1 1 
		4
		1 3 7 12 
		0 1 2 1 
		4

Console Output -
	Format: 
		Algorithm changegreedy:
		A= 15 time = 0.000023			- A= amount, time = runtime in seconds
		A= 29 time = 0.000005
		Algorithm changedp:
		A= 15 time = 0.000081
		A= 29 time = 0.000147