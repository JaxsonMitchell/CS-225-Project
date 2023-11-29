/*******************************************************************************
* filename: battle.cpp
* This file is the function and class implemenations of Battle.
* It also contains function implementations for template functions used 
* within the implementation of fight (i'm so proud of those template functions)
*******************************************************************************/

#include "battle.h"

using namespace std;

void resetDefenseMultipliers(vector<Adventurer*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        vec[i]->def = 1;
    }
}

template <class T>
void removeIfNoHealth(vector<T*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i]->getHealth() <= 0) {
            delete vec[i];
            vec.erase(vec.begin() + i);
            --i;
        }
    }
}

template <class T>
void printOutAllMembers(vector<T*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << i + 1 << ". " << *vec[i] << endl;
        cout << "----------------------------" << endl;
    }
}

bool neitherVectorsEmpty(vector<Adventurer*>& party, vector<Monster*>& enemies) {
    return (party.size() != 0 && enemies.size() != 0);
}

/*******************************************************************************
 * Battle classs
*******************************************************************************/
Battle::Battle(vector<Adventurer*>& party, vector<Monster*>& enemies) : party(party), enemies(enemies) {}

void Battle::fight() {
    sleep(2);
    cout << endl << endl;
    printf("\e[0;31m"); // Red font
    cout << "BATTLE BEGIN! FIGHT!" << endl;
    printf("\e[0m \n");
    sleep(2);

    do {
        resetDefenseMultipliers(party);

        // Print monster position numbers
        printf("\e[0;32m"); // Green font
        printOutAllMembers(party);
        printf("\e[0m");
        sleep(3);

        cout << endl;
        printf("\e[0;31m"); // Red font
        printOutAllMembers(enemies);
        printf("\e[0m");
        sleep(3);
        
        for (auto& adventurer : party) {
            if (enemies.size() != 0) {
                adventurer->displayActions();
                adventurer->promptUserForAction(party, enemies);
                removeIfNoHealth(party);
                removeIfNoHealth(enemies);
            }
        }
        
        printf("\e[0;36m"); // Red font
        for (auto& monster : enemies) {
            if (party.size() == 0) {
                printf("\e[0;31m"); // Red font
                cout<<"Party is dead"<<endl;
                gameOver();
            }
            monster->doAction(party, enemies);
            cout << endl;
            removeIfNoHealth(party);
            removeIfNoHealth(enemies);
            sleep(2);
        }
        printf("\e[0m");
    } while (neitherVectorsEmpty(party, enemies));
    
    // If your party all get's knocked out.
    if (party.size() == 0){
        gameOver();
    }
}
