
2 Opt Algorithm - Traveling Salesmen Problem
Corey Savage
------------------------------------------------

Uses a 2-opt algorithm to find an optimal path, when given a txt file of
    node with x and y coordinates


Usage Instructions
-------------------------------------------------
Compiling -
    g++ -std=c++11 two-opt.cpp -o two-opt

Executing - 
	./two-opt <file.txt>

Input File -
	Format:
		0   10  39
        1   5   9
        2   30  25

	First number is the node ID.
    Second number is x
    Third number is y

    Each number can be separated by any combination of spaces and tabs
    Every new node must start on new line


Normal Mode
-------------------------------------------------
No time limit. After 20 complete swaps of the list of nodes without finding an
    improved path, the program will export the results and exit.

Console Output:
    Start Distance
    Improvement Counter Increases
    Final Runtime


Competition Mode
-------------------------------------------------
3 minute time limit. Additionally, if after 20 complete swaps of the list of nodes without finding an
    improved path, the program will export the results and exit.

Console Output:
    Start Distance


Results
------------------------------------------------

Output File -
	Filename: <input filename>.txt.tour
	Format:
		14667               -   Total Distance
            0               -   Start Tour
            3
            2
            1
            4
            5               -   Must return to starting node [0]

