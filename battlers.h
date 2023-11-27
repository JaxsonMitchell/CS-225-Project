#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <thread>
#include <algorithm>
#include <unistd.h>

using namespace std;
void displayStringLikeText(string text, float rateOfMessage);
void gameOver();

template <class T>
void printOutAllMembers(vector<T*>& vec);

class Monster;
class Adventurer;

/*******************************************************************************
Adventure Class (Parent)
*******************************************************************************/
class Adventurer {
protected:
    int maxHealth;
    int attackValue;
    int currentHealth;
    string name;

public:
    float def = 1;

    // Pure Virtual Functions
    virtual void promptUserForAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) = 0;
    virtual void displayActions() = 0;

    // Basic Functions
    void defend();
    void basicAttack(Monster& M);
    void lowerHealth(int x);

    // Getter Functions
    string getName();
    int getHealth();

    // Default constructors to remove issues
    Adventurer() = default;
    virtual ~Adventurer() = default;

    // Overloading the << operator for ostream
    friend ostream& operator<<(ostream& os, const Adventurer&);
};


/*******************************************************************************
Knight Class (Child)
*******************************************************************************/
class Knight : public Adventurer {
public:
    void promptUserForAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void displayActions() override;

    void bigSlash(Monster&);
    Knight();
};

/*******************************************************************************
Rogue Class (Child)
*******************************************************************************/
class Rogue : public Adventurer {
private:
    double critChance;
public:
    Rogue();
    void rogueAttack(Monster&);

    void promptUserForAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void displayActions() override;
};

/*******************************************************************************
Wizard Class (Child)
*******************************************************************************/
class Wizard : public Adventurer {
private:
    int numFireballs;
public:
    void promptUserForAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void fireball(vector<Monster*>& monsters);
    void refocus();
    void displayActions() override;
    Wizard();
};

/*******************************************************************************
Priest Class (Child)
*******************************************************************************/
class Priest : public Adventurer {
public:
    void promptUserForAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void heal(vector<Adventurer*>& adventurers);
    void healAll(vector<Adventurer*>& adventurers);
    void displayActions() override;
    Priest();
};

/*******************************************************************************
FUNCTION HEADERS
*******************************************************************************/
int randomNumber(int, int);
void promptUserUntilReceiveJoke1();
void promptUserUntilReceiveJoke2();

/*******************************************************************************
Monster Class (Parent)
*******************************************************************************/
class Monster {
protected:
    int maxHealth;
    int currentHealth;
    string monsterName;

public:
    // Pure Virtual Function
    virtual void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) = 0;

    // Basic functions
    void lowerHealth(int healthDropped);

    // Getter functions
    string getName();
    int getHealth();

    // Default constructors to remove issues
    Monster() = default;
    virtual ~Monster() = default;

    friend ostream& operator<<(ostream& os, const Monster& monster);
};

/*******************************************************************************
Gnome Class (Child)
*******************************************************************************/
class Gnomeageddon : public Monster {
protected:
    bool firstUnderHalf = true;

public:
    Gnomeageddon();
    ~Gnomeageddon();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void attack(vector<Adventurer*>& adventurers);

    void speakGnome(bool);
};

/*******************************************************************************
Lion Class (Child)
*******************************************************************************/
class Lion : public Monster {
public:
    Lion();
    ~Lion();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void pounce(vector<Adventurer*>& adventurers);
};

/*******************************************************************************
Ringleader Class (Child)
*******************************************************************************/
class Ringleader : public Monster {
public:
    Ringleader();
    ~Ringleader();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void command(vector<Monster*>& monsters, vector<Adventurer*>& adventurers);
    void attack(vector<Adventurer*>& adventurers);
};

/*******************************************************************************
Clown Class (Child)
*******************************************************************************/
class Clown : public Monster {
public:
    Clown();
    ~Clown();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void joke(vector<Adventurer*>& adventurers, vector<Monster*>& monsters);
};

/*******************************************************************************
Cat in Boots Class (Child)
*******************************************************************************/
class CatInBoots : public Monster {
public:
    CatInBoots();
    ~CatInBoots();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void demoralize(vector<Adventurer*>& adventurers);
    void stab(vector<Adventurer*>& adventurers);
};

/*******************************************************************************
Nondescript Ogre Class (Child)
*******************************************************************************/
class NondescriptOgre : public Monster {
public:
    NondescriptOgre();
    ~NondescriptOgre();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void throwALog(vector<Adventurer*>& adventurers);
    void roar(vector<Adventurer*>& adventurers);
};

/*******************************************************************************
Jackass Class (Child)
*******************************************************************************/
class Jackass : public Monster {
public:
    Jackass();
    ~Jackass();

    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
    void annoy(vector<Adventurer*>& adventurers, vector<Monster*>& monsters);
};

/*******************************************************************************
Dragon Class (Child)
*******************************************************************************/
class Dragon : public Monster {
private:
    int fireBreathCoolDown;

public:
    Dragon();
    void rend(vector<Adventurer*>& adventurers);
    void fireBreath(vector<Adventurer*>& adventurers);
    void doAction(vector<Adventurer*>& adventurers, vector<Monster*>& monsters) override;
};
