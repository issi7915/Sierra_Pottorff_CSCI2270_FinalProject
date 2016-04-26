#include "HashTable.h"
#include <iostream>


using namespace std;

HashTable::HashTable()
{
    //ctor
    for(int j = 0; j<tableSize; j++){
        hashTable[j] = NULL;
    }
}

HashTable::~HashTable()
{
    //dtor
}

int HashTable::hashSum(string x)
{
    int sum = 0;
    for(unsigned int i = 0; i<x.size(); i++){
        sum += x[i];
    }
    sum %= tableSize;
    return sum;
}

void HashTable::deleteTeam(string title){
    int index = hashSum(title);
    HashElem *tmp = hashTable[index];
    while(tmp != NULL){
        if(tmp->title == title){
            if(tmp->previous != NULL){
                tmp->previous->next = tmp->next;
                if(tmp->next != NULL){
                    tmp->next->previous = tmp->previous;
                }
            }
            else {
                if(tmp->next == NULL){
                    hashTable[index] = tmp->next;
                }
                else {
                    hashTable[index] = tmp->next;
                    tmp->next->previous = NULL;
                }
           }
            return;
        }
        tmp = tmp->next;
    }
    delete tmp;
    cout << "not found" << endl;
    return;
}

HashElem* HashTable::findTeam(string title){
    int index = hashSum(title);
    HashElem *tmp = hashTable[index];
    while(tmp != NULL){
        if(tmp->title == title){
            return tmp;
        }
        tmp = tmp->next;
    }
    cout << "not found" << endl;
    return NULL;
}

void HashTable::TeamStats(string team){
  HashElem* t = findTeam(team);
  cout<<"--------------------------------------------------------------------------------"<<endl;cout<<endl;
  cout<<"Team:    "<<t->title<< ", " << t->city << endl;
  cout<<endl;
  cout<<"------Wins---"<<"---Loses---"<<"---PCT------"<<endl;
  cout<<"       "<<t->wins<<"          "<<t->loses<<"        "<<t->wins/(t->loses + t->wins)<<endl;
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  return;
}

void HashTable::printLeague(){
    int c = 0;
    cout<<"========MY LEAGUE TEAMS========"<<endl;cout<<endl;
    for(int k = 0; k<tableSize; k++){
        HashElem *rary = hashTable[k];
        while(rary !=NULL){
            cout<<rary->title<<",   "<<rary->city<<endl;
            rary = rary->next;
            c++;
        }
    }
    if(c == 0){
        cout<<"empty"<<endl;
    }
    cout<<endl;
    return;
}

void HashTable::insertTeam(string title, string city, int wins, int losses){
    int index = hashSum(title);
    if(hashTable[index] == NULL){
        hashTable[index] = new HashElem(title, city, wins, losses);
        numTeams++;
    }
    else{
        HashElem *temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new HashElem(title, city, wins, losses);
        temp->next->previous = temp;
        numTeams++;
    }
    return;
}

void HashTable::updateWin(string teamName){
    int index = hashSum(teamName);
    HashElem *tmp = hashTable[index];
    bool found = false;

    while(tmp != NULL){
        if(tmp->title == teamName){
            tmp->wins++;
            found = true;
            cout<<endl;
            cout<<"Win updated."<<endl;
        }
        tmp = tmp->next;
    }

    if(!found)
        cout<<"Team not found. "<<endl;

}

void HashTable::updateLoss(string teamName){
    int index = hashSum(teamName);
    HashElem *tmp = hashTable[index];
    bool found = false;

    while(tmp != NULL){
        if(tmp->title == teamName){
            tmp->loses++;
            found = true;
            cout<<endl;
            cout<<"Loss updated."<<endl;
        }
        tmp = tmp->next;
    }

    if(!found)
        cout<<"Team not found. "<<endl;

}

void HashTable::addPlayer(string teamName, string player, int shot, int handles, int defense){
    int index = hashSum(teamName);
    HashElem *tmp = hashTable[index];

    bool found = false;

    while(tmp != NULL){
        if(tmp->title == teamName){
            Player p1;
            p1.name = player;
            p1.shot = shot;
            p1.handles = handles;
            p1.defense = defense;
            tmp->roster.push_back(p1);
            found = true;
            cout<<player<<" added to "<<teamName<<"'s roster."<<endl;
        }
        tmp = tmp->next;
    }

    if(!found)
        cout<<"Team not found. "<<endl;

}

void HashTable::removePlayer(string Team, string player){
  HashElem *tmp = findTeam(Team);
  for(unsigned int i = 0; i < tmp->roster.size(); i ++){
    if(tmp->roster[i].name == player){
      //delete and
      tmp->roster.erase(tmp->roster.begin() + i);
    }
  }
}

void HashTable::game(string homeTeam, string awayTeam, string winner){
  updateWin(winner);
  if(winner == homeTeam){
    updateLoss(awayTeam);
  }
  else {
    updateLoss(homeTeam);
  }
  return;
}

void HashTable::printRoster(string teamName){
    int index = hashSum(teamName);
    HashElem *tmp = hashTable[index];

    bool found = false;

    while(tmp != NULL){
        if(tmp->title == teamName){
            found = true;
            cout<<teamName<<"'s Roster: "<<endl;
            cout<<"--";
            for(unsigned int i = 0; i < tmp->roster.size(); i++){
                cout<<tmp->roster[i].name<<"--";
            }
            cout<<endl;

        }
        tmp = tmp->next;
    }

    if(!found)
        cout<<"Team not found. "<<endl;

}

void HashTable::rankTeams(){

}

void HashTable::guide(){
        cout << "======My League======" << endl;
        cout << "1. Add Team" << endl;
        cout << "2. Remove Team" << endl;
        cout << "3. Print Teams" << endl;
        cout << "======Team Manager=====" <<endl;
        //cout << "4. Update Win" << endl;
        //cout << "5. Update Loss" << endl;
        cout << "4. Game" << endl;
        cout << "5. Team Stats" << endl;
        //cout << "========Roster========"<<endl;
        cout << "6. Add Player" <<endl;
        cout << "7. Remove Player"<<endl;
        cout << "8. Print Roster" <<endl;
        cout << "9. Quit" << endl;
}
