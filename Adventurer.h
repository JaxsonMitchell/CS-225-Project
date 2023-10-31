#pragma once
#include <string>
#include <iostream>
using namespace std;
class Adventurer
{protected:
	static int maxHealth;
	static int attackValue;
	int currentHealth;
	string name;
	int initative;

public:
	void defend();
	void basicAttack();
	void lowerHealth(int x) {
		currentHealth -= x;
	};



};
class Knight : public Adventurer {
private:
	static int maxHealth;
	static int attackValue;
	int currentHealth;
public:
	void taunt();
	Knight() {
		cout << "Enter the name of your Knight:";
		cin >> name;
		maxHealth = 100;
		attackValue = 10;
		currentHealth = 100;
	};


};
class Rogue : public Adventurer {
private:
	static int maxHealth;
	static int attackValue;
	int currentHealth;
	double critChance;
public:
	void ambush();
	void basicAttack();
	Rogue() {
		cout << "Enter the name of your Rogue:";
		cin >> name;
		maxHealth = 75;
		attackValue = 20;
		currentHealth = 75;
		critChance = 0.33;
	}
};
class Wizard : public Adventurer {
private:
	static int maxHealth;
	static int attackValue;
	int currentHealth;
	int numFireballs;
public:
	void fireball();
	void refocus();
	Wizard() {
		cout << "Enter the name of your Wizard:";
		cin >> name;
		maxHealth = 50;
		currentHealth = 50;
		attackValue = 25;
		numFireballs = 2;

	}
};
class Priest : public Adventurer {
private:
	static int maxHealth;
	static int attackValue;
	int currentHealth;
public:
	void heal();
	void healAll();
	Priest() {
		cout << " Enter the name of your Priest:";
		cin >> name;
		maxHealth = 50;
		currentHealth = 50;
		attackValue = 5;
	}

};
