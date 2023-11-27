#include "battlers.h"


void resetDefenseMultipliers(vector<Adventurer*>& vec);

template <class T>
void removeIfNoHealth(vector<T*>& vec);

template <class T>
void printOutAllMembers(vector<T*>& vec);

bool neitherVectorsEmpty(vector<Adventurer*>& party, vector<Monster*>& enemies);

/*******************************************************************************
 * Battle classs
*******************************************************************************/
class Battle {
private:
    vector<Adventurer*>& party;
    vector<Monster*>& enemies;
public:
    Battle(vector<Adventurer*>& party, vector<Monster*>& enemies);
    void fight();
};
