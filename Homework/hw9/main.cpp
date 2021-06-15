#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "movie.h"



/*
These two functions are not required for your program, but may be helpful!
The recursive function will generate every combination of 0/1 for 6 positions
in a vector. Whenever pos == 6, the vector is complete.

Hint: There are 6 different "fields" in a query, this may be useful in constructing
your hash table.
*/
void resize_data(std::vector<std::pair<std::string, std::list<int> > > &full_info, std::vector<Movie> &base_data, int &key,float& occupancy);
//I copy this hash function from lab  and N is the size of hash table so it return within the index range
unsigned int hash(std::string const& key, unsigned int N) {
   unsigned int hash = 1315423911;
    for(unsigned int i = 0; i < key.length(); i++)
      hash ^= ((hash << 5) + key[i] + (hash >> 2));
    return hash % N;
}

void permute_filters(int pos, std::vector<int> filter, Movie &one_movie, std::vector<std::pair<std::string, std::list<int> > > &full_info,
	std::vector<Movie> &base_data, int& key, float& occupancy, int index){
	if(pos == 6){
		//Add other code here if you want to use the completed vectors
		//after generate the filter vector, base on that result, we so the insert
		//this below is creating the query which the will be the input of hash function 
		std::string hash_string = "";
		int count = 0;
		//loop through the filter and add the result of different permutation of query
		//so the query will be a string which will be name+year+runningtime+#of genre+all the genre+#of actor+actors+#of role+roles
		for(std::vector<int>::iterator itr = filter.begin(); itr != filter.end(); itr++){
			//deal with title
			if(count == 0){
				if(*itr == 0) hash_string += "?";
				else hash_string += one_movie.title();
			}
			//deal with year
			if(count == 1){
				if(*itr == 0) hash_string += "?";
				else hash_string += one_movie.year();
			}
			//deal with running time
			if(count == 2){
				if(*itr == 0) hash_string += "?";
				else hash_string += one_movie.time();
			}
			//deal with genre
			if(count == 3){
				if(*itr == 0) hash_string += "0";
				else{
					hash_string += std::to_string(one_movie.genre().first);
					for(std::list<std::string>::iterator itr2 = one_movie.genre().second.begin();
				 	itr2 != one_movie.genre().second.end(); itr2++){
					hash_string += *itr2;}
				}
			}
			//deal with actors
			if(count == 4){
				if(*itr == 0) hash_string += "0";
				else{
					hash_string += std::to_string(one_movie.actor().first);
					for(std::list<std::string>::iterator itr2 = one_movie.actor().second.begin(); 
						itr2 != one_movie.actor().second.end(); itr2++){
					hash_string += *itr2;}
				}
			}
			//deal with roles
			if(count == 5){
				if(*itr == 0) hash_string += "0";
				else {
					hash_string += std::to_string(one_movie.role().first);
					for(std::list<std::string>::iterator itr2 = one_movie.role().second.begin(); 
						itr2 != one_movie.role().second.end(); itr2++){
					hash_string += *itr2;}
				}
			}
			count ++;
		}
		

		//then we create the hash number base on the string we created and the size of hash table
		unsigned int hash_number = hash(hash_string,full_info.size());
		//up date the number of content that actually inserted into the hash table
		key++;
		//find if we need to resize the hash table
		if(float(key)/float(full_info.size()) > occupancy){
			resize_data(full_info,base_data,key ,occupancy);
		}

		//where i think should deal w/ collision and actual insert
		// this if statement if the normal insert where no collision happened
		if(full_info[hash_number].second.empty() || 
			(!full_info[hash_number].second.empty() && full_info[hash_number].first == hash_string) ){
			full_info[hash_number].first = hash_string;
			full_info[hash_number].second.push_back(index);
		}
		//this else statement is dealing w/ the collision 
		else{
			
			int i = 1;//this is help to keep track the index
			//so we start w/ the hash index and keep looking after that index to find a empty spot or the query 
			//that correspond w/ the one I am going in insert
			while(true){
				hash_number++;
				//if there is a empty spot after that, them put that in and update the query
				if( full_info[hash_number].second.empty()){
						full_info[hash_number].first = hash_string;
						full_info[hash_number].second.push_back(index);			
						break;
				}
				//if the query is same as what we want to insert, then we just add that into that line
				if( full_info[hash_number].first == hash_string){	
					full_info[hash_number].second.push_back(index);	
					break;
				}
				if((unsigned int)i == full_info.size()) break;
				i++;
			}		
		}
		return;
	}

	filter.push_back(0);
	std::vector<int> filter_new = filter;
	filter_new.back() = 1;
	permute_filters(pos+1, filter_new,one_movie,full_info,base_data,key,occupancy,index);
	permute_filters(pos+1, filter,one_movie,full_info,base_data,key,occupancy,index);
}

//Driver function, feel free to modify to pass more arguments
void permute_filters(Movie &one_movie,std::vector<std::pair<std::string, std::list<int> > > &full_info,
	std::vector<Movie> &base_data, int &key,float& occupancy,int index ){
		permute_filters(0, std::vector<int>(), one_movie, full_info,base_data,key,occupancy,index);
}
//this resize_data is relatively simple, we just created a new hash table w/ size doubled. and then re-create the hash table and copy it
void resize_data(std::vector<std::pair<std::string, std::list<int> > > &full_info, 
	std::vector<Movie> &base_data, int &key,float& occupancy){

	key = 0;//update the key value
	int count = 0;
	//resize the table
	std::vector<std::pair<std::string, std::list<int> > > new_table(full_info.size()*2);
	//for each table in the element, create the new table
	for(std::vector<Movie>::iterator itr = base_data.begin(); itr != base_data.end(); ++itr){
		permute_filters(*itr, new_table, base_data, key, occupancy,count);
		count ++;
	}
	full_info = new_table;

}

