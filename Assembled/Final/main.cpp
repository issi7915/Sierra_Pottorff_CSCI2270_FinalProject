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
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.findMovie(name);
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
            ht.printTableContents();
        }
        if(variable == "7"){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }
    return 0;
}
