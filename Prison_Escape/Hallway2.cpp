/********************************************************************
 ** Program Name: Hallway2.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Hallway2 class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Hallway2.hpp"

/*********************************************************************
  ** Function: Hallway2
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Hallway2::Hallway2() {

    name = "Hallway 2";
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Hallway2::special(Items inventoryIn[]) {

    string userIn;

    cout << "Well, this seems like an ordinary hallway... Nothing of impor.. " << endl;
    cout << "Oh shit! A map is mounted on the wall!" << endl;
    cout << "View map (y/n): ";
    cin >> userIn;

    if (userIn == "y") {

        cout << "           —-———————————— Armory ———————————————" << endl;
        cout << "           |                                   |" << endl;
        cout << "           |                                   |" << endl;
        cout << "        Kitchen	—————————————————————— Guard Break Room —————————" << endl;
        cout << "           |            Other Cell             |               |" << endl;
        cout << "           |                 |                 |               |" << endl;
        cout << "      Hallway 2  ————  Cell Hallway  ————  Hallway 1  ————  Laundry" << endl;
        cout << "           |                 |                 |               |" << endl;
        cout << "          Exit               |           Utility Closet  ——————" << endl;
        cout << "                             |                 " << endl;
        cout << "                       Main Cell Block" << endl;



    }
}