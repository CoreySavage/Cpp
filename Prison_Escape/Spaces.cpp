/********************************************************************
 ** Program Name: Spaces.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Spaces class
 ** Input: Direction input
 ** OutPut: Game output
 ********************************************************************/

#include "Spaces.hpp"

/*********************************************************************
  ** Function: Spaces.hpp
  ** Description: Default constructor, sets pointers to NULL
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Spaces::Spaces() {

    north = NULL;
    south = NULL;
    east = NULL;
    west = NULL;
    // Room unlocked by default
    canEnter = true;

}

/*********************************************************************
  ** Function: getCanEnter
  ** Description: return canEnter
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
bool Spaces::getCanEnter() {

    return canEnter;
}

/*********************************************************************
  ** Function: setNorth
  ** Description: Sets direction based on input.
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Spaces::setNorth(Spaces* spaceIn) {

    north = spaceIn;
}

/*********************************************************************
  ** Function: setSouth
  ** Description: Sets direction based on input.
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Spaces::setSouth(Spaces* spaceIn) {

    south = spaceIn;
}

/*********************************************************************
  ** Function: setEast
  ** Description: Sets direction based on input.
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Spaces::setEast(Spaces* spaceIn) {

    east = spaceIn;
}

/*********************************************************************
  ** Function: setWest
  ** Description: Sets direction based on input.
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Spaces::setWest(Spaces* spaceIn) {

    west = spaceIn;
}

/*********************************************************************
  ** Function: move
  ** Description: Moves player around map
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Spaces* Spaces::move(Spaces* currentIn) {

    string userMove;

    cout << "Direction:" << endl;
    cout << "a:         Go North (" << north->getName(north) << ")" << endl;
    cout << "b:         Go South (" << south->getName(south) << ")" << endl;
    cout << "c:         Go East (" << east->getName(east) << ")" << endl;
    cout << "d:         Go West (" << west->getName(west) << ")" << endl;
    cin >> userMove;

    if (userMove == "a") {

        // Run if player attempts to go towards a "Dead End"
        if (north == NULL) {

            cout << endl << "There's no where to go in this direction." << endl;
            return currentIn;
        }
        else {
            if (north->canEnter == true) {
                return north;
            }
            // Run if player can not yet access the door
            else {
                cout << endl << "The door is locked, there must be a key somewhere." << endl;
                return currentIn;
            }
        }
    }
    else if (userMove == "b") {

        if (south == NULL) {

            cout << endl << "No where to go in that direction." << endl;
            return currentIn;
        }
        else {
            if (south->canEnter == true) {
                return south;
            }
            else {
                cout << endl << "The door is locked, there must be a key somewhere." << endl;
                return currentIn;
            }
        }
    }
    if (userMove == "c") {

        if (east == NULL) {

            cout << endl << "I'm pretty sure this is just a wall." << endl;
            return currentIn;
        }
        else {
            if (east->canEnter == true) {
                return east;
            }
            else {
                cout << endl << "The door is locked, there must be a key somewhere." << endl;
                return currentIn;
            }
        }
    }
    if (userMove == "d") {

        if (west == NULL) {

            cout << endl << "This way seems to be a dead end." << endl;
            return currentIn;
        }
        else {
            if (west->canEnter == true) {
                return west;
            }
            else {
                cout << endl << "The door is locked, there must be a key somewhere." << endl;
                return currentIn;
            }
        }
    }

    return currentIn;

}

/*********************************************************************
  ** Function: getName
  ** Description: Returns name, if pointer == NULL return "Dead End"
  ** Parameters: Spaces pointer
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
string Spaces::getName(Spaces* currentIn) {

    if (currentIn != NULL) {

        return name;
    }
    // Run if pointer == NULL
    return "Dead End";
}

/*********************************************************************
  ** Function: setCanEnter
  ** Description: Sets bool variable
  ** Parameters: bool
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Spaces::setCanEnter(bool enterIn) {

    canEnter = enterIn;
}









