/********************************************************************
 ** Program Name: Kitchen.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Kitchen class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Kitchen_hpp
#define Kitchen_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class Kitchen : public Spaces {

protected:


public:
    Kitchen();
    void special(Items inventoryIn[]);
    
};

#endif /* Kitchen_hpp */
