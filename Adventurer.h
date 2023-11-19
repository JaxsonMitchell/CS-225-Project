#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Battler.h"
#include "Monster.h"

using namespace std;


/*******************************************************************************
Adventure Class (Parent)

*******************************************************************************/
class Adventurer : public Battler {
    protected:
        int maxHealth = 100;
        int attackValue = 10;
        int currentHealth = 0;
	int def = 1;
        string name;
    
    public:
        // Using virtual to overload the operator later
        virtual void displayActions();
        void defend();
        void basicAttack();
        void lowerHealth(int x);
        string getName();
    
        // Overloading the << operator for ostream
        friend ostream& operator<<(ostream&, const Adventurer&);
};


/*******************************************************************************
Knight Class (Child)

*******************************************************************************/
class Knight : public Adventurer {
    private:
    	const int maxHealth = 100;
    	const int attackValue = 10;
    	int currentHealth;
    public:
    	void taunt();
    	void displayActions();
    	Knight();
};


/*******************************************************************************
Rogue Class (Class)

*******************************************************************************/
class Rogue : public Adventurer {
private:
	const int maxHealth = 75;
	const int attackValue = 20;
	int currentHealth;
	double critChance;
	
public:
    Rogue();
	void ambush();
	void rogueAttack();
	void displayActions();
};


/*******************************************************************************
Wizard Class (Class)

*******************************************************************************/
class Wizard : public Adventurer {
private:
	const int maxHealth = 50;
	const int attackValue = 25;
	int currentHealth;
	int numFireballs;
public:
	void fireball();
	void refocus();
	void displayActions();
	Wizard();
};



class Priest : public Adventurer {
private:
	const int maxHealth = 50;
	const int attackValue = 5;
	int currentHealth;
public:
	void heal();
	void healAll();
	void displayActions();
	Priest();

};
