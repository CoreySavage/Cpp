/********************************************************************
 ** Program Name: GuardBreakRoom.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for GuardBreakRoom class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef GuardBreakRoom_hpp
#define GuardBreakRoom_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class GuardBreakRoom : public Spaces {

protected:


public:
    GuardBreakRoom();
    void special(Items inventoryIn[]);
    
};
#endif /* GuardBreakRoom_hpp */
