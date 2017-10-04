/********************************************************************
 ** Program Name: Items.hpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Header file for Items class.
 ** Input: none
 ** OutPut: none
 ********************************************************************/

#ifndef Items_hpp
#define Items_hpp

#include "HeaderAll.hpp"
#include <stdio.h>

using std::string;


class Items {

private:
    string name;

public:
    Items();
    Items(string nameIn);
    string getName();
    void setName(string nameIn);

};

#endif /* Items_hpp */
