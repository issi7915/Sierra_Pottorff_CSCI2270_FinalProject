#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    HashTable ht = HashTable();
    string variable, name, city, team1, team2, winner;

    while(1){
        ht.guide();
        getline(cin,variable);

        if(variable == "1"){
            string wins, losses;
            int w, l;
            cout << "Enter Team Name:" << endl;
            getline(cin, name);
            cout << "Enter City:" << endl;
            getline(cin, city);
            cout << "Wins:" << endl;
            getline(cin, wins);
            istringstream(wins) >> w;
            cout << "Losses:" << endl;
            getline(cin, losses);
            istringstream(losses) >> l;
            ht.insertTeam(name, city, w, l);
        }
        if(variable == "2"){
            cout << "Enter title:" << endl;
            getline(cin, name);
            ht.deleteTeam(name);
        }

        if(variable == "3"){
            ht.printLeague();
        }

        if(variable == "4"){
            cout << "Home Team:" << endl;
            getline(cin, team1);
            cout << "Away Team:" << endl;
            getline(cin, team2);
            cout << "Who won?" << endl;
            getline(cin, winner);
            ht.game(team1, team2, winner);


        }
        if(variable == "5"){
            cout << "Team Name:" << endl;
            getline(cin, name);
            ht.TeamStats(name);
        }

        if(variable == "6"){
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

        if(variable == "7"){
          string pName;
          cout << "Team Name:" << endl;
          getline(cin, name);
          cout << "Player Name:" << endl;
          getline(cin, pName);
          ht.removePlayer(name, pName);
        }

        if(variable == "8"){
          cout << "Team Name:" << endl;
          getline(cin, name);
          ht.printRoster(name);

        }

        if(variable == "9"){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }
    return 0;
}
