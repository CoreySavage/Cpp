/********************************************************************
 ** Program Name: Map.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/12/16
 ** Description: Holds functions for the Map class.
 ** Input: All game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "Map.hpp"

/*********************************************************************
  ** Function: Map
  ** Description: Constructor for map class, creates and sets map.
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
Map::Map() {

    // Create blank inventory
    for (int i=0;i<8;i++) {

        Items* itms = new Items;
        inventory[i] = *itms;
    }


    // Set pointers to spaces
    current = &yc;

    yc.setNorth(&ch);
    yc.setSouth(NULL);
    yc.setEast(NULL);
    yc.setWest(NULL);

    ch.setNorth(&othr);
    ch.setSouth(&yc);
    ch.setEast(&hw1);
    ch.setWest(&hw2);

    othr.setNorth(NULL);
    othr.setSouth(&ch);
    othr.setEast(NULL);
    othr.setWest(NULL);

    hw1.setNorth(&gbr);
    hw1.setSouth(&uc);
    hw1.setEast(&ld);
    hw1.setWest(&ch);

    hw2.setNorth(&ktc);
    hw2.setSouth(&ext);
    hw2.setEast(&ch);
    hw2.setWest(NULL);

    gbr.setNorth(&arm);
    gbr.setSouth(&hw1);
    gbr.setEast(&ld);
    gbr.setWest(&ktc);

    uc.setNorth(&hw1);
    uc.setSouth(NULL);
    uc.setEast(&ld);
    uc.setWest(NULL);

    ld.setNorth(&gbr);
    ld.setSouth(&uc);
    ld.setEast(NULL);
    ld.setWest(&hw1);

    ktc.setNorth(&arm);
    ktc.setSouth(&hw2);
    ktc.setEast(&gbr);
    ktc.setWest(NULL);

    arm.setNorth(NULL);
    arm.setSouth(NULL);
    arm.setEast(&gbr);
    arm.setWest(&ktc);

    // Won game if in Exit, no need for other pointers
    ext.setNorth(NULL);
    ext.setSouth(NULL);
    ext.setEast(NULL);
    ext.setWest(NULL);



}

/*********************************************************************
  ** Function: getInventory
  ** Description: Prints inventory items to screen, numbered.
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Map::getInventory() {

    cout << "Inventory:" << endl;
    for (int i=0;i<8;i++) {
        if (inventory[i].getName() != "Item") {
            cout << i + 1 << ":     " << inventory[i].getName() << endl;
        }
    }
    cout << endl;
}

/*********************************************************************
  ** Function: addItem
  ** Description: Change temp Items name to desired string, based on input.
  ** Parameters: string
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Map::addItem(string ItemIn) {

    for (int i=0;i<8;i++) {
        if (inventory[i].getName() != "Item") {
            inventory[i].setName(ItemIn);
            return;
        }
    }
    // Run if inventory is full
    cout << "Inventory is full." << endl;


}

/*********************************************************************
  ** Function: beginGame
  ** Description: Runs game
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void Map::beginGame() {

    string userIn;
    bool caught = false;
    bool alreadySurvivedGBR = false;
    int maxRounds = 45;
    int currentRounds = 0;

    // Run until player escapes, rounds run out, or player gets caught
    while (current != &ext && currentRounds < maxRounds && caught == false) {

        cout << endl << "You are in " << current->getName(current) << ", what would you like to do?" << endl;
        cout << "a:         Inspect Room" << endl;
        cout << "b:         Move" << endl;
        cout << "c:         View Inventory" << endl;
        cin >> userIn;
        cout << endl;

        if (userIn == "a") {

            current->special(inventory);
            // Set player room access
            for (int i=0;i<8;i++) {
                if (inventory[i].getName() == "Cell Key") {

                    ch.setCanEnter(true);
                    othr.setCanEnter(true);
                }
                if (inventory[i].getName() == "Master Key") {

                    arm.setCanEnter(true);
                    ch.setCanEnter(true);
                    uc.setCanEnter(true);
                    ext.setCanEnter(true);
                }
                if (inventory[i].getName() == "Utility Closet Key") {

                    uc.setCanEnter(true);
                }

            }
        }
        else if (userIn == "b") {

            current = current->move(current);

            // Rooms with immediate effects run here
            if (current == &othr) {

                int joinChance = 30;
                int attackYouRisk = (rand() % 100) + 1;
                for (int i=0;i<8;i++) {

                    // Item modifiers
                    if (inventory[i].getName() == "Guard Uniform" ) {

                        joinChance += 80;
                    }
                    if (inventory[i].getName() == "M4 Carbine" ) {

                        joinChance += 60;
                    }
                    if (inventory[i].getName() == "Knife" ) {

                        joinChance += 20;
                    }
                    if (inventory[i].getName() == "Shovel" ) {

                        joinChance += 10;
                    }
                }
                if (joinChance <= attackYouRisk) {

                    cout << endl << "I asked another prisoner if he wants to get out of here with me." << endl;
                    cout << "He seemed pumped about the thought of getting out." << endl;
                    cout << "But the second I opened his cell door he knocked me out." << endl;
                    cout << "I woke up a few hours later in the infirmary, the other guy had escaped." << endl;
                    cout << "What a terrible idea." << endl;
                    caught = true;
                }
            }

            if (current == &ext) {

                int escapeChance = 10;
                int riskStrength = (rand() % 100) + 1;
                for (int i=0;i<8;i++) {
                    if (inventory[i].getName() == "Guard Uniform" ) {

                        escapeChance += 80;
                    }
                    if (inventory[i].getName() == "M4 Carbine" ) {

                        escapeChance += 50;
                    }
                    if (inventory[i].getName() == "Prison Buddy" ) {

                        escapeChance -= 50;
                    }
                }

                if (escapeChance <= riskStrength) {

                    cout << endl << "Well, I was able to get out the door." << endl;
                    cout << "But the gaurds in the towers spotted me the second I stepped out the door." << endl;
                    cout << "There has to be a way to get out of here.." << endl;
                    cout << "Maybe if I can find a way to blend in better..." << endl;
                    caught = true;
                }

            }

            if (current == &gbr && alreadySurvivedGBR == false) {

                cout << "The second I open the door my eyes meet with a fat elderly gaurd." << endl;
                cout << "He has a plate of donuts and pizza in front of him." << endl;
                cout << "What a slob." << endl;
                cout << "I move in to try and take him out, before his chubby finger can grab for his gun...." << endl;

                int survivalChance = 10;
                int guardStrength = (rand() % 100) + 1;
                for (int i=0;i<8;i++) {
                    if (inventory[i].getName() == "M4 Carbine" ) {

                        survivalChance += 60;
                    }
                    if (inventory[i].getName() == "Shovel" ) {

                        survivalChance += 10;
                    }
                    if (inventory[i].getName() == "Knife" ) {

                        survivalChance += 20;
                    }
                    if (inventory[i].getName() == "Prison Buddy" ) {

                        survivalChance += 20;
                    }
                }
                if (guardStrength < survivalChance) {

                    cout << endl << "Success! That was easier than expected." << " GS: " << guardStrength << " SC: " << survivalChance << endl;
                    alreadySurvivedGBR = true;
                }
                else {

                    cout << endl << "Well, that didn't work. He shot me in the shoulder before I could get to him." << endl;
                    cout << "In my defense, Porky moved like a gazelle." << endl;
                    cout << "Now I'm in the infirmary, surrounded with armed guards. No chance of getting out, for now." << endl;
                    cout << "Better start planning my next escape." << " GS: " << guardStrength << "SC: " << survivalChance << endl;
                    caught = true;

                }


            }
        }
        else if (userIn == "c") {

            getInventory();
        }
        else {

            // Player inputs invalid char
            cout << "Something went wrong, try again." << endl;
            cout << "Be more careful! (-1 turn)" << endl;
        }
        currentRounds++;
        // Warning for last 5 turns
        if (currentRounds > 39) {

            cout << maxRounds-currentRounds << " turns before you get caught!" << endl;
        }
    }

    // Run if lost
    if (caught == true) {

        cout << "You Lost." << endl;
    }
    // Run if won
    else {

        current->special(inventory);
        cout << "You Won." << endl;
    }
    
}









