/********************************************************************
 ** Program Name: OtherCell.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for OtherCell class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "OtherCell.hpp"

/*********************************************************************
  ** Function: OtherCell
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
OtherCell::OtherCell() {

    name = "Another Cell";
    canEnter = false;
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void OtherCell::special(Items inventoryIn[]) {

    string userIn;

    // Run if Prison Buddy is already in group
    for (int i=0; i<8;i++) {
        if (inventoryIn[i].getName() == "Prison Buddy") {

            cout << "This is just an ordinary empty cell now that my buddy is with me." << endl;
            return;
        }
    }

    cout << "You find the least dangerous looking guy and whisper to get his attention." << endl;
    cout << "You ask if he wants to get out of here." << endl;
    cout << "He jumps up, excited about the prospect of getting out." << endl;
    cout << "Once you unlock his cell door, you extend your hand for a proper introduction." << endl;
    cout << "He pushes the hand away and gives you a tender hug while whispering, \"Thank you\" into your ear." << endl;
    cout << "Once he lets go, your eyes meet and for a brief second you can see into his soul; you feel something special." << endl;
    cout << "It might be easier to get out of here if we stick together." << endl;
    cout << "Ask other prisoner to join group? (y/n): ";
    cin >> userIn;



    if (userIn == "y") {
        for (int i=0; i<8;i++) {
            if (inventoryIn[i].getName() == "Item") {

                inventoryIn[i].setName("Prison Buddy");
                cout << endl << "Prison Buddy joined the group" << endl;
                break;
            }
        }
    }

}
