/********************************************************************
 ** Program Name: Armory.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Armory class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Armory_hpp
#define Armory_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class Armory : public Spaces {

protected:


public:
    Armory();
    void special(Items inventoryIn[]);
    
};

#endif /* Armory_hpp */
