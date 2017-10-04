/********************************************************************
 ** Program Name: Kitchen.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Kitchen class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Kitchen.hpp"

/*********************************************************************
  ** Function: Kitchen
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Kitchen::Kitchen() {

    name = "the Kitchen";
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Kitchen::special(Items inventoryIn[]) {

    string userIn;

    cout << "Wow, this kitchen is pretty impressive for how little cooking they do here." << endl;
    cout << "Instant eggs, instant mashed potatoes, and bread. Thats been my life for 22 grueling years." << endl;
    cout << "They didn't even have the decency to toast the bread! 22 years of untoasted white bread." << endl;
    cout << "The first thing I do when I get out of here is get myself a nice meal." << endl;
    cout << "But first, I have to get out.. Lets see here.. What could be useful?" << endl;
    cout << "Plates, bowls, spoons, forks, butter knifes.. It's all useless." << endl;

    // Run if Knife is already in inventory
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Knife") {

            cout << "The Knife is alreay in my inventory, and I dont see anything else of use. I better move on." << endl;
            return;
        }
    }
    cout << "Ooo cooking knifes, these could come of use." << endl;
    cout << "Take Cooking Knife? (y/n): ";
    cin >> userIn;



    if (userIn == "y") {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("Knife");
                cout << endl << "Knife added to inventory" << endl;
                break;
            }
        }
    }

}