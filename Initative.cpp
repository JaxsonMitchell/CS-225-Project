#include <stdio.h>
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
    
    Set_initative(wizard, knight);
    int randomNum;
    
    srand(time(NULL));
    randomNum = 1 + (rand() % 20);
    wizard.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    knight.set_initative(randomNum);
    
    vector<Adventurer*> adventurers;
    adventurers.push_back(wp);
    adventurers.push_back(kp);
    adventurers.push_back(new Adventurer);
    
    for (i = 0; i < (adventurers.size()); i++) {
        cout<<"initative "<<adventurers[i]->get_initative()<<endl;
        adventurers[i]->displayActions();
        cout<<endl;
    }
    
    randomNum = 1 + (rand() % 20);
    wizard.set_initative(randomNum);
    
    randomNum = 1 + (rand() % 20);
    knight.set_initative(randomNum);
    
    
    for (i = 0; i < (adventurers.size()); i++) {
        
                
        cout<<"initative "<<adventurers[i]->get_initative()<<endl;
    }

    return 0;
}
