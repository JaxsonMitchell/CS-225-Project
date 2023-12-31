/******************************************************************************
* fileName: StartGame.cpp
* The file is the main script for the game containing the dialogue and battles.
*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include "battlers.h"
#include "battle.h"

using namespace std;

int main() {
    // Initialization and seeding a random number generator.
    srand(time(NULL));
    int i;

    cout<<"Once upon a time..."<<endl;
    sleep(2);
    cout<<"Four Adventures walk into the bar and the bartender says:"<<endl;
    sleep(3);
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Ay-yO WhAT are YE NAMEs?", 30);
    printf("\e[0m");
 
    /*******************************************************************************
     * New adventurers
    *******************************************************************************/
    Wizard* wizard = new Wizard;
    Knight* knight = new Knight;
    Rogue* rogue = new Rogue;
    Priest* priest = new Priest;

    
    vector<Adventurer*> adventurers;
    adventurers.push_back(wizard);
    adventurers.push_back(knight);
    adventurers.push_back(rogue);
    adventurers.push_back(priest);
    
    string wizardName = wizard->getName();
    string knightName = knight->getName();
    string rogueName = rogue->getName();
    string priestName = priest->getName();
    
    /*******************************************************************************
     * Beginning Text
    *******************************************************************************/
    printf("\e[0;33m \n"); //yellow font
    displayStringLikeText("ThAts...", 30);
    sleep(1);
    displayStringLikeText("...nice...", 30);
    sleep(1);
    displayStringLikeText("Any ways. It appeares that I have lost my", 30);
    printf("\e[1;35m"); //purple font
    displayStringLikeText("SALT SHAKER!", 5);
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Would you be kind enough to find it for me?", 30);
    printf("\e[0m \n");
   
    cout<< knightName << " the knight replies with ";
    printf("\e[0;36m"); //blue font
    displayStringLikeText("What..? Salt..? Of course not.", 10);
    
    
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Why thank YE for accepting my quest to find the", 30);
    printf("\e[1;35m"); //purple font
    displayStringLikeText("SALT SHAKER!", 5);
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Better be on your way then", 30);
    displayStringLikeText("Bye bye!!", 100);
    printf("\e[0m \n");

    cout<<"and so";
    for (i = 0; i < (adventurers.size() - 1); i++) {
        cout<<" "<<adventurers[i]->getName()<<",";
        
    }
    cout<<" and "<< adventurers[i]->getName()
        <<" all walk out of the bar and into..."<<endl;
    
    sleep(2);
    cout << "A mob of Gnomes..? Trying to get into the adventurers way!!!" << endl;
    printf("\e[1;31m"); // Red font
    displayStringLikeText("We are GNOMEAGEDDON!", 5);
    printf("\e[0m"); // Resets
    cout << "The gnomes coalesce into a monstrosity never gazed upon by mankind." << endl;
    
    /***************************************************************************
     * Start of battle 1
    ***************************************************************************/

    Gnomeageddon* gnomes = new Gnomeageddon;
    
    vector<Monster*> gnome;
    gnome.push_back(gnomes);


    Battle battle1(adventurers, gnome);
    battle1.fight();
    cout << endl << endl;

    cout << rogueName << ": ";
    printf("\e[1;34m"); //blue font
    displayStringLikeText("Wow, let's hope nothing else bad happens! ", 15);
    printf("\e[0m \n");

    cout << priestName << ": ";
    
    printf("\e[1;35m"); //purple font
    displayStringLikeText("DON'T SAY THAT!", 15);
    printf("\e[0m \n");
    /***************************************************************************
     * End of battle 1
     **************************************************************************/

    cout << "The adventurers trip on 32 geese and stumble into the circus..?" << endl;
    sleep(2);
    
    cout << endl << "Ringleader: ";
    printf("\e[1;33m"); // Yellow
    displayStringLikeText("Well well well... what do we have here?", 10);
    printf("\e[0m \n");
    sleep(1);
    
    cout << "Not The Joker: ";
    printf("\e[1;31m"); // Red font
    displayStringLikeText("Why HELLO! Why... So... SERIOUS!", 10);
    printf("\e[0m");

    vector<Monster*> circus;

    Lion* lion = new Lion;
    Ringleader* ringleader = new Ringleader;
    Clown* clown = new Clown;
    
    circus.push_back(lion);
    circus.push_back(ringleader);
    circus.push_back(clown);
    
    /***************************************************************************
     * Start of battle 2
     **************************************************************************/
    Battle battle2(adventurers, circus);
    battle2.fight();
    sleep(2);
    cout << "The adventurers escape all the cringey jokes and stumble into..." << endl;
    /***************************************************************************
     * End of battle 2
     **************************************************************************/
    sleep(2);
    cout << "A Swamp?" << endl;
    sleep(3);
    cout << "\nAfter wandering the swamp for a while the party is approached by the figures." << endl;
    sleep(2);
    cout <<endl<< "Non-Descript Ogre: ";
    printf("\e[1;32m"); // Green
    displayStringLikeText("Look at what we have here, a group of Adventurers in MY SWAMP?",10);
    displayStringLikeText("You must be looking for that barkeeps Salt Shaker.", 10);
    printf("\e[0m \n");
    sleep(1);
    cout << "Non-Descript Ogre: ";
    printf("\e[1;32m"); // Green
    displayStringLikeText("Well you can't have it!!", 10);
    displayStringLikeText("This is MY SWAMP and you are tresspassing.", 10);
    sleep(1);
    displayStringLikeText("And tresspassers make a great stew.", 10);
    printf("\e[0m \n");
    /***************************************************************************
     * Start of battle 3
     **************************************************************************/  

    vector<Monster*> swamp;
    
    CatInBoots* cat = new CatInBoots;
    NondescriptOgre* ogre = new NondescriptOgre;
    Jackass* jackass = new Jackass;

    swamp.push_back(cat);
    swamp.push_back(ogre);
    swamp.push_back(jackass);
    Battle battle3(adventurers, swamp);
    

    battle3.fight();

    /***************************************************************************
     * End of battle 3
     **************************************************************************/    
    cout<<"The adventurers finally make it out of the swamp alive and arrive at..."<<endl;
    sleep(3);
    printf("\e[1;35m");
    displayStringLikeText("THE DRAGON'S LAIR!!!", 5);
    printf("\e[0m\n");
    sleep(3);
    cout<<"They end up face to face with a ferocious beast..."<<endl;
    sleep(3);
    cout<<"A DRAGON!!!"<<endl;
    sleep(3);
    cout << knightName << ": ";
    printf("\e[0;36m");
    displayStringLikeText("AAAAAAAAAAAAAAAAA!!", 8);
    printf("\e[0m");
    
    
    vector<Monster*> dragonDen;

    Dragon* dragon = new Dragon;
    dragonDen.push_back(dragon);
    Battle battle4(adventurers,dragonDen);
    battle4.fight();

    
    cout << wizardName << ":";
    printf("\e[1;33m"); //yellow font
    displayStringLikeText("Is that a salt shaker??!", 15);
    printf("\e[0m \n");
    
    sleep(1);
    cout << "The adventurers all went to grab the salt shaker in the Dragons Horde!" << endl;
    sleep(1);
    cout << knightName << " grabs the salt shaker, but trips on a goose!" << endl;
    cout << knightName << ": ";
    printf("\e[1;36m"); //teal font
    displayStringLikeText("OOOOOOOOOPS", 60);
    printf("\e[0m \n");
    cout << "The salt shaker shatters into millions of pieces on the floor..." << endl;
    cout << knightName << ": ";
    
    sleep(3);
    printf("\e[1;36m"); //teal font
    displayStringLikeText("F@CK", 2);
    printf("\e[0m \n");
    
    cout << "The adventurers all stare in awe at the broken salt shaker." << endl;
    sleep(3);

    cout << knightName << ": ";
    printf("\e[1;36m"); //blue font
    displayStringLikeText("I'm going home y'all", 20);
    printf("\e[0m \n");

    printf("\e[1;31m"); //red font
    displayStringLikeText("--- THE END ---", 3);

    return 0;
}
