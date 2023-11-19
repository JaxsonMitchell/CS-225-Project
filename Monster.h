#pragma once
#include <iostream>
#include <string>
#include <climits>
#include <time.h>
#include "Adventurer.h"
#include "Battler.h"

using namespace std;


/*******************************************************************************
FUNCTION HEADERS

*******************************************************************************/
int randomNumber(int, int);
void promptUserUntilReceiveJoke1();
void promptUserUntilReceiveJoke2();


/*******************************************************************************
Monster Class (Parent)

*******************************************************************************/
class Monster : public Battler{
    protected:
        int maxHealth;
        int currentHealth;
        string monsterName;
    public:
        void lowerHealth(int healthDropped);
        string getName();    
        friend ostream& operator<<(ostream& os, const Monster monster);
};




/*******************************************************************************
Gnome Class (Child)

*******************************************************************************/
class Gnomeageddon : public Monster{
    protected:
        bool firstUnderHalf = true;
    public:
        Gnomeageddon();
        ~Gnomeageddon();
        void attack();
        void lowerAttack();
        void speakGnome(bool firstEncounter = false);
};


/*******************************************************************************
Lion Class (Child)

*******************************************************************************/
class Lion : public Monster{
    public:
        Lion();
        ~Lion();
        void pounce();
};


/*******************************************************************************
Ringleader Class (Child)

*******************************************************************************/
class Ringleader : public Monster{
    public:
        Ringleader();
        ~Ringleader();
        void command();
        void attack();
};



/*******************************************************************************
Clown Class (Child)

*******************************************************************************/
class Clown:public Monster{
    public:
        Clown();
        ~Clown();
        void joke();
};




/*******************************************************************************
Cat in Boots Class (Child)

*******************************************************************************/
class CatInBoots:public Monster {
    public:
        CatInBoots();
        ~CatInBoots();
        void demoralize();
        void stab();
};


/*******************************************************************************
Nondescript Ogre Class (Child)

*******************************************************************************/
class NondescriptOgre:public Monster{
    public:
        NondescriptOgre();
        ~NondescriptOgre();
        void throwALog();
        void roar();
};


/*******************************************************************************
Jackass Class (Child)

*******************************************************************************/
class Jackass:public Monster{
    public:
        Jackass();
        ~Jackass();
        void annoy();
};


/*******************************************************************************
Dragon Class (Child)

*******************************************************************************/
class Dragon:public Monster{
    private:
        int fireBreathCoolDown;
    public:
        Dragon();
        void rend();
        void fireBreath();
        void attack();
};
