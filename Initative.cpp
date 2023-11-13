#include <fstream>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Monster.h"
#include "Adventurer.h"
using namespace std;


int main() {
    int i = 0;
    
    // Creating the adventurers
    Wizard wizard;
    Knight knight;
    Rogue rogue;
    Priest priest;

    
    // Rolling for initative
    int randomNum;
    srand(time(NULL));
    randomNum = 1 + (rand() % 20);
    wizard.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    knight.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    rogue.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    priest.set_initative(randomNum);
    
    
    // Putting adventurers into a vector 
    vector<Battler> adventurers;
    adventurers.push_back(wizard);
    adventurers.push_back(knight);
    adventurers.push_back(rogue);
    adventurers.push_back(priest);
    
    // Displays unsorted initative
    for (i = 0; i < (adventurers.size()); i++) {
        cout<<"initative "<<adventurers[i].get_initative()<<endl;
        
    }
    
    
    // Sorting from higest initative to lowest
    sort(adventurers.begin(), adventurers.end());

    
    // Displays sorted initative
    sort(adventurers.begin(), adventurers.end());
    cout<<endl;
    for (i = 0; i < (adventurers.size()); i++) {
        
        cout<<"initative "<<adventurers[i].get_initative()<<endl;
    }

    return 0;
}
