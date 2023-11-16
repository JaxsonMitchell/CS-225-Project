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

class Battle{
    private:
        vector<Adventurer> party;
        vector<Monster> enemies;
        vector<Battler> combatants;
    public:
        Battle(
            vector<Adventurer> party,
            vector<Monster> enemies,
            vector<Battler> combatants
        ){
            this->party = party;
            this->enemies = enemies;
            this->combatants = combatants;
            
            int randomNum;
            
            // Sort combatants with initiative
            for (int i = 0; i < combatants.size(); ++i){
                randomNum = 1 + (rand() % 20);
                combatants[i].set_initative(randomNum);
            }
            
            sort(combatants.begin(), combatants.end());
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
    srand(time(NULL));

    string reply;
    int i;
    cout<<"Once upon a time..."<<endl;
    sleep(2);
    cout<<"Four Adventures walk into the bar and the bartender says:"<<endl;
    sleep(3);
    printf(" \e[0;33m \n"); //yellow font
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
    printf("\e[1;34m"); //yellow font
    cin>>reply;
    
    
    printf("\e[0;33m"); //yellow font
    cout<<"Why thank YE for accepting my quest to find the";
    printf(" \e[1;35m"); //purple font
    cout<<"SALT SHAKER!"<<endl;
    printf("\e[0;33m"); //yellow font
    cout<<"Better be on your way then"<<endl;
    cout<<"Bye bye!!"<<endl;
    printf("\e[0m \n");
    
    cout<<"and so";
    for (i = 0; i < (adventurers.size() - 1); i++) {
        cout<<" "<<adventurers[i].getName()<<",";
        
    }
    cout<<" and "<<adventurers[i].getName()
        <<" all walk out of the bar and into..."<<endl;
    
    
    return 0;
}
