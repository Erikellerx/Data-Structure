#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include "fighter.h"

//You may add additional typedefs, includes, etc. up here

//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};

//Feel free to put forward declarations here

//this function is to find and return a set of fighter based on command -d
std::set<std::string> find_d(std::map <std::string, Fighter> &all_data,std::string move, int frame){
	std::map<std::string, Fighter>::iterator itr = all_data.begin();
	std::set<std::string> output;
	//loop through all the data 
	while(itr != all_data.end()){
		//if it match corresponding frame add those into the output set
		if(itr->second.get_frame()[move] == frame) output.insert(itr->first);
		itr++;
	}
	return output;

}
//this function also return a set of fighters based on -f command and also used on -s command
std::set<Fighter>  find_f(std::map<std::string,Fighter> &all_data, std::string move, bool which){
	//if 'which' is false, operate< them wieh -f command, else wieh -s command 
	std::map<std::string, Fighter>::iterator itr = all_data.begin();
	std::set<Fighter> output;
	//loop through all data 
	while(itr != all_data.end()){
		//set which order we are going to compare
		if(which) itr->second.set_which();
		//set which move we are going to compare
		itr->second.set_comparsion(move);
		//insert everything w/in the order compared with specific move
		output.insert(itr->second);
		itr++;
	}
	return output;

}
//load the data base file 
std::map<std::string,Fighter> load(std::ifstream &dbfile){
	//load the title, but we are not going to use them
	std::string file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;
	dbfile>>file;

	std::string fighter;
	std::map <std::string, Fighter> all_data;
	//loop through each line and get data from each move and create fighter
	//class to generate a map which first is name and second is all the data and stuff
	while(dbfile >> fighter){

		int jab;
		int forward_tilt; 
		int up_tilt;
		int down_tilt; 
		int forward_smash; 
		int up_smash; 
		int down_smash;
		dbfile >> jab;
		dbfile >> forward_tilt;
		dbfile >> up_tilt;
		dbfile >> down_tilt;
		dbfile >> forward_smash;
		dbfile >> up_smash;
		dbfile >> down_smash;
		all_data[fighter] = Fighter(fighter,jab,forward_tilt,up_tilt,down_tilt, forward_smash,up_smash,down_smash);
	}
	return all_data;
}

int main(int argc, char* argv[] ){
	// Argument parsing
	if(argc != 4){
		std::cerr << "Proper usage is " << argv[0] << " [database file] [input file] [output file]" << std::endl;
		return -1;
	}

	std::ifstream dbfile(argv[1]);
	if(!dbfile){
		std::cerr << "Failed to open database " << argv[1] << " for reading." << std::endl;
	}

	std::ifstream infile(argv[2]);
	if(!infile){
		std::cerr << "Failed to open input " << argv[2] << " for reading." << std::endl;
	}

	std::ofstream outfile(argv[3]);
	if(!outfile){
		std::cerr << "Failed to open output " << argv[3] << " for writing." << std::endl;
	}

	///////Fill in the rest of main below:

	//load the data
	std::map<std::string,Fighter> all_data = load(dbfile);
	std::string command;
	while(infile >>command){
		if(command == "-q"){
			//load the move
			std::string name;
			std::string move;
			infile >> name;
			infile >> move;
			//check if that fighter name and move are valid
			bool found = false;
			if(all_data.count(name) == 0){
				outfile << "Invalid character name: "<< name<<std::endl<<std::endl;
				continue;
			}	
			for(int i = 0; i < 7;++i){
				if(move_names[i] == move) {found = true;break;}
			}
			if(found == false&& move !="all"){
				outfile << "Invalid move name: "<< move << std::endl<<std::endl;
				continue;
			}
			
			
			//if the command is not all, just print the specific move's frame
			if(move != "all"){
				Fighter temp;
				temp = all_data[name];
				outfile<< name <<" "<< move << ": "<< temp.get_frame()[move] <<std::endl;
				outfile<<std::endl;
			}
			else{
				//else print them all
				Fighter temp;
				temp = all_data[name];
				outfile <<name<<" "<<"down-smash: "<< temp.get_frame()["down-smash"]<<std::endl;
				outfile <<name<<" "<<"down-tilt: "<< temp.get_frame()["down-tilt"]<<std::endl;
				outfile <<name<<" "<<"forward-smash: "<< temp.get_frame()["forward-smash"]<<std::endl;
				outfile <<name<<" "<<"forward-tilt: "<< temp.get_frame()["forward-tilt"]<<std::endl;
				outfile <<name<<" "<<"jab: "<< temp.get_frame()["jab"]<<std::endl;
				outfile <<name<<" "<<"up-smash: "<< temp.get_frame()["up-smash"]<<std::endl;
				outfile <<name<<" "<<"up-tilt: "<< temp.get_frame()["up-tilt"]<<std::endl;
				outfile<<std::endl; 
			}
		}

		if(command == "-d"){
			std::string move;
			int frame;
			infile>>move>>frame;
			//check if that is a valid move
			bool found = false;
			for(int i = 0; i < 7;++i){
				if(move_names[i] == move) {found = true;break;}
			}
			if(found==false){
				outfile << "Invalid move name: "<< move << std::endl<<std::endl;
				continue;
			}
			outfile<<"-d "<<move<<" "<<frame<<std::endl;
			//find the fighter w/ certain move
			std::set <std::string> set_d = find_d(all_data,move,frame);
			//loop through the returned set and print the result
			std::set<std::string>::iterator itr = set_d.begin();
			while(itr != set_d.end()){
				outfile<<*itr<<std::endl;
				itr++;
			}
			outfile<<std::endl;
		}
		//find the fastest frame move
		if(command == "-f"){
			std::string move;
			int frame;
			infile >> move >> frame;
			//check if that is a valid move
			bool found = false;
			for(int i = 0; i < 7;++i){
				
				if(move_names[i] == move) {found = true;break;}
			}
			if(found==false){
				outfile << "Invalid move name: "<< move << std::endl<<std::endl;
				continue;
			}

			outfile << "-f "<<move<<" "<<frame<<std::endl;
			//order the set of fighters with accoding move
			std::set<Fighter> output = find_f(all_data,move,false);
			std::set<Fighter>::iterator itr = output.begin();
			//loop through the returned set and print the data
			while(frame != 0){
				outfile<<itr->get_name()<<" "<<itr->get_frame()[move]<<std::endl;
				frame --;
				itr ++;
			}
			outfile << std::endl;
		}
		//find the slowest move with specific move
		if(command == "-s"){
			std::string move;
			int frame;
			infile >> move >> frame;
			//check if that's a valid move 
			bool found = false;
			for(int i = 0; i < 7;++i){
				if(move_names[i] == move) {found = true;break;}
			}
			if(found==false){
				outfile << "Invalid move name: "<< move << std::endl<<std::endl;
				continue;
			}
			//basically same as -f command but print those reversely
			outfile << "-s "<<move<<" "<<frame<<std::endl;
			std::set<Fighter> output = find_f(all_data,move,true);
			std::set<Fighter>::iterator itr = output.end();
			itr--;
			while(frame != 0){
				outfile<<itr->get_name()<<" "<<itr->get_frame()[move]<<std::endl;
				frame --;
				itr --;
			}
			outfile << std::endl;

		}
	}
	
	



	return 0;
}
