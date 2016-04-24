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
    for(int i = 0; i<x.size(); i++){
        sum += x[i];
    }
    sum %= tableSize;
    return sum;
}

void HashTable::deleteMovie(string title){
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

void HashTable::findMovie(string title){
    int index = hashSum(title);
    HashElem *tmp = hashTable[index];
    while(tmp != NULL){
        if(tmp->title == title){
            cout<<"--------------------------------------------------------------------------------"<<endl;cout<<endl;
            cout<<"Team:    "<<tmp->title<< ", " << tmp->city << endl;
            cout<<endl;
            cout<<"------Wins---"<<"---Loses---"<<"---PCT------"<<endl;
            cout<<"       "<<tmp->wins<<"          "<<tmp->loses<<"        "<<tmp->wins/(tmp->loses + tmp->wins)<<endl;
            cout<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "not found" << endl;
    return;
}

void HashTable::printTableContents(){
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

void HashTable::insertMovie(string title, string city){
    int index = hashSum(title);
    if(hashTable[index] == NULL){
        hashTable[index] = new HashElem(title, city);
        numTeams++;
    }
    else{
        HashElem *temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new HashElem(title, city);
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

void HashTable::guide(){
        cout << "======My League======" << endl;
        cout << "1. Add Team" << endl;
        cout << "2. Remove Team" << endl;
        cout << "3. Print Team Stats" << endl;
        cout << "======Team Manager=====" <<endl;
        cout << "4. Update Win" << endl;
        cout << "5. Update Loss" << endl;
        cout << "6. Print Teams" << endl;
        cout << "7. Quit" << endl;
}