//load the actor file by using simple map
void load_actors(std::ifstream &file, std::map<std::string, std::string> &actors){
	std::string number;
	std::string name;
	while(file >> number){
		file>>name;
		actors[number] = name;
	}
	return;
}
//load the movie file and create each movie class 
void load_movies(std::ifstream &file, std::vector<std::pair<std::string, std::list<int> > > &movie_data, 
	std::vector<Movie> &base_data, int& key, float& occupancy){
	std::string title;
	std::string year;
	std::string time;
	std::string temp;
	int num1, num2, num3;
	std::list<std::string> l1,l2,l3;
	//read everything we need and create one movie object
	while(file >> title){
		l1.clear();
		l2.clear();
		l3.clear();
		file >> year;
		file >> time;
		file >> num1;		
		for(int i = 0; i < num1; ++i) {
			file >> temp;
			l1.push_back(temp);
		}
		file >> num2;
		for(int j = 0; j < num2; ++j){
			file >> temp;
			l2.push_back(temp);
		}
		file>>num3;
		for(int k = 0; k < num3; ++k){
			file >> temp;
			l3.push_back(temp);
		}
		//create the movie class called one movie
		Movie one_movie(title, year, time, std::make_pair(num1,l1),std::make_pair(num2, l2), std::make_pair(num3, l3));
		base_data.push_back(one_movie);//push one into the movie vector
		//then create different permutation of one movie
		permute_filters(one_movie , movie_data,base_data, key,occupancy,base_data.size()-1);
	}

}





int main()
{
	//assumne the table size is 100 and occupancy is o.5
	int table_size = 100;
	float occupancy = 0.5;
	int key = 0;
	std::string input;
	//actors record all the actor data
	std::map<std::string, std::string> actors;
	//actural hash table and index inside are pointing to the base data
	std::vector<std::pair<std::string, std::list<int> > > movie_data(table_size);
	//base data record the actural data of movies 
	std::vector<Movie> base_data;
	while(std::cin >> input){
		if(input == "quit") break;
		//resize the hash table
		if(input =="table_size") std::cin >> table_size;
		//resize the occupancy
		if(input == "occupancy") std::cin >> occupancy;
		//load the actor data
		if(input == "actors"){
			std::string temp;
			std::cin >> temp;
			std::ifstream actor_file(temp);
			load_actors(actor_file, actors);
		}
		//load the movie data
		if(input == "movies"){
			movie_data.resize(table_size);
			std::string temp;
			std::cin >> temp;
			std::ifstream movie_file(temp);
			load_movies(movie_file,movie_data,base_data,key,occupancy);

		}
		//"find" function
		if(input == "query"){
			//create the "hash answer"
			//which is the string base on the input
			std::string title,year,time;
			int temp_num;
			std::string temp_str;
			std::string genre, actor, role;

			std::cin>>title>> year>>time;
			std::cin>>temp_num;
			genre += std::to_string(temp_num);
			for(int i = 0; i < temp_num; ++i){
				std::cin >> temp_str;
				genre += temp_str;

			}
			std::cin>>temp_num;
			actor += std::to_string(temp_num);
			for(int i = 0; i < temp_num; ++i){
				std::cin >> temp_str;
				actor += temp_str;

			}
			std::cin>>temp_num;
			actor += std::to_string(temp_num);
			for(int i = 0; i < temp_num; ++i){
				std::cin >> temp_str;
				role += temp_str;

			}
			
			unsigned int hash_answer = hash(title+year+time+genre+actor+role,movie_data.size());

			std::string query = (title+year+time+genre+actor+role);
		
			bool found = true;
			std::list<Movie> output; 
			//make sure if we find the result if not, print "no results"
			if(query != movie_data[hash_answer].first){
				unsigned int i = 1;
				while(true){
					hash_answer = (hash_answer+i)% movie_data.size();
					if(query ==  movie_data[hash_answer].first) break;
					++i;
					if(i ==  movie_data.size()){
						std::cout<<"No results for query."<<std::endl;
						found = false;
						break;
					}
				}
			}
			if(!found) continue;
			//right now, we know we find the thing in the hash table
			//copy that line of hash table
			for(std::list<int>::iterator i = movie_data[hash_answer].second.begin(); i != movie_data[hash_answer].second.end(); ++i ){
				
				output.push_back(base_data[*i]);
			}
			if(query == "???000") output.pop_back();


			// print out the result as the format required
			std::cout<<"Printing "<< output.size() << " result(s):"<<std::endl;
			for(std::list<Movie>::iterator itr = output.begin(); itr != output.end(); itr++){
				std::cout<<itr->title()<<std::endl;
				std::cout<<itr->year()<<std::endl;
				std::cout<<itr->time()<<std::endl;

				std::cout<<itr->genre().first;
				for(std::list<std::string>::iterator itr2 = itr->genre().second.begin(); itr2 != itr->genre().second.end(); itr2++){
					std::cout<<" "<<*itr2;
				}
				std::cout<<std::endl;

				std::cout<<itr->actor().first;
				std::list<std::string>::iterator itr3 = itr->role().second.begin();
				for(std::list<std::string>::iterator itr2 = itr->actor().second.begin(); itr2 != itr->actor().second.end(); itr2++){
					std::cout<<" "<<actors[*itr2]<<" "<<"("<<*itr3<<")";
					itr3++;
				}
				std::cout<<std::endl;
			}
		}
	}
	return 0;
}