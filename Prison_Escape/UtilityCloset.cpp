/********************************************************************
 ** Program Name: UtilityCloset.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for UtilityCloset class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "UtilityCloset.hpp"

/*********************************************************************
  ** Function: UtilityCloset
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
UtilityCloset::UtilityCloset() {

    name = "the Utility Closet";
    hasMasterKey = false;
    canEnter = false;
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void UtilityCloset::special(Items inventoryIn[]) {

    string userIn;
    cout << "Cha-ching! One step closer from getting out of this hell hole." << endl;

    cout << "Take Master Key? (y/n): ";
    cin >> userIn;

    // Run if Master Key is already in inventory
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Master Key") {

            cout << "The Master Key is already in my inventory." << endl;
            hasMasterKey = true;
            break;
        }
    }

    if (userIn == "y" && hasMasterKey == false) {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("Master Key");
                cout << endl << "Master Key added to inventory" << endl;
                break;
            }
        }
    }

    cout << "Take Shovel? (y/n): ";
    cin >> userIn;

    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Shovel") {

            cout << "The Shovel is alreay in my inventory." << endl;
            return;
        }
    }

    if (userIn == "y") {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("Shovel");
                cout << endl << "Shovel added to inventory" << endl;
                break;
            }
        }
    }




}



