#include <string>
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Adventurer.h"
//Adventurer Actions

    //Basic Attack Function
    void Adventurer::basicAttack(Adventurer A,Monster M){
        M.lowerHealth(A.attackValue);
        cout<<"The "<<M<<endl;
    }
    void Adventurer::defend(){
	    def -= 0.5;
    }
    //Knight Big Slash Function
    void Knight::bigSlash(Monster M){
        M.lowerHealth(attackValue*1.5);
        cout<<M<<endl;
    }
    //Rogues Attack Function
    void Rogue::rogueAttack(Monster M){
        int crit = rand() % 3;
        if(crit == 1){
            M.lowerHealth(attackValue*2);
            cout<<name<<" Scored a critical hit!!"<<endl;
            cout<<"The "<<M<<endl;
        }
        else{
            M.lowerHealth(attackValue);
            cout<<"The "<<M<<endl
        }
    }
    //Ambush Function
    void Rogue::ambush(Monster M){
        M.lowerHealth(attackValue*2);
        cout<< name << " Ambushed the "<< M<< " and scored a critical hit!!"<<endl;
        cout<< "The "<< M <<endl;
    }
    //Fireball Function
    void Wizard::fireball(vector<Monster> M){
        cout<<name<<" casts Fireball!!"<<endl;
        for(int i = 0; i< M.size();i++){
            M[i].lowerHealth(50);
        }
        cout<<"All the Monsters took 50 damage!!"<<endl;
    }
    
    //Refocus Function
    void Wizzard::refocus(){
        numFireballs +=1
        cout<<name<<" Refocuses and gains another use of Fireball"<<endl;
    }
    //Heal Function
    void Priest::heal(vector<Adventurer> A){
        cout<<"Who do you want "<<name<<" to Heal?"<<endl;
        while (int i =0;i<A.size();i++){
            cout<<i+1<<". "<<A[i]<<endl;
        }
        int x;
        cin<<x;
        while (!cin or x>4 or x<1) {
    	    cin.clear();
    	    cin.ignore(INT_MAX, '\n');
    	    cout << "Error. Please enter 1-4";
    	    cin >> x;
    }
     A[x].lowerHealth(-40);
    }
    //Heal All Function
    void Priest::healAll(vector<Adventurer> A){
        while(int i = 0;)i<A.size();i++){
            A[i].lowerHealth(-15);
        }
        cout<<"All Adventurers Healed by 15 points."<<endl;
    }

