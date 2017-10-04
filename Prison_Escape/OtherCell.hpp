/********************************************************************
 ** Program Name: OtherCell.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for OtherCell class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef OtherCell_hpp
#define OtherCell_hpp

#include "HeaderAll.hpp"
#include "Spaces.hpp"
#include <stdio.h>

class OtherCell : public Spaces {

private:

public:
    OtherCell();
    void special(Items inventoryIn[]);
    
};

#endif /* OtherCell_hpp */
