#include "Monster.h"


/*******************************************************************************
FUNCTION HEADERS

*******************************************************************************/
int randomNumber(int lowerBound, int upperBound) {
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


/*******************************************************************************
Monster Class (Parent)

*******************************************************************************/
Monster::void lowerHealth(int healthDropped){
    // Lowers the monster's health.
    this->currentHealth = (currentHealth - healthDropped > 0) ? (currentHealth - healthDropped) : 0;
}

Monster::string getName() {
    return this->monsterName;
}

Monster::ostream& operator<<(ostream& os, const Monster monster){
    os << monster.monsterName << " has " << monster.currentHealth << " health Left!";
    return os;
}


/*******************************************************************************
Gnome Class (Child)

*******************************************************************************/

Gnomeageddon::Gnomeageddon(){
    this->maxHealth = 100;
    this->currentHealth = maxHealth;
    this->monsterName = "Gnomeageddon";
}

Gnomeageddon::~Gnomeageddon(){
    cout<< "I'm all on my GNOME! *runs away*" << endl;
}

Gnomeageddon::void attack(vector<Adeventurer> A){
    // ADD CODE HERE FOR BASIC ATTACK
    int x = rand() % A.size();
    A[x].lowerHealth(currentHealth / 2);
    cout<<"Gnomeaggeddon strikes " << A[x].getName<<endl;
    cout<<A[x]<<endl;
}

Gnomeageddon::void lowerAttack(){
    // Lowers attack stat
}

Gnomeageddon::void speakGnome(bool firstEncounter = false){
    string listOfPuns[4] = {
        "Mind your GNOME business!",
        "We will show you GNOME mercy!!",
        "Hope you have GNOME insurance!",
        "We will win GNOME matter what!"
    }
            
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


/*******************************************************************************
Lion Class (Child)

*******************************************************************************/
Lion::Lion(){
    this->maxHealth = 20;
    this->currentHealth = maxHealth;
    this->monsterName = "Lion";
}

Lion::~Lion(){
    cout << "The Lion runs away!" << endl;
    cout << "Ringleader: No Henry!" << endl;
}

Lion::void pounce(vector<Adventurer> A){
    // Add implementation for pounce.
    int x = rand() % A.size();
    A[x].lowerHealth(20);
    cout<<" The Lion pounces on "<<A[x].getName<<endl;
    cout<<A[x]<<endl;
}


/*******************************************************************************
Ringleader Class (Child)

*******************************************************************************/
Ringleader::Ringleader(){
    this->maxHealth = 50;
    this->currentHealth = maxHealth;
    this->monsterName = "Ringleader";
}


Ringleader::~Ringleader(){
    cout << "Ringleader: NO! MY CIRCUS!!" << endl;
}

Ringleader::void command(){
    // Commands the lion to attack again.
}

Ringleader::void attack(){
    // Normal basic attack.
}


/*******************************************************************************
Clown Class (Child)

*******************************************************************************/
Clown::Clown(){
    this->maxHealth = 30;
    this->currentHealth = maxHealth;
    this->monsterName = "Clown";
}
        
Clown::~Clown(){
    cout << "All Jokes were generated by jokester buddy ChatGPT! " <<
    "We're here all night! *comically stumbles over 32 geese*" << endl;
}
        
Clown::void joke(){
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


/*******************************************************************************
Cat in Boots Class (Child)

*******************************************************************************/
CatInBoots::CatInBoots(){
    this->maxHealth = 20;
    this->currentHealth = maxHealth;
    this->monsterName = "Cat in Boots.";
}

CatInBoots::~CatInBoots(){
    cout << "Oof." << endl;
}

CatInBoots::void demoralize(){
    // Demoralizes the opponents, makes their defense drop.
}

CatInBoots::void stab(){
    // Basic stab attack
}


/*******************************************************************************
Nondescript Ogre Class (Child)

*******************************************************************************/
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


/*******************************************************************************
Jackass Class (Child)

*******************************************************************************/
Jackass::Jackass(){
    this->maxHealth = 60;
    this->currentHealth = maxHealth;
    this->monsterName = "Jackass";
}

Jackass::~Jackass(){
    cout << "INSERT DONKEY QUOTE" << endl;
}

Jackass::void annoy(){
    // Donkey says literally anything and everyone gets annoyed at him
    // And only attacks him until the beginning of the next turn.
}



/*******************************************************************************
Dragon Class (Child)

*******************************************************************************/
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
