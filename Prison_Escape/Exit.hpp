/********************************************************************
 ** Program Name: Exit.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/15/16
 ** Description: Header file for Exit class
 ** Input: none
 ** OutPut: none
 ********************************************************************/


#ifndef Exit_hpp
#define Exit_hpp

#include "Spaces.hpp"
#include "HeaderAll.hpp"

class Exit : public Spaces {

protected:


public:
    Exit();
    void special(Items inventoryIn[]);
    
};

#endif /* Exit_hpp */
