/********************************************************************
 ** Program Name: Armory.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Armory class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Armory.hpp"

/*********************************************************************
  ** Function: Armory
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Armory::Armory() {

    name = "the Armory";
    canEnter = false;
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Armory::special(Items inventoryIn[]) {

    string userIn;

    cout << "Things are finally starting to turn my way." << endl;
    cout << "Take M4 Carbine? (y/n)" << endl;
    cin >> userIn;

    // Run if M4 Carbine is already in inventory
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "M4 Carbine") {

            cout << "I can't imagine the need for two M4s, plus carrying two will slow me down." << endl;
            return;
        }
    }

    if (userIn == "y") {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("M4 Carbine");
                cout << endl << "M4 Carbine added to inventory" << endl;
                break;
            }
        }
    }

}