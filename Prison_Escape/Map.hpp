/********************************************************************
 ** Program Name: Map.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Map class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Map_hpp
#define Map_hpp

#include "HeaderAll.hpp"
#include "Spaces.hpp"
#include "YourCell.hpp"
#include "CellHallway.hpp"
#include "Hallway1.hpp"
#include "Hallway2.hpp"
#include "GuardBreakRoom.hpp"
#include "UtilityCloset.hpp"
#include "Laundry.hpp"
#include "Kitchen.hpp"
#include "Armory.hpp"
#include "Items.hpp"
#include "Exit.hpp"
#include "OtherCell.hpp"


#include <stdio.h>
using std::string;

class Map {

private:
    YourCell yc;
    CellHallway ch;
    Hallway1 hw1;
    Hallway2 hw2;
    GuardBreakRoom gbr;
    UtilityCloset uc;
    Laundry ld;
    Kitchen ktc;
    Armory arm;
    Exit ext;
    OtherCell othr;

    Spaces* current;
    Items inventory[8];

public:
    Map();
    string getCurrentName();

    void getInventory();
    void removeItem(int inventoryNum);
    void addItem(string itemIn);
    void beginGame();




};

#endif /* Map_hpp */
