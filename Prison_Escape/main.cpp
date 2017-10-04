/********************************************************************
 ** Program Name: main.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/10/16
 ** Description: Main file for Prison Escape!
 ** Input: (y/n) 
 ** OutPut: All Game output messages up to the game starting
 ********************************************************************/

#include "HeaderAll.hpp"
#include "Spaces.hpp"
#include "YourCell.hpp"
#include "CellHallway.hpp"
#include "Map.hpp"

int main(int argc, const char * argv[]) {

    srand(time(NULL));

    // User inputs
    string beginGame;
    string userInput;
    string viewGoal;

    // Start Screen
    cout << "           Prison Escape!" << endl << endl;
    cout << "Welcome! In the game Prison Escape there are multiple ways to escape," << endl;
    cout << "but there are also multiple ways to get caught." << endl;
    cout << "As with real prison escapes, there is no guaranteed method of success. " << endl;
    cout << "However, you actions greatly dictate your likelihood of success or failure." << endl;
    cout << "Proceed with caution." << endl << endl << endl;


    cout << "Would you like to view the win requirment for Prison Escape? (y/n): ";
    cin >> viewGoal;

    if (viewGoal == "y") {

        cout << "The goal of the game is to escape prison with a limited number of turns (45), without getting caught." << endl;
        cout << "Actions such as Inspecting Rooms, Moving, and Viewing Inventory all will cost a turn." << endl;
        cout << "Certain rooms will require a key to unlock them, some rooms can even get the player caught or killed." << endl << endl;
    }

    cout << "Would you like to begin the game? (y/n): ";
    cin >> beginGame;

    // Begin Game
    if (beginGame == "y") {

        Map m1;
        // Start message
        cout << endl << "Ugh I can’t it any longer! Today is the day I get out of this place." << endl;
        cout << "All I have to do, is just get out of this cell…" << endl;
        cout << "and then… umm… I’m sure I’ll figure it out." << endl;
        cout << "I know this isn’t the most fleshed out plan, but I’ve figured one thing out." << endl;
        cout << "Yesterday in the yard, I was able to swipe the key to the cells from a bozo cop." << endl;
        cout << "But in celebration, I got smashed off of toliet wine and now I don’t remember where I hid the key." << endl;

        m1.beginGame();


    }


    return 0;
}
