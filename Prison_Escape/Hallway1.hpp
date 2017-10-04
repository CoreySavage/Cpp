/********************************************************************
 ** Program Name: Hallway1.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Hallway1 class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Hallway1_hpp
#define Hallway1_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"
#include <stdio.h>

class Hallway1 : public Spaces {

protected:


public:
    Hallway1();
    void special(Items inventoryIn[]);
    
};
#endif /* Hallway1_hpp */
