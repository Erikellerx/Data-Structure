#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "player.h"

//this function is to read the file input and create a vector
//return a vector with all players with their score, name, country
std::vector<player> create_list(std::ifstream& file){


	std::vector<player> players;
	std::string in_str;
    std::string event;
    std::string firstname;
    std::string lastname;
    std::string country;
    std::string score;
    

    while(file >> in_str){
    	
        //this part read the file from input txt 
    	if(in_str == "event"){file >> event;file >> firstname;}
    	else{firstname = in_str;}
    	
    	file >> lastname;
    	file >> country;
    	file >> score;

        bool in_here = false;//this bool is help if that player has already been added into the vector
        int place;//if yes, where are they

        //this loop is trying to find if that player has already been added into the vector
        //and if they are, it will change in_here boolen and give the place of index where he is
        for (unsigned int i = 0; i < players.size(); ++i){

            if(players[i].getlastname()==lastname){//compare the name
                in_here = true;
                place = i;          
            }
        }
        
        if (!in_here){//if they are not in the vector, creat a new player class and add into vector

            players.push_back(player(firstname, lastname, country));
            players[players.size()-1].addscore(event,score);
          }
        else{
            
            players[place].addscore(event, score);//if they already are, only add their score corresponding thier event they attend 
        }
  
    }
    return players;
    

}




int main(int argc, char const *argv[])
{

	if (argc != 4)
	{
		std::cerr<<"Missing argument"<<std::endl;//this part is checking if correct number command argunment are putting into the terminal
        exit(1);
	}


	std::vector<player> players;

	std::string f = argv[1];//read the input file
	std::string output = argv[2];//read the output file name
	std::string type = argv[3];//that type of data the output should get 

	std::ifstream file;
	std::ofstream outputf;

	file.open(f);
	outputf.open(output);

	if(!file.is_open()){
        std::cerr<<"Can not open the file"<<std::endl;//this part is check if the file can be open
        exit(1);
    }
    if(!outputf.is_open()){
        std::cerr<<"Can not open the file"<<std::endl;//this part is check if the file can be open
        exit(1);
    }

    players=create_list(file);//create the vector with all players

    unsigned int long_name = 0;//find the longgest name and format name neatly within the output file
    for (unsigned int i = 0; i < players.size(); ++i)
    {
    	if (long_name < players[i].getfirstname().length())
    	{
    		long_name = players[i].getfirstname().length();
    	}

    }
    


    if(type == "scores"){//output the score


        sort(players.begin(), players.end(),sort);//sort the vector by the score they get


        //thie part is create the title of the output file
        outputf<<std::left<<std::setw(long_name+21)<<"DECATHLETE SCORES";
        outputf<<std::right<<std::setw(7)<<"100";
        outputf<<std::right<<std::setw(7)<<"LJ";
        outputf<<std::right<<std::setw(7)<<"SP";
        outputf<<std::right<<std::setw(7)<<"HJ";
        outputf<<std::right<<std::setw(7)<<"400";
        outputf<<std::right<<std::setw(7)<<"110H";
        outputf<<std::right<<std::setw(7)<<"DT";
        outputf<<std::right<<std::setw(7)<<"PV";
        outputf<<std::right<<std::setw(7)<<"JT";
        outputf<<std::right<<std::setw(9)<<"1500"<<std::endl;

        //this part is print the score of each player
        for (unsigned int i = 0; i < players.size(); ++i)
        {
        	players[i].printscore(outputf,long_name);
        }

       	}

   	if(type == "points"){//points after calculated 

   		

   		for (unsigned int i = 0; i < players.size(); ++i)
   		{
   			players[i].cal_points();//calculate the points by the score they get 
   			
   		}

        //title
   		outputf<<std::left<<std::setw(long_name+21)<<"DECATHLETE POINTS";
	    outputf<<std::right<<std::setw(7)<<"100";
	    outputf<<std::right<<std::setw(7)<<"LJ";
	    outputf<<std::right<<std::setw(7)<<"SP";
	    outputf<<std::right<<std::setw(7)<<"HJ";
	    outputf<<std::right<<std::setw(7)<<"400";
	    outputf<<std::right<<std::setw(7)<<"110H";
	    outputf<<std::right<<std::setw(7)<<"DT";
	    outputf<<std::right<<std::setw(7)<<"PV";
	    outputf<<std::right<<std::setw(7)<<"JT";
	    outputf<<std::right<<std::setw(9)<<"1500";
	    outputf<<std::right<<std::setw(9)<<"TOTAL"<<std::endl;


	    sort(players.begin(), players.end(),sortpoint);//sort players by their points

	    for (unsigned int i = 0; i < players.size(); ++i)
    	{
    	players[i].printpoint(outputf,long_name);//print each player's score   	
    	}
    }
    if(type == "custom"){//custom is calculate the average 

    	

    	for (unsigned int i = 0; i < players.size(); ++i)
   		{
   			players[i].cal_points();//calculate the points by their score
   			players[i].cal_average();//calculate the average of points they got 

   		}
        //title
   		outputf<<std::left<<std::setw(long_name+21)<<"DECATHLETE CUSTOM";
	    outputf<<std::right<<std::setw(7)<<"100";
	    outputf<<std::right<<std::setw(7)<<"LJ";
	    outputf<<std::right<<std::setw(7)<<"SP";
	    outputf<<std::right<<std::setw(7)<<"HJ";
	    outputf<<std::right<<std::setw(7)<<"400";
	    outputf<<std::right<<std::setw(7)<<"110H";
	    outputf<<std::right<<std::setw(7)<<"DT";
	    outputf<<std::right<<std::setw(7)<<"PV";
	    outputf<<std::right<<std::setw(7)<<"JT";
	    outputf<<std::right<<std::setw(9)<<"1500";
	    outputf<<std::right<<std::setw(9)<<"Average"<<std::endl;


	    sort(players.begin(), players.end(),sortpoint);//sort players by their average score

	    for (unsigned int i = 0; i < players.size(); ++i)
    	{
    	players[i].printpoint(outputf,long_name);//orint points and average
    	
    	}

    }
    return 0;

 }







   	
   	








    






