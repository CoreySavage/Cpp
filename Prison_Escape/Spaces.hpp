/********************************************************************
 ** Program Name: Spaces.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Spaces class
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Spaces_hpp
#define Spaces_hpp

#include "HeaderAll.hpp"
#include <stdio.h>




using std::string;

class Items;

class Spaces {
    
protected:
    Spaces* north;
    Spaces* south;
    Spaces* east;
    Spaces* west;
    string name;

    bool canEnter;


    
public:
    Spaces();
    virtual void special(Items inventoryIn[]) =0;
    bool getCanEnter();
    void setCanEnter(bool enterIn);
    void setMap();
    void setNorth(Spaces* spaceIn);
    void setSouth(Spaces* spaceIn);
    void setEast(Spaces* spaceIn);
    void setWest(Spaces* spaceIn);
    Spaces* move(Spaces*);
    string getName(Spaces*);


    
};

#endif /* Spaces_hpp */
