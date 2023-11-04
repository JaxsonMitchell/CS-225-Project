#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Adventurer
{protected:
	const int maxHealth = 100;
	const int attackValue = 10;
	int currentHealth = 0;
	string name;
	int initative = 0;

public:
	void defend();
	void basicAttack();
	void lowerHealth(int x) {
		currentHealth -= x;
	};



};
class Knight : public Adventurer {
private:
	const int maxHealth = 100;
	const int attackValue = 10;
	int currentHealth;
public:
	void taunt();
	void displayActions() {
		cout << "1. Attack" << endl;
		cout << "2. Defend" << endl;
		cout << "3. Taunt" << endl;
	}
	Knight(){
		cout << "Enter the name of your Knight:";
		cin >> name;
		ifstream myfile ("Knight_Art.txt");
		char art;
		while (myfile) {
			art = myfile.get();
			cout << art;
		}
		currentHealth = 100;
	};


};
class Rogue : public Adventurer {
private:
	const int maxHealth = 75;
	const int attackValue = 20;
	int currentHealth;
	double critChance;
public:
	void ambush();
	void basicAttack();
	void displayActions() {
		cout << "1. Attack" << endl;
		cout << "2. Defend" << endl;
		cout << "3. Ambush" << endl;
	}
	Rogue() {
		cout << "Enter the name of your Rogue:";
		cin >> name;
		ifstream myfile("Rogue_Art.txt");
		char art;
		while (myfile) {
			art = myfile.get();
			cout << art;
		}
		currentHealth = 75;
		critChance = 0.33;
	}
};
class Wizard : public Adventurer {
private:
	const int maxHealth = 50;
	const int attackValue = 25;
	int currentHealth;
	int numFireballs;
public:
	void fireball();
	void refocus();
	void displayActions() {
		cout << "1. Attack" << endl;
		cout << "2. Defend" << endl;
		cout << "3. Fireball" << endl;
		cout << "4. Refocus" << endl;
	}
	Wizard() {
		cout << "Enter the name of your Wizard:";
		cin >> name;
		ifstream myfile("Wizard_Art.txt");
		char art;
		while (myfile) {
			art = myfile.get();
			cout << art;
		}
		currentHealth = 50;
		numFireballs = 2;

	}
};
class Priest : public Adventurer {
private:
	const int maxHealth = 50;
	const int attackValue = 5;
	int currentHealth;
public:
	void heal();
	void healAll();
	void displayActions() {
		cout << "1. Attack" << endl;
		cout << "2. Defend" << endl;
		cout << "3. Heal" << endl;
		cout << "4. Heal All" << endl;
	}
	Priest() {
		cout << "Enter the name of your Priest:";
		cin >> name;
		ifstream myfile("Priest_Art.txt");
		char art;
		while (myfile) {
			art = myfile.get();
			cout << art;
		}
		currentHealth = 50;
	}

};
