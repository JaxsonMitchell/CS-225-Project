#include "battlers.h"
//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <thread>
//#include <algorithm>
//#include <unistd.h>

void resetDefenseMultipliers(vector<Adventurer*>& vec);

template <class T>
void removeIfNoHealth(vector<T*>& vec);

template <class T>
void printOutAllMembers(vector<T*>& vec);

bool neitherVectorsEmpty(vector<Adventurer*>& party, vector<Monster*>& enemies);

class Battle {
private:
    vector<Adventurer*>& party;
    vector<Monster*>& enemies;
public:
    Battle(vector<Adventurer*>& party, vector<Monster*>& enemies);
    void fight();
};

//void displayStringLikeText(string text, float rateOfMessage);
