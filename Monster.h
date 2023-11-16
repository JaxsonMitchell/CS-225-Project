#pragma once
#include <iostream>
#include <string>
#include <climits>
#include <time.h>

#include "Battler.h"

using namespace std;

// FUNCTION HEADERS
int randomNumber(int, int);
void promptUserUntilReceiveJoke1();
void promptUserUntilReceiveJoke2();


//CLASSES
class Monster{
    protected:
        int maxHealth;
        int currentHealth;
        string monsterName;
    public:
        void lowerHealth(int healthDropped){
            // Lowers the monster's health.
            this->currentHealth = (currentHealth - healthDropped > 0) ? (currentHealth - healthDropped) : 0;
        }
    
    friend ostream& operator<<(ostream& os, const Monster monster);
};


ostream& operator<<(ostream& os, const Monster monster){
    os << monster.monsterName << " has " << monster.currentHealth << " health Left!";
    return os;
}

//Gnome Class
class Gnomeageddon : public Monster{
    protected:
        bool firstUnderHalf = true;
    public:
        Gnomeageddon(){
            this->maxHealth = 100;
            this->currentHealth = maxHealth;
            this->monsterName = "Gnomeageddon";
        }
        
        ~Gnomeageddon(){
            cout<< "I'm all on my GNOME! *runs away*" << endl;
        }
        
        void attack(){
            // ADD CODE HERE FOR BASIC ATTACK
        }
        
        void lowerAttack(){
            // Lowers attack stat
        }
        
        void speakGnome(bool firstEncounter = false){
            string listOfPuns[4] = {
                "Mind your GNOME business!",
                "We will show you GNOME mercy!!",
                "Hope you have GNOME insurance!",
                "We will win GNOME matter what!"
            };
            
            if (firstEncounter){
                cout << "This is our forest I don't GNOME you!" << endl;
            } else if (firstUnderHalf && currentHealth < int(.5 * maxHealth)){
                promptUserUntilReceiveJoke1();
                promptUserUntilReceiveJoke2();
                cout << "GNOME more arguing!! Die!!!" << endl;
                
                firstUnderHalf = false;
            } else {
                int randomValue = randomNumber(0, 3);
                cout << listOfPuns[randomValue] << endl;
            }
        }
};


int randomNumber(int lowerBound, int upperBound)
{
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}

void promptUserUntilReceiveJoke1(){
    string prompt = "Knock Knock.";
    string response;

    cout << prompt << endl;
    getline(cin, response);  // Captures whole line

    while (!cin || 
        !(response == "whos there" || response == "whos there." || 
        response == "whos there?" || response == "Who's There." || 
        response == "who's there" || response == "Who's There?")) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "No. Incorrect!" << endl;
        cout << prompt;
        getline(cin, response);  // Change to getline here as well
    }
}

void promptUserUntilReceiveJoke2(){
    // A second prompt to get the user to write Gnome who?
    string prompt = "GNOME";
    string response;
    
    cout << prompt << endl;
    getline(cin, response);
    
    while ((!cin) || 
            (response != "GNOME WHO?" && response != "GNOME Who?" && 
            response != "Gnome Who?" && response != "gnome who?" && 
            response != "GNOME who?" && response != "GNOME WHO." &&
            response != "GNOME Who." && response != "Gnome Who." &&
            response != "gnome who." && response != "GNOME who." &&
            response != "GNOME WHO" && response != "GNOME Who" &&
            response != "Gnome Who" && response != "gnome who" &&
            response != "GNOME who"
        )) { 
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "No. Incorrect!" << endl;
        cout << prompt;
        getline(cin, response);
    }
}

//Lion class
class Lion : public Monster{
    public:
        Lion(){
            this->maxHealth = 20;
            this->currentHealth = maxHealth;
            this->monsterName = "Lion";
        }
        
        ~Lion(){
            cout << "The Lion runs away!" << endl;
            cout << "Ringleader: No Henry!" << endl;
        }
        
        void pounce(){
            // Add implementation for pounce.
        }
};

//Ringleader class
class Ringleader : public Monster{
    public:
        Ringleader(){
            this->maxHealth = 50;
            this->currentHealth = maxHealth;
            this->monsterName = "Ringleader";
        }
        
        ~Ringleader(){
            cout << "Ringleader: NO! MY CIRCUS!!" << endl;
        }
        
        void command(){
            // Commands the lion to attack again.
        }
        
        void attack(){
            // Normal basic attack.
        }
};

// Clown class
class Clown:public Monster{
    public:
        Clown(){
            this->maxHealth = 30;
            this->currentHealth = maxHealth;
            this->monsterName = "Clown";
        }
        
        ~Clown(){
            cout << "All Jokes were generated by jokester buddy ChatGPT! " <<
            "We're here all night! *comically stumbles over 32 geese*" << endl;
        }
        
        void joke(){
            string listOfJokes[5] = {
                "I'm the jokester baby",
                "A bat walks into a bar... 'Why the long wings?'",
                "Batman walks into a bar and the bartender chuckles,\
                'We don't serve bats here.'\
                Batman replies, 'That's okay; I prefer justice on the rocks.'",
                "ChatGPT walks into a bar, and the bartender exclaims,\
                'Sorry, we don't serve AI drinks!' ChatGPT replies,\
                'That's okay; I'm just here for the bits and bytes.'",
                "What do you get when you cross a Charizard and a CHEESE SANDWICH?\
                A GRILLED CHEESE SANDWICH."
            };
            
            int randomValue = randomNumber(0, 4);
            cout << listOfJokes[randomValue] << endl;
        }
};

//Cat in Boots class
class CatInBoots:public Monster {
    public:
        CatInBoots(){
            this->maxHealth = 20;
            this->currentHealth = maxHealth;
            this->monsterName = "Cat in Boots.";
        }
        
        ~CatInBoots(){
            cout << "Oof." << endl;
        }
        
        void demoralize(){
            // Demoralizes the opponents, makes their defense drop.
        }
        
        void stab(){
            // Basic stab attack
        }
};

//Nondescript Ogre class
class NondescriptOgre:public Monster{
    public:
        NondescriptOgre(){
            this->maxHealth = 70;
            this->currentHealth = maxHealth;
            this->monsterName = "Nondescript Ogre";
        }
        
        ~NondescriptOgre(){
            cout << "The nondescript ogre looks bored..." << endl;
            cout << "Nondescript Ogre: *uhhh idk*";
        }
        
        void throwALog(){
            // Throws a log deals splash damage.
        }
        
        void roar(){
            // Decreases opponents.
        }
};

// Jackass Class
class Jackass:public Monster{
    public:
        Jackass(){
            this->maxHealth = 60;
            this->currentHealth = maxHealth;
            this->monsterName = "Jackass";
        }
        
        ~Jackass(){
            cout << "INSERT DONKEY QUOTE" << endl;
        }
        
        void annoy(){
            // Donkey says literally anything and everyone gets annoyed at him
            // And only attacks him until the beginning of the next turn.
        }
};


// Dragon class 
class Dragon:public Monster{
    private:
        int fireBreathCoolDown;
    public:
        Dragon(){
            this->currentHealth = 100;
            this->maxHealth = currentHealth;
            this->monsterName = "Dragon";
            this->fireBreathCoolDown = 0;
        }
        
        void rend(){
            // Implement basic dragon attack.
            this->fireBreathCoolDown--;
        }
        
        void fireBreath(){
            // Shoots a blast of fire.
            this->fireBreathCoolDown = 3;
        }
        
        void attack(){
            if (this->fireBreathCoolDown == 0){
                fireBreath();
            } else {
                rend();
            }
        }
        
};
