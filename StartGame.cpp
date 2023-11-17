/******************************************************************************

* Name: StartGame.cpp

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Adventurer.h"
#include "Monster.h"
#include "Battler.h"

class Battle {
    private:
        vector<Adventurer>& party;
        vector<Monster>& enemies;

    public:
        Battle(vector<Adventurer>& party, vector<Monster>& enemies) : party(party), enemies(enemies) {}
        
        void fight(){
            // Tests by iterating through the list.
            cout << endl << endl;
            printf("\e[0;31m"); // Red font
            cout << "BATTLE BEGIN! FIGHT!" << endl;
            printf("\e[0m \n");

            for (auto& adventurer : party) {
                cout << adventurer.getName() << endl;
            }
    
            for (auto& monster : enemies) {
                cout << monster.getName() << endl;
            }
        }
};


void displayStringLikeText(string text, float rateOfMessage){
    // Displays string text with a slight delay to emulate typing.
    for (int i = 0; i < text.length(); i++){
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(1000 / rateOfMessage)));
    }
    cout << endl;
}

int main()
{
    // Initialization and seeding a random number generator.
    srand(time(NULL));
    string reply;
    int i;
    
    cout<<"Once upon a time..."<<endl;
    sleep(2);
    cout<<"Four Adventures walk into the bar and the bartender says:"<<endl;
    sleep(3);
    printf(" \e[0;33m"); //yellow font
    displayStringLikeText("Ay-yO WhAT are YE NAMEs?", 30);
    printf("\e[0m");
    
    Wizard wizard;
    Knight knight;
    Rogue rogue;
    Priest priest;
    
    vector<Adventurer> adventurers;
    adventurers.push_back(wizard);
    adventurers.push_back(knight);
    adventurers.push_back(rogue);
    adventurers.push_back(priest);
    
    printf(" \e[0;33m \n"); //yellow font
    displayStringLikeText("ThAts...", 30);
    sleep(1);
    displayStringLikeText("...nice...", 30);
    sleep(1);
    displayStringLikeText("Any ways. It appeares that I have lost my", 30);
    printf(" \e[1;35m"); //purple font
    displayStringLikeText("SALT SHAKER!", 5);
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Would you be kind enough to find it for me?", 30);
    printf("\e[0m \n");
   
    cout<< knight.getName() << " the knight replies with a kind ";
    printf("\e[0;36m"); //yellow font
    displayStringLikeText("What..? Salt..? Of course not.", 10);
    
    
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Why thank YE for accepting my quest to find the", 30);
    printf(" \e[1;35m"); //purple font
    displayStringLikeText("SALT SHAKER!", 5);
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Better be on your way then", 30);
    displayStringLikeText("Bye bye!!", 100);
    printf("\e[0m \n");
    
    cout<<"and so";
    for (i = 0; i < (adventurers.size() - 1); i++) {
        cout<<" "<<adventurers[i].getName()<<",";
        
    }
    cout<<" and "<<adventurers[i].getName()
        <<" all walk out of the bar and into..."<<endl;
    
    sleep(2);
    cout << "A mob of Gnomes..? Trying to get into the adventurers way!!!" << endl;
    printf("\e[1;31m"); // Red font
    displayStringLikeText("We are GNOMEAGEDDON!", 5);
    printf("\e[0m"); // Resets
    cout << "The gnomes coalesce into a monstrosity never gazed upon by mankind." << endl;
    
    vector<Monster> gnome({Gnomeageddon()});    
    Battle battle1(adventurers, gnome);
    battle1.fight();

    
    
    return 0;
}