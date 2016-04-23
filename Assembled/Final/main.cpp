#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    HashTable ht = HashTable();
    string variable, data, name, year, num, r;
    int R, Y, N;

    while(1){
        ht.guide();
        getline(cin,variable);

        if(variable == "1"){
            cout << "Enter title:" << endl;
            getline(cin, name);
            cout << "Enter year:" << endl;
            getline(cin, year);
            istringstream(year) >> Y;   //convert string to int
            ht.insertMovie(name, Y);
        }
        if(variable == "2"){
            cout << "Enter title:" << endl;
            getline(cin, name);
            ht.deleteMovie(name);
        }
        if(variable == "3"){
            cout << "Enter title:" << endl;
            getline(cin, name);
            ht.findMovie(name);
        }
        if(variable == "4"){
            ht.printTableContents();
        }
        if(variable == "5"){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }
    return 0;
}
