#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Battler {
    private:
        int initiative;
    public:
        virtual void set_initiative(int num){initiative = num;}
        int get_initative() {return initiative;}

        bool operator<(Battler b2) {
            return initiative > b2.initiative;
        }
};
