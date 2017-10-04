/********************************************************************
 ** Program Name: GuardBreakRoom.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for GuardBreakRoom class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "GuardBreakRoom.hpp"

/*********************************************************************
  ** Function: GuardBreakRoom
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
GuardBreakRoom::GuardBreakRoom() {

    name = "the Guard Break Room";
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void GuardBreakRoom::special(Items inventoryIn[]) {

    string userIn;

    cout << "I need to be more careful, I almost got killed." << endl;
    cout << "Well at least I can take the guards uniform. That should be of some use." << endl;
    cout << "Take Gaurd Uniform? (y/n): ";
    cin >> userIn;

    // Run if guard uniform is already in group
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Guard Uniform") {

            cout << "I've already took the uniform, but those boxers are pretty stylish..." << endl;
            return;
        }
    }

    if (userIn == "y") {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("Guard Uniform");
                cout << endl << "Guard Uniform added to inventory" << endl;
                break;
            }
        }
    }

}
