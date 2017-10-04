/********************************************************************
 ** Program Name: Laundry.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Laundry class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Laundry_hpp
#define Laundry_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class Laundry : public Spaces {

protected:


public:
    Laundry();
    void special(Items inventoryIn[]);
    
};

#endif /* Laundry_hpp */
