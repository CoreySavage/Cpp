/********************************************************************
 ** Program Name: Items.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for Items class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#include "Items.hpp"

/*********************************************************************
  ** Function: Items
  ** Description: Default constructor for Items, sets default name.
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Items::Items() {

    name = "Item";
}

/*********************************************************************
  ** Function: Items
  ** Description: Constructor for Items, sets name based on input.
  ** Parameters: string
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Items::Items(string nameIn) {

    name = nameIn;
}

/*********************************************************************
  ** Function: getName
  ** Description: Returns name
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
string Items::getName() {

    return name;
}

/*********************************************************************
  ** Function: setName
  ** Description: Sets the name variable, based on input.
  ** Parameters: string
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Items::setName(string nameIn) {

    name = nameIn;
}
