/********************************************************************
 ** Program Name: YourCell
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for YourCell class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef YourCell_hpp
#define YourCell_hpp

#include "HeaderAll.hpp"
#include "Spaces.hpp"
#include <stdio.h>

class YourCell : public Spaces {

private:

public:
    YourCell();
    void special(Items inventoryIn[]);
    
};


#endif /* YourCell_hpp */
