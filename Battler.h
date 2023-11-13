#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Battler {
   private:
    int initative;

   public:
    
    // Using virtural to overlaod the opporator latter
    virtual void set_initative(int num) {initative = num;}
    int get_initative() {return initative;}
    
    bool operator<(Battler b2) {
        return initative > b2.initative;
    }
};
