#pragma once
using namespace std;
// We really do not need any includes
class Battler {
   protected:
    int initative = 0;

   public:
    
    // Using virtural to overlaod the opporator latter
    virtual void set_initative(int num) {initative = num;}
    int get_initative() {return initative;}
    bool operator<(const Battler& battler) {
        return initative < battler.initative;
    }
};
