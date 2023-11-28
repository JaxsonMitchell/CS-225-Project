#include "battlers.h"

/*******************************************************************************
Helper functions
*******************************************************************************/

void displayStringLikeText(string text, float rateOfMessage) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(1000 / rateOfMessage)));
    }
    cout << endl;
}

void gameOver() {
    printf("\e[0;31m"); // Red font
    displayStringLikeText("GAME OVER!!!",5);
    exit(1);
}

template <class T>
void printOutAllMembers(vector<T*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << i + 1 << ". " << *vec[i] << endl;
        cout << "----------------------------" << endl;
    }
}

int getUserInput(int lowerBound, int upperBound, const string& promptMessage) {
    int userInput;
    do {
        cout << promptMessage;
        while (!(cin >> userInput)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter an integer." << endl;
            cout << promptMessage;
            cin >> userInput;
        }
    } while (userInput < lowerBound || userInput > upperBound);
    return userInput;
}


string testName(string nameinput) {
    for (int i = 0; i < nameinput.length(); i++) {
    if(isdigit(nameinput[i]))
        throw (1);
    }
    return nameinput;
}

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

//Basic Attack Function
void Adventurer::basicAttack(Monster& M){
    M.lowerHealth(this->attackValue);
    printf("\e[0;31m");
    cout<<endl<<M<<endl;
    printf("\e[0m");
}

void Adventurer::defend(){
	def -= 0.5;
}


/*******************************************************************************
Knight Class (Child)
*******************************************************************************/
void Knight::displayActions() {
    printf("\e[0m \n");
    cout << name << " the Knight Actions: "<< endl;
    cout << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Big Slash!" << endl;
}

Knight::Knight(){
    
    cout << "Enter the name of your Knight: ";
    
    string newName;
    getline(cin, newName);
    try {
        name = testName(newName);
    }
    catch (int i) {
        cout<<"OK ELon MUSK! this is a person not a Tezzzla!"<<endl;
        gameOver();
    }
    
    this->maxHealth = 130;
    this->attackValue = 20;
    this->currentHealth = this->maxHealth;
    /*ifstream myfile ("Knight_Art.txt");
    char art;
    while (myfile) {
        art = myfile.get();
        cout << art;
    }*/
}

void Knight::bigSlash(Monster& M){
    M.lowerHealth(attackValue * 1.5);
    printf("\e[0;31m");
    cout<<endl<<M<<endl;
    printf("\e[0m");
}

void Knight::promptUserForAction(vector<Adventurer*>& party, vector<Monster*>& enemies) {
    int actionNum = getUserInput(1, 3, "What action will the knight do? ");
    int len = enemies.size();
    int i;

    switch (actionNum) {
        case 1:
            cout<<endl;
            printf("\e[0;31m"); // Red font
            printOutAllMembers(enemies);
            printf("\e[0m");
            i = getUserInput(1, len + 1, "Who will the knight attack? ");
            basicAttack(*(enemies[i - 1]));
            break;
        case 2:
            defend();
            break;
        case 3:
            cout<<endl;
            printf("\e[0;31m"); // Red font
            printOutAllMembers(enemies);
            printf("\e[0m");
            i = getUserInput(1, len + 1, "Who will the knight use Big Slash on? ");
            bigSlash(*(enemies[i - 1]));
            break;
    }
}

/*******************************************************************************
Rogue Class (Class)
*******************************************************************************/
void Rogue::displayActions() {
    printf("\e[0m \n");
	cout << name << " the Rogue Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
}


Rogue::Rogue() {
    cout << "Enter the name of your Rogue: ";
	
    string newName;
    getline(cin, newName);
    try {
        name = testName(newName);
    }
    catch (int i) {
        cout<<"OK ELon MUSK! this is a person not a Tezzzla!"<<endl;
        gameOver();
    }
    this->maxHealth = 100;
    this->attackValue = 20;
    this->currentHealth = this->maxHealth;

    /*ifstream myfile("Rogue_Art.txt");
    char art;
    while (myfile) {
    art = myfile.get();
    cout << art;
    }*/
    critChance = 1;
}

