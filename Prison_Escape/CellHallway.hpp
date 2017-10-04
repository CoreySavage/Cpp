/********************************************************************
 ** Program Name: CellHallway.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for CellHallway class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef CellHallway_hpp
#define CellHallway_hpp

#include "HeaderAll.hpp"
#include "Spaces.hpp"
#include <stdio.h>
#include "Items.hpp"

class CellHallway : public Spaces {

protected:


public:
    CellHallway();
    void special(Items inventoryIn[]);
    
};


#endif /* CellHallway_hpp */
