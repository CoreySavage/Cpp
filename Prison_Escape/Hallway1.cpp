/********************************************************************
 ** Program Name: Hallway1.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Hallway1 class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Hallway1.hpp"

/*********************************************************************
  ** Function: Hallway1
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Hallway1::Hallway1() {

    name = "Hallway 1";
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Hallway1::special(Items inventoryIn[]) {

    cout << "Nothing peculiar about a hallway. I should carry on." << endl;
}

