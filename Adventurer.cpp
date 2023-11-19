#include "Adventurer.h"


/*******************************************************************************
Adventure Class (Parent)

*******************************************************************************/
void Adventurer::lowerHealth(int x) {
    currentHealth -= def * x;
}


string Adventurer::getName() {
    return this->name;
}

int Adventurer::getHealth() {
    return this->currentHealth;
}

ostream& operator<<(ostream& os, const Adventurer& adventurer) {
    os << adventurer.name << " has " << adventurer.currentHealth << " health left!";
    return os;
}



/*******************************************************************************
Knight Class (Child)

*******************************************************************************/
void Knight::displayActions() {
    cout << name << " the Knight Actions: "<< endl;
    cout << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Taunt" << endl;
}

Knight::Knight(){
    cout << "Enter the name of your Knight: ";
    cin >> name;
    ifstream myfile ("Knight_Art.txt");
    char art;
    while (myfile) {
        art = myfile.get();
        cout << art;
    }
}



/*******************************************************************************
Rogue Class (Class)

*******************************************************************************/
void Rogue::displayActions() {
	cout << name << " the Rogue Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Ambush" << endl;
}


Rogue::Rogue() {
	cout << "Enter the name of your Rogue: ";
	cin >> name;
	ifstream myfile("Rogue_Art.txt");
	char art;
	while (myfile) {
		art = myfile.get();
		cout << art;
    }
    currentHealth = 75;
	critChance = 1;
}



/*******************************************************************************
Wizard Class (Class)

*******************************************************************************/
void Wizard::displayActions() {
	cout << name << " the Wizard Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Fireball" << endl;
	cout << "4. Refocus" << endl;
}

Wizard::Wizard() {
	cout << "Enter the name of your Wizard: ";
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

/*******************************************************************************
Priest Class (Class)

*******************************************************************************/
void Priest::displayActions() {
	cout << name << " the Priest Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Heal" << endl;
	cout << "4. Heal All" << endl;
}

Priest::Priest() {
	cout << "Enter the name of your Priest: ";
	cin >> name;
	ifstream myfile("Priest_Art.txt");
	char art;
	while (myfile) {
		art = myfile.get();
		cout << art;
	}
	currentHealth = 50;
}
