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

Battle::Battle(vector<Adventurer*>& party, vector<Monster*>& enemies) : party(party), enemies(enemies) {}

void Battle::fight() {
    cout << endl << endl;
    printf("\e[0;31m"); // Red font
    cout << "BATTLE BEGIN! FIGHT!" << endl;
    printf("\e[0m \n");

    do {
        resetDefenseMultipliers(party);

        // Print monster position numbers
        printf("\e[0;32m"); // Green font
        printOutAllMembers(party);
        printf("\e[0m");

        cout << endl;
        printf("\e[0;31m"); // Red font
        printOutAllMembers(enemies);
        printf("\e[0m");

        printf("\e[0;35m"); // Purple font
        for (auto& adventurer : party) {
            adventurer->displayActions();
            adventurer->promptUserForAction(party, enemies);
        }
        printf("\e[0m");

        printf("\e[0;36m"); // Red font
        for (auto& monster : enemies) {
            monster->doAction(party, enemies);
            cout << endl;
            sleep(2);
        }

        removeIfNoHealth(party);
        removeIfNoHealth(enemies);
        printf("\e[0m");
    } while (neitherVectorsEmpty(party, enemies));
}
/**
void displayStringLikeText(string text, float rateOfMessage) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(1000 / rateOfMessage)));
    }
    cout << endl;
}
**/
