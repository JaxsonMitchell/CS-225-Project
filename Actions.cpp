#include <string>
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Adventurer.h"
//Basic Attack Function
void basicAttack(Adventurer A,Monster M){
    M.currentHealth -= A.attackValue;
    cout<<"The "<<M.monsterName<<" took "<<A.attackValue<<" Damage!!"endl;
}
//Rogues Attack Function
void rogueAttack(Monster M){
    int crit = rand() % 3;
    if(crit == 1){
        M.currentHealth -= attackValue*3;
        cout<<getName()<<" Scored a critical hit!!"<<endl;
        cout<<"The "<<M.monsterName<<" took "<<attackValue*3<<" Damage!!"<<endl;
    }
    else{
        M.currentHealth -= attackValue;
        cout<<"The "<<M.monsterName<<" took "<<attackValue<<" Damage!!"<<endl
    }
}
//Fireball Function
void fireball(vector<Monster> M){
    cout<getName()<<" casts Fireball!!"<<endl;
    for(int i = 0; i< M.size();i++){
        M[i].currentHealth -= 50;
    }
    cout<<"All the enimeies took 50 damage!!"<<endl;
}

//Refocus Function
void refocus(){
    numFireballs +=1
    cout<<getName()<<" Refocuses and gains another use of Fireball"<<endl;
}
//Heal Function
void heal(vector<Adventurer> A){
    cout<<"Who do you want "<<getName()<<" to Heal?"<<endl;
    while (int i =0;i<A.size();i++){
        cout<<i<<". "<<A[i].getName<<endl;
    }
    int x;
    cin<<x;
    while (!cin or x>4 or x<1) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	    cout << "Error. Please enter 1-4";
	    cin >> x;
}
 A[x].currentHealth += 40;
}
//Heal All Function
void healAll(vector<Adventurer> A){
    while(int i = 0;)i<A.size();i++){
        A[i].currentHealth += 15;
    }
    cout<<"All Adventurers Healed by 15 points."<<endl;
}