void Rogue::rogueAttack(Monster& M){
    int crit = rand() % 3;
    if(crit == 1){
        M.lowerHealth(attackValue*2);
        cout<<name<<" Scored a critical hit!!"<<endl;
        printf("\e[0;31m");
        cout<< M <<endl;
        printf("\e[0m");
    }else{
        M.lowerHealth(attackValue);
        printf("\e[0;31m");
        cout<< M <<endl;
        printf("\e[0m");
    }
}

void Rogue::promptUserForAction(vector<Adventurer*>& party, vector<Monster*>& enemies) {
    int actionNum = getUserInput(1, 2, "What action will the rogue do? ");
    int len = enemies.size();
    int i;

    switch (actionNum) {
        case 1:
            cout<<endl;
            printf("\e[0;31m"); // Red font
            printOutAllMembers(enemies);
            printf("\e[0m");
            i = getUserInput(1, len + 1, "Who will the rogue attack? ");
            rogueAttack(*(enemies[i - 1]));
            break;
        case 2:
            defend();
            break;
    }
}
/*******************************************************************************
Wizard Class (Class)
*******************************************************************************/
void Wizard::displayActions() {
    printf("\e[0m \n");
	cout << name << " the Wizard Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Fireball" << endl;
	cout << "4. Refocus" << endl;
}

Wizard::Wizard() {
	cout << "Enter the name of your Wizard: ";

    string newName;
    getline(cin, newName);
    try {
        name = testName(newName);
    }
    catch (int i) {
        cout<<"OK ELon MUSK! this is a person not a Tezzzla!"<<endl;
        gameOver();
    }
    
	this->maxHealth = 60;
    this->attackValue = 50;
	this->currentHealth = this->maxHealth;
	/*ifstream myfile("Wizard_Art.txt");
	char art;
	while (myfile) {
		art = myfile.get();
		cout << art;
	}*/
	this->currentHealth = this->maxHealth;
	numFireballs = 2;
}

void Wizard::fireball(vector<Monster*>& M){
    cout<<name<<" casts Fireball!!"<<endl;
    sleep(3);
    for(int i = 0; i < M.size(); i++){
        M[i]->lowerHealth(50);
    }
    printf("\e[0;36m\n");
    cout<<"All the Monsters took 50 damage!!"<<endl;
    printf("\e[0m\n");
    sleep(2);
}

void Wizard::refocus(){
    numFireballs +=1;
    cout<<name<<" Refocuses and gains another use of Fireball"<<endl;
}

void Wizard::promptUserForAction(vector<Adventurer*>& party, vector<Monster*>& enemies) {
    int actionNum = getUserInput(1, 4, "What action will the wizard do? ");
    int len = enemies.size();
    int i;

    switch (actionNum) {
        case 1:
            cout<<endl;
            printf("\e[0;31m"); // Red font
            printOutAllMembers(enemies);
            printf("\e[0m");
            i = getUserInput(1, len + 1, "Who will the wizard attack? ");
            basicAttack(*(enemies[i - 1]));
            break;
        case 2:
            defend();
            break;
        case 3:
            fireball(enemies);
            break;
        case 4:
            refocus();
            break;
    }
}

/*******************************************************************************
Priest Class (Class)

*******************************************************************************/
void Priest::displayActions() {
    printf("\e[0m \n");
	cout << name << " the Priest Actions: "<< endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Heal" << endl;
	cout << "4. Heal All" << endl;
}

Priest::Priest() {
	cout << "Enter the name of your Priest: ";
	
	string newName;
    getline(cin, newName);
    try {
        name = testName(newName);
    }
    catch (int i) {
        cout<<"OK ELon MUSK! this is a person not a Tezzzla!"<<endl;
        gameOver();
    }
	
	this->maxHealth = 60;
        this->attackValue = 50;
	this->currentHealth = this->maxHealth;
	
	/*ifstream myfile("Priest_Art.txt");
	char art;
	while (myfile) {
		art = myfile.get();
		cout << art;
	}*/
}

