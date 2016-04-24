#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    HashTable ht = HashTable();
    string variable, name, city;

    while(1){
        ht.guide();
        getline(cin,variable);

        if(variable == "1"){
            cout << "Enter Team Name:" << endl;
            getline(cin, name);
            cout << "Enter City:" << endl;
            getline(cin, city);
            ht.insertMovie(name, city);
        }
        if(variable == "2"){
            cout << "Enter title:" << endl;
            getline(cin, name);
            ht.deleteMovie(name);
        }

        if(variable == "3"){
            ht.printTableContents();
        }

        if(variable == "4"){
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.updateWin(name);


        }
        if(variable == "5"){
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.updateLoss(name);
        }

        if(variable == "6"){
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.findMovie(name);
        }

         if(variable == "7"){
            string pName;
            string input;
            int shot, handling, defense;
            cout << "Name of team player will be added to :" << endl;
            getline(cin, name);
            cout << "Player name: "<<endl;
            getline(cin, pName);
            cout << "Shooting ability (0-10) : "<<endl;
            getline(cin, input);
            istringstream(input) >> shot;
            cout << "Handling ability (0-10) : "<<endl;
            getline(cin, input);
            istringstream(input) >> handling;
            cout << "Defensive ability (0-10) : "<<endl;
            getline(cin,input);
            istringstream(input) >> defense;
            ht.addPlayer(name,pName,shot,handling,defense);
        }

        if(variable == "9"){
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.printRoster(name);

        }

        if(variable == "10"){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }
    return 0;
}
