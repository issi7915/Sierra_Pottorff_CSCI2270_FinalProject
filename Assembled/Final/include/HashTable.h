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
    	int Rank;
    	bool visited;

	HashElem(){};
	HashElem(std::string in_title, std:: string in_city, int w, int l)
	{
		title = in_title;
		city = in_city;
		wins = w;
		loses = l;
		next = NULL;
		previous = NULL;
		Rank = -1;
		visited = false;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printLeague();                               //DONE
		void guide();                                           //DONE-Menu
		void insertTeam(std::string name, std::string city, int wins, int losses);   //DONE
		void deleteTeam(std::string name);                     //DONE
		void TeamStats(std::string name);                      //DONE
		void rankTeams();                                     //Done - case of two same pct
		void addPlayer(std::string teamName, std::string player, int shot, int handles, int defense); //DONE
		void printRoster(std::string teamName); //Done
		void removePlayer(std::string teamName, std::string name); //DOne
		void game(std::string team1, std::string team2); //Done
	private:
        	HashElem* findTeam(std::string name);                       //DONE
        	void updateWin(std::string name);                      //DONE
		void updateLoss(std::string name);                    //DONE
		int hashSum(std::string x);                           //DONE
		void unrank();
		int tableSize = 10;
		HashElem* hashTable[10];
		int numTeams = 0;
		bool TeamsR = false;

};

#endif // HASHTABLE_H
