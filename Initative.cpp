#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Monster.h"
#include "Adventurer.h"
using namespace std;


void Set_initative(Wizard w, Knight k) {
    int randomNum;
    
    srand(time(NULL));
    randomNum = 1 + (rand() % 20);
    w.set_initative(randomNum);
    
    srand(time(NULL));
    randomNum = 1 + (rand() % 20);
    k.set_initative(randomNum);
}



int main() {
    int i = 0;
    Wizard wizard;
    Wizard* wp;
    wp = &wizard;
    
    Knight knight;
    Knight* kp;
    kp = &knight;
    
    Rogue rogue;
    Rogue* rp;
    rp = &rogue;
    
    Priest priest;
    Priest* pp;
    pp = &priest;
    
    srand(time(NULL));
    int randomNum = 1 + (rand() % 20);
    wizard.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    knight.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    rogue.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    priest.set_initative(randomNum);
    
    
    
    vector<Adventurer*> adventurers;
    adventurers.push_back(wp);
    adventurers.push_back(kp);
    adventurers.push_back(rp);
    adventurers.push_back(pp);
    
    for (i = 0; i < (adventurers.size()); i++) {
        cout<<"initative "<<adventurers[i]->get_initative()<<endl;
        adventurers[i]->displayActions();
        cout<<endl;
    }
    
    vector<Battler*> battler;
    for (i = 0; i < (adventurers.size()); i++) {
        battler.push_back(adventurers[i]);
    }
    
    sort(battler.begin(), battler.end());
    
    for (i = 0; i < (battler.size()); i++) {
        
        cout<<"initative "<<battler[i]->get_initative()<<endl;
    }

    return 0;
}
