/******************************************************************************

* Name: StartGame.cpp

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>

#include "Adventurer.h"



int main()
{
    string reply;
    int i;
    cout<<"Once upon a time..."<<endl;
    sleep(2);
    cout<<"Four Adventures walk into the bar and the bartender says:"<<endl;
    sleep(3);
    printf(" \e[0;33m \n"); //yellow font
    cout<<"Ay-yO WhAT are YE NAMEs?"<<endl;
    printf("\e[0m");
    
    Wizard wizard;
    Knight knight;
    Rogue rogue;
    Priest priest;
    
    vector<Adventurer> adventurers;
    adventurers.push_back(wizard);
    adventurers.push_back(knight);
    adventurers.push_back(rogue);
    adventurers.push_back(priest);
    
    printf(" \e[0;33m \n"); //yellow font
    cout<<"ThAts..."<<endl;
    sleep(3);
    cout<<"...nice..."<<endl;
    sleep(1);
    cout<<"Any ways. It appeares that I have lost my";
    printf(" \e[1;35m"); //purple font
    cout<<"SALT SHAKER!"<<endl;
    printf("\e[0;33m"); //yellow font
    cout<<"Would you be kind enough to find it for me?"<<endl;
    printf("\e[0m \n");
   
    cout<< knight.getName() << " the knight replies with a kind ";
    printf("\e[1;34m"); //yellow font
    cin>>reply;
    
    
    printf("\e[0;33m"); //yellow font
    cout<<"Why thank YE for accepting my quest to find the";
    printf(" \e[1;35m"); //purple font
    cout<<"SALT SHAKER!"<<endl;
    printf("\e[0;33m"); //yellow font
    cout<<"Better be on your way then"<<endl;
    cout<<"Bye bye!!"<<endl;
    printf("\e[0m \n");
    
    cout<<"and so";
    for (i = 0; i < (adventurers.size() - 1); i++) {
        cout<<" "<<adventurers[i].getName()<<",";
        
    }
    cout<<" and "<<adventurers[i].getName()
        <<" all walk out of the bar and into..."<<endl;
    
    
    return 0;
}
