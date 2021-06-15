#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class player
{
public:
	player();
	player(std::string afirstname,std::string alastname,std::string acountry);

	bool comparename (std::string firstname,std::string lastname) ;//compare the name between 2 players

	//add score to that player
	void addscore(std::string event, std::string score);

	std::string getlastname() const;
	std::string getfirstname() const;
	std::string getcountry() const;
	std::vector<std::string> getscore() const;
	int gettotal() const;//get the total points 



	

	void printscore(std::ofstream &output_file,int long_name);//put the scores into the file
	void printpoint(std::ofstream &output_file,int long_name);//put the points into the file
	void cal_points();//calculate the points each player earn
	void cal_average();//calculate the average points 
	





private:
	std::string firstname;
	std::string lastname;

	std::string country;
	std::vector<std::string> events;

	std::vector<std::string> scores;
	std::vector<int> allpoints;


};



bool sort(const player& player1, const player& player2);//sort player in players vector by their name and country

bool sortpoint(const player& player1, const player& player2);//sort player in players vector by their points earn
