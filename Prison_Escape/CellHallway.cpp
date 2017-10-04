/********************************************************************
 ** Program Name: CellHallway.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for CellHallway class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "CellHallway.hpp"

/*********************************************************************
  ** Function: CellHallway
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
CellHallway::CellHallway() {

    name = "the Cell Hallway";
    canEnter = false;
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void CellHallway::special(Items inventoryIn[]) {

    cout << "You hear the rumblings of the other prisoners." << endl;
    cout << "It might be a good idea to get another prisoner to help with the escape, I could use all the help that I can get." << endl;
}