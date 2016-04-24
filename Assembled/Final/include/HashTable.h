#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct Player{
    std::string name;
    int shot;
    int handles;
    int defense;

    Player(){};
    Player(std::string name_in, int shot_in, int handles_in, int defense_in){
        name = name_in;
        shot = shot_in;
        defense = defense_in;
    }
};


struct HashElem{
	std::string title;
	std::string city;
	double wins;
	double loses;
	std::vector <Player> roster;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(std::string in_title, std:: string in_city)
	{
		title = in_title;
		city = in_city;
		wins = 0;
		loses = 0;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printTableContents();                               //DONE
		void guide();                                           //DONE-Menu
		void insertMovie(std::string name, std::string city);   //DONE
		void deleteMovie(std::string name);                     //DONE
		void findMovie(std::string name);                       //DONE-PrintTeamStats
		void updateWin(std::string name);                       //DONE
		void updateLoss(std::string name);                      //DONE
		void rankTeams();
		void addPlayer(std::string name, int shot, int handles, int defense);
		void printRoster(std::string teamName);
		void removePlayer(std::string name);
		void game(std::string team1, std::string team2);
	private:
		int hashSum(std::string x);
		int tableSize = 10;
		HashElem* hashTable[10];
		int numTeams = 0;

};

#endif // HASHTABLE_H