void Priest::heal(vector<Adventurer*>& A){
    cout<<"Who do you want "<<name<<" to Heal? ";
    int x;
    cin >> x;
    while (!cin or x>4 or x<1) {
	    cin.clear();
        cin.ignore(INT_MAX, '\n');
    	cout << "Error. Please enter 1-4";
    	cin >> x;
    }
    A[x - 1]->lowerHealth(-40);
    printf("\e[0;32m"); // Green font
    cout<<A[x - 1]->getName()<<" now has "<< A[x - 1]->getHealth()<<" health"<< endl;
    printf("\e[0m");
}

//Heal All Function
void Priest::healAll(vector<Adventurer*>& A){
    for(int i = 0; i<A.size(); i++){
        A[i]->lowerHealth(-15);
    }
    cout<<"All Adventurers Healed by 15 points."<<endl;
}

void Priest::promptUserForAction(vector<Adventurer*>& party, vector<Monster*>& enemies) {
    int actionNum = getUserInput(1, 4, "What action will the priest do? ");
    int len = enemies.size();
    int i;  // Declare i outside the switch statement

    switch (actionNum) {
        case 1:
            cout<<endl;
            printf("\e[0;31m"); // Red font
            printOutAllMembers(enemies);
            printf("\e[0m");
            i = getUserInput(1, len + 1, "Who will the priest attack? ");
            basicAttack(*(enemies[i - 1]));
            break;
        case 2:
            defend();
            break;
        case 3:
            cout<<endl;
            printf("\e[0;32m"); // Green font
            printOutAllMembers(party);
            printf("\e[0m");
            heal(party);
            break;
        case 4:
            healAll(party);
            break;
    }
}

/*******************************************************************************
FUNCTION IMPLEMENTATIONS

*******************************************************************************/
int randomNumber(int lowerBound, int upperBound) {
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}

void promptUserUntilReceiveJoke1(){
    string prompt = "Knock Knock.";
    string response;
    printf("\e[1;31m"); // Red font
    displayStringLikeText(prompt, 15);
    printf("\e[0m");
    printf("\e[0;36m");
    
    cin.ignore();
	getline(cin, response);
	
    while ((!cin) || 
            (response != "whos there" && response != "Whos there" && 
            response != "whos there?" && response != "Whos There?" &&
            response != "who is there" && response != "Who is there" &&
            response != "who is there?" && response != "Who is there?" &&
            response != "who's there?" && response != "Who's there?" &&
            response != "who's there." && response != "Who's there." &&
            response != "whos there." && response != "Whos there." &&
            response != "whos there?" && response != "Whos there?" &&
            response != "who's there" && response != "Who's there")) {
            
        cin.clear();
        //cin.ignore(INT_MAX); // the code keeps getting stuck here.
        printf("\e[1;31m"); // Red font
        displayStringLikeText("No. Incorrect!", 15);
        displayStringLikeText(prompt, 15);
        printf("\e[0;36m");
        getline(cin >> ws, response);
    }
}


void promptUserUntilReceiveJoke2(){
    // A second prompt to get the user to write Gnome who?
    string prompt = "GNOME";
    string response;
    
    printf("\e[1;31m"); // Red font
    displayStringLikeText(prompt, 15);
    printf("\e[0;36m");
    getline(cin, response);
    
    while ((!cin) || 
            (response != "GNOME WHO?" && response != "GNOME Who?" && 
            response != "Gnome Who?" && response != "gnome who?" && 
            response != "GNOME who?" && response != "GNOME WHO." &&
            response != "GNOME Who." && response != "Gnome Who." &&
            response != "GNOME who." && response != "Gnome who." &&
            response != "GNOME Who?" && response != "Gnome Who?" &&
            response != "GNOME who?" && response != "Gnome who?" &&
            response != "gnome who." && response != "GNOME who." &&
            response != "GNOME WHO" && response != "GNOME Who" &&
            response != "Gnome Who" && response != "gnome who" &&
            response != "GNOME who"
        )) { 
        cin.clear();
        //cin.ignore(INT_MAX, '\n');
        printf("\e[1;31m"); // Red font
        displayStringLikeText("No. Incorrect!", 15);
        displayStringLikeText(prompt, 15);
        printf("\e[0;36m");
        getline(cin, response);
    }
}


