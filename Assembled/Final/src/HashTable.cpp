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
            cout << index << ":" << tmp->title << ":" << tmp->year << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "not found" << endl;
    return;
}

void HashTable::printTableContents(){
    int c = 0;
    for(int k = 0; k<tableSize; k++){
        HashElem *rary = hashTable[k];
        while(rary !=NULL){
            cout<<rary->title<<":"<<rary->year<<endl;
            rary = rary->next;
            c++;
        }
    }
    if(c == 0){
        cout<<"empty"<<endl;
    }
    return;
}

void HashTable::insertMovie(string title, int year){
    int index = hashSum(title);
    if(hashTable[index] == NULL){
        hashTable[index] = new HashElem(title, year);
    }
    else{
        HashElem *temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new HashElem(title, year);
        temp->next->previous = temp;
    }
    return;
}

void HashTable::guide(){
        cout << "======Main Menu======" << endl;
        cout << "1. Insert movie" << endl;
        cout << "2. Delete movie" << endl;
        cout << "3. Find movie" << endl;
        cout << "4. Print table contents" << endl;
        cout << "5. Quit" << endl;
}
