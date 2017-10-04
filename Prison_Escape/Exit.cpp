/********************************************************************
 ** Program Name: Exit.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Exit class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Exit.hpp"

/*********************************************************************
  ** Function: Exit
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Exit::Exit() {

    name = "Exit";
    canEnter = false;
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Exit::special(Items inventoryIn[]) {

    // Run once game has been won
    cout << endl << "You walk out of the door like you own the prison." << endl;
    cout << "Calmly you cross the yard, until you get to the outter fense." << endl;
    cout << "That fense is all that seperates you from freedom." << endl;
    cout << "With haste you jump the fense, hopping over your last obsticle." << endl;
    cout << "You dart into the nearby woods, running until you can run no longer." << endl;
    cout << "In the distance you start hearing the faint sounds of alarms," << endl;
    cout << "but all you can think about right now is a plate of pancakes..." << endl;

}