/*******************************************************************************
Monster Class (Parent)

*******************************************************************************/
void Monster::lowerHealth(int healthDropped){
    // Lowers the monster's health.
    this->currentHealth = (currentHealth - healthDropped > 0) ? (currentHealth - healthDropped) : 0;
}

string Monster::getName() {
    return this->monsterName;
}

int Monster::getHealth() {
    return this->currentHealth;
}

ostream& operator<<(ostream& os, const Monster& monster) {
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
    cout<<endl;
    printf("\e[1;31m"); // Red font
        displayStringLikeText("I'm all on my GNOME!", 15);
    printf("\e[0;36m\n");
    cout<< "*runs away*" << endl;
    printf("\e[0m");
}

void Gnomeageddon::attack(vector<Adventurer*>& A){
    int x = rand() % A.size();
    A[x]->lowerHealth(currentHealth / 2);
    sleep(2);
    printf("\e[0;36m\n");
    cout<<"Gnomeaggeddon strikes " << A[x]->getName() << endl;
    printf("\e[0;32m");
    sleep(1);
    cout<<*A[x]<<endl;
    printf("\e[0m");
}

void Gnomeageddon::speakGnome(bool firstEncounter = false){
    string listOfPuns[4] = {
        "Mind your GNOME business!",
        "We will show you GNOME mercy!!",
        "Hope you have GNOME insurance!",
        "We will win GNOME matter what!"
    };
            
    if (firstEncounter){
        printf("\e[1;31m"); // Red font
        displayStringLikeText("This is our forest I don't GNOME you!", 15);
        printf("\e[0m");
    } else if (firstUnderHalf && currentHealth < int(.5 * maxHealth)){
        promptUserUntilReceiveJoke1();
        promptUserUntilReceiveJoke2();
        printf("\e[1;31m"); // Red font
        displayStringLikeText("GNOME more arguing!! Die!!!", 15);
        printf("\e[0m");
        firstUnderHalf = false;
    } else {
        int randomValue = randomNumber(0, 3);
        printf("\e[1;31m"); // Red font
        displayStringLikeText(listOfPuns[randomValue], 15);
        printf("\e[0m");
    }
}


void Gnomeageddon::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    speakGnome(); 
    attack(party);
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
    printf("\e[0;36m");
    cout << "The Lion runs away!" << endl;
    printf("\e[0m");
    sleep(1);
    cout << "Ringleader: ";
    printf("\e[1;33m"); // Yellow
    displayStringLikeText("No Henry!", 10);
    printf("\e[0m \n");
}

void Lion::pounce(vector<Adventurer*>& A){
    // Add implementation for pounce.
    int x = rand() % A.size();
    A[x]->lowerHealth(20);
    printf("\e[0;36m\n");
    sleep(2);
    cout<<"The Lion pounces on "<<A[x]->getName()<<endl;
    sleep(1);
    printf("\e[0;32m");
    cout<<*A[x]<<endl;
    printf("\e[0m");
    
    
}


void Lion::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    pounce(party);
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
    sleep(1);
    cout << "Ringleader: ";
    printf("\e[1;33m"); // Yellow
    displayStringLikeText("NO! MY CIRCUS!!", 10);
    printf("\e[0m \n");
    
}

void Ringleader::command(vector<Monster*>& M, vector<Adventurer*>& A){
    for(int i = 0; i < M.size(); i++){
        if (M[i]->getName() == "Lion"){
            // Needed line because of a compile error because the Monster doesn't 
            // have pounce, so it had to call it this way.
            Lion* lionPtr = static_cast<Lion*>(M[i]);
            printf("\e[0;36m");
            sleep(2);
            cout << "The Ringleader cracks his whip and commands the Lion to attack!!!" << endl;
            lionPtr->pounce(A);
        }
    }
    
    this->attack(A);
}

void Ringleader::attack(vector<Adventurer*>& A){
    int x = rand() % A.size();
    A[x]->lowerHealth(10);
    printf("\e[0;36m\n");
    sleep(2);
    cout<<"The Ringleader cracks his whip at "<< A[x]->getName() << endl;
    printf("\e[0;32m");
    cout<<*A[x]<<endl;
    printf("\e[0m");
}

void Ringleader::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    command(monsters, party);
}

/*******************************************************************************
Clown Class (Child)

*******************************************************************************/
Clown::Clown(){
    this->maxHealth = 30;
    this->currentHealth = maxHealth;
    this->monsterName = "Clown (not the Joker)";
}
        
Clown::~Clown(){
    cout<<"Clown: ";
    printf("\e[1;31m"); // Red
    displayStringLikeText("All Jokes were generated by jokester buddy ChatGPT!", 10);
    displayStringLikeText("We're here all night! ", 10);
    printf("\e[0;36m");
    sleep(2);
    cout<<"*comically stumbles over 32 geese*" << endl;
    printf("\e[0m\n");
    
}
        
void Clown::joke(vector<Adventurer*>& A, vector<Monster*>& M){
    string listOfJokes[5][2] = {
        {"I'm the jokester baby", ". . ."},
        {"A bat walks into a bar...", "\n'Why the long wings?'"},
        {"Batman walks into a bar and the bartender chuckles,\n'We don't serve bats here.'",
        "\nBatman replies, \n'That's okay; I prefer justice on the rocks.'"},
        {"ChatGPT walks into a bar, and the bartender exclaims,\n"
        "'Sorry, we don't serve AI drinks!'", "\nChatGPT replies,\n"
        "'That's okay; I'm just here for the bits and bytes.'"},
        {"What do you get when you cross a Charizard and a CHEESE SANDWICH?",
        "\nA GRILLED CHEESE SANDWICH!!!"}
    };
    
    int randomValue = randomNumber(0, 4);
    printf("\e[1;31m"); // Red
    displayStringLikeText(listOfJokes[randomValue][0], 10);
    sleep(2);
    displayStringLikeText(listOfJokes[randomValue][1], 10);
    sleep(2);
    printf("\e[0m \n");
    //cout << listOfJokes[randomValue] << endl;
    
    for (int i = 0; i<A.size(); i++){
        A[i]->lowerHealth(5);
    }
    for (int i = 0; i<M.size(); i++){
        M[i]->lowerHealth(5);
    } 
    
    cout<<"The Clown gives everyone a headache and all combatants take 5 pyschic damage....."<<endl;
}

void Clown::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    joke(party, monsters);
}


/*******************************************************************************
Cat in Boots Class (Child)
*******************************************************************************/
CatInBoots::CatInBoots(){
    this->maxHealth = 20;
    this->currentHealth = maxHealth;
    this->monsterName = "Cat in Boots";
}

CatInBoots::~CatInBoots(){
    cout << "Cat in Boots: ";
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("Oof", 15);
    printf("\e[0m\n"); //yellow font
    sleep(2);
}

void CatInBoots::demoralize(vector<Adventurer*>& A){
    int x = rand() % A.size();
    A[x]->def += 1;
}

void CatInBoots::stab(vector<Adventurer*>& A){
    int x = rand() % A.size();
    A[x]->lowerHealth(20);
    printf("\e[0;36m\n"); // not Red font
    cout<<"Cat in Boots stabs "<< A[x]->getName()<<" for 20 Damage!!"<<endl;
    printf("\e[0;32m");
    cout<<*A[x]<<endl;
    printf("\e[0m");
    
}


void CatInBoots::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    int i = rand() % 3;
    if (i == 0){
        demoralize(party);
    }
    stab(party);
}


/*******************************************************************************
Nondescript Ogre Class (Child)

*******************************************************************************/
NondescriptOgre::NondescriptOgre(){
    this->maxHealth = 70;
    this->currentHealth = maxHealth;
    this->monsterName = "Nondescript Ogre";
}

NondescriptOgre::~NondescriptOgre(){
    printf("\e[0;36m"); // not Red font
    cout << "The nondescript ogre looks bored..." << endl;
    sleep(2);
    cout << "Nondescript Ogre walks away.";
    printf("\e[0m\n");
    sleep(2);
}

void NondescriptOgre::throwALog(vector<Adventurer*>& A){
    // Throws a log deals splash damage.
    for (int i = 0; i<A.size(); i++){
        A[i]->lowerHealth(10);
    }
    printf("\e[0;36m"); // not Red font
    cout<<"The Non-Descript Ogre throws a log hitting the whole party!!!"<<endl;
    printf("\e[0m");
    
}

void NondescriptOgre::roar(vector<Adventurer*>& A){
    // Decreases opponents defense.
    for (int i = 0; i < A.size(); i++){
        A[i]->def *= 1.25;
    }
    printf("\e[0;36m"); // not Red font
    cout<<"The Non-Descript Ogre Roars lowering the defense of the Adventurers!!"<<endl;
    printf("\e[0m");
}


void NondescriptOgre::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    int x = rand() % 4;
    if (x == 0){
        roar(party);
    }
    
    throwALog(party);
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
    cout << "Jackass: ";
    printf("\e[0;33m"); //yellow font
    displayStringLikeText("INSERT DONKEY QUOTE", 10);
    printf("\e[0m\n"); //yellow font
    
}

void Jackass::annoy(vector<Adventurer*>& A, vector<Monster*>& M){
    // insert quotes.
    for(int i = 0; i<A.size(); i++){
        A[i]->lowerHealth(5);
    }
    
    for(int i = 0; i<M.size(); i++){
        M[i]->lowerHealth(5);
    }
    printf("\e[0;36m"); // not Red font
    cout<<"Jackass annoys everyone giving them a headache, everyone takes 5 damage...."<<endl;
    printf("\e[0m");
    sleep(2);
}


void Jackass::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters) {
    annoy(party, monsters);
}

/*******************************************************************************
Dragon Class (Child)

*******************************************************************************/
Dragon::Dragon(){
    this->currentHealth = 100;
    this->maxHealth = currentHealth;
    this->monsterName = "Dragon";
    this->fireBreathCoolDown = 0;
}

void Dragon::rend(vector<Adventurer*>& A){
    // Implement basic dragon attack.
    int x = rand() % A.size();
    A[x]->lowerHealth(30);
    printf("\e[0;36m\n");
    cout<<"The Dragon rends "<<A[x]->getName()<<" for 30 Damage!!!"<<endl;
    cout<<*A[x]<<endl;
    this->fireBreathCoolDown--;
    sleep(3);
}

void Dragon::fireBreath(vector<Adventurer*>& A){
    // Shoots a blast of fire.
    for (int i = 0; i < A.size(); i++){
        A[i]->lowerHealth(40);
    }
    printf("\e[0;36m\n");
    cout<<"The Dragon Breaths Fire on all the Adventurers dealing 40 Damage!!!"<<endl;
    this->fireBreathCoolDown = 3;
    sleep(3);
}

void Dragon::doAction(vector<Adventurer*>& party, vector<Monster*>& monsters){
    if (this->fireBreathCoolDown == 0){
        fireBreath(party);
    } else {
        rend(party);
    }
}
