/********************************************************************
 ** Program Name: UtilityCloset.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for UtilityCloset class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef UtilityCloset_hpp
#define UtilityCloset_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class UtilityCloset : public Spaces {

protected:
    bool hasMasterKey;


public:
    UtilityCloset();
    void special(Items inventoryIn[]);
    
};
#endif /* UtilityCloset_hpp */
