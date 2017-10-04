/********************************************************************
 ** Program Name: YouCell.cpp
 ** Author: Corey Savage - SavageCo-OregonState.edu
 ** Date: 3/13/16
 ** Description: Functions for YourCell class
 ** Input: Game inputs
 ** OutPut: Game outputs
 ********************************************************************/

#include "YourCell.hpp"

/*********************************************************************
  ** Function: YourCell
  ** Description: Default Constructor
  ** Parameters: none
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
YourCell::YourCell() {

    name = "Your Cell";
    
}

/*********************************************************************
  ** Function: special
  ** Description: Special
  ** Parameters: Array of Items
  ** Pre-Conditions: none
  ** Post-Conditions: none
  *********************************************************************/
void YourCell::special(Items inventoryIn[]) {

    string userIn;
    bool keepLooking = true;

    cout << "Everything looks about same since I left it." << endl;
    cout << "There's my lumpy stain covered mattress, my sink, and my favorite part of the cell my trusty toliet!" << endl;

    while (keepLooking == true) {
        cout << endl << "Where should I look?" << endl;
        cout << "a:         Mattress" << endl;
        cout << "b:         Sink" << endl;
        cout << "c:         Toliet" << endl;
        cout << "d:         Return to Action Menu" << endl;
        cin >> userIn;


        if (userIn == "a") {

            cout << endl;
            cout << "I've been sleeping on this same twin mattress for the last 22 years." << endl;
            cout << "But the last couple years I haven't been able to sleep." << endl;
            cout << "The pain in my back is worse than ever, and I can't sleep on this goddamn rock!" << endl;
            cout << "Now with La Nuestra after me, I have to get out of here." << endl << endl;

            cout << "I look under the mattress for the key, but there's only a few nudie mags and a few old letters." << endl;

        }
        else if (userIn == "b") {

            cout << endl;
            cout << "The past week I haven't even been able to look at the sink." << endl;
            cout << "There's still blood stains from the fight." << endl;
            cout << "I'm sick with myself that I killed that kid, but I'm not letting anyone stick anything up my butt." << endl << endl;

            // Run if Cell Key is already in inventory
            for (int i=0; i<8;i++) {
                if (inventoryIn[i].getName() == "Cell Key") {

                    cout << "I've already found the cell key, I need to hurry and get out of here!" << endl;
                    return;
                }
            }

            cout << "I look in the sink bowl, but its empty." << endl;
            cout << "But underneath, I drag my fingers under the bottom lip and feel a metal object." << endl;
            cout << "After a few moments of struggling I get the key free from the sink" << endl;

            for (int i=0; i<8;i++) {
                if (inventoryIn[i].getName() == "Item") {
                    inventoryIn[i].setName("Cell Key");
                    cout << endl << "Cell Key added to inventory" << endl;
                    break;
                }
            }
        }
        else if (userIn == "c") {

            cout << endl;
            cout << "Ah, my only real friend in here." << endl;
            cout << "This toliet has gotten me through some of the worst food I've ever had." << endl << endl;

            cout << "I search the bowl and the water tank, but I cant find anything." << endl;
        }
        else if (userIn == "d") {

            keepLooking = false;
        }
}
}

