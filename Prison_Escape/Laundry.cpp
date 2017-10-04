/********************************************************************
 ** Program Name: Laundry
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Laundry class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Laundry.hpp"

/*********************************************************************
  ** Function: Laundry
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Laundry::Laundry() {

    name = "the Laundry Room";
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Laundry::special(Items inventoryIn[]) {

    string userIn;

    cout << "Ahh this places takes me back." << endl;
    cout << "My first job when I got here was in the Laundry Room." << endl;
    cout << "Nothing like the smell of freshly washed clothes." << endl;
    cout << "If I remember correctly, there's a key for the closet in the manager's desk." << endl;

    // Run if player already has Key
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Utility Closet Key") {

            cout << "I've already busted into the managers desk! Nothing to take but a few pens." << endl;
            return;
        }
    }

    for (int i=0;i<8;i++) {
        if (inventoryIn[i].getName() == "Knife") {

            cout << "And luckily, the knife I grabbed from the kitchen will definitely be able to pry that baby open." << endl;
            cout << "Pry desk open and retrieve Utility Closet Key? (y/n): ";
            cin >> userIn;

            if (userIn == "y") {
                for (int i=0; i<8;i++) {
                    if (inventoryIn[i].getName() == "Item") {
                        inventoryIn[i].setName("Utility Closet Key");
                        cout << endl << "Utility Closet Key added to inventory" << endl;
                        return;
                    }
                }
            }

        }
    }
    // Run if player doesnt have the Knife in their inventory
    cout << "All I have to do is find something to pry the drawer open." << endl;
}