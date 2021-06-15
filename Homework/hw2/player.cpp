#include <iostream>
#include "player.h"
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>




player::player(std::string afirstname,std::string alastname,std::string acountry){

	firstname = afirstname;
	lastname = alastname;
	country = acountry;
	

	events = {"100_METERS","LONG_JUMP","SHOT_PUT","HIGH_JUMP","400_METERS","110_METERS_HURDLES","DISCUS_THROW","POLE_VAULT","JAVELIN_THROW","1500_METERS"};
	scores = {"0","0","0","0","0","0","0","0","0","0"};//create  vector of their score(assume they get 0 initially)
	allpoints = {0,0,0,0,0,0,0,0,0,0,0};//(their points they get)
	

}


bool player::comparename(std::string firstname,std::string lastname) {
	return firstname==firstname&&lastname==lastname;
}

std::string player::getlastname() const{
	return lastname;
}
std::string player::getfirstname() const{
	return firstname;
}

std::string player::getcountry() const{
	return country;
}
std::vector<std::string> player::getscore() const{
	return scores;
}
int player::gettotal() const{//total score has been pushed back into the last index of vector
	return allpoints[allpoints.size()-1];
}



//sort 2 player classes by their name and country
bool sort(const player& player1, const player& player2){
	if(player1.getcountry() == player2.getcountry()){
		return player1.getlastname() < player2.getlastname();
	}
	else{
		return player1.getcountry() < player2.getcountry();
	}
}

//sore 2 player classes by their total points 
bool sortpoint(const player& player1, const player& player2){
	return player1.gettotal() > player2.gettotal();
}

//print all scores they get in the output file
void player::printscore(std::ofstream &output_file,int long_name){

	

	output_file<<std::left<<std::setw(long_name+4)<<firstname;
	output_file<<std::left<<std::setw(14)<<lastname;
	output_file<<country;

	for (unsigned int i = 0; i <scores.size() ; ++i)
	{
		if(scores[i]=="0"){
			output_file<<std::right<<std::setw(7)<<" ";
		}
		else if (i == scores.size()-1){
			output_file<<std::right<<std::setw(9)<<scores[i];
		}
		else{
			output_file<<std::right<<std::setw(7)<<scores[i];
		}
		
	}
	output_file<<std::endl;
	
}

//print all the points they get into the output file
void player::printpoint(std::ofstream &output_file,int long_name){

	

	output_file<<std::left<<std::setw(long_name+4)<<firstname;
	output_file<<std::left<<std::setw(14)<<lastname;
	output_file<<country;

	for (unsigned int i = 0; i <allpoints.size() ; ++i)
	{
		
		if (i == allpoints.size()-1 || i == allpoints.size()-2){
			output_file<<std::right<<std::setw(9)<<allpoints[i];
		}
		else{
			output_file<<std::right<<std::setw(7)<<allpoints[i];
		}
		
	}
	output_file<<std::endl;
	
}

//all score of that player according the event they attend
void player::addscore(std::string aevent, std::string ascore){
	for (int i = 0; i <  10; ++i)
	{
		if (events[i] == aevent ){
			scores[i] = ascore;
		}
	}
}

//transfer the score they get in all event and turn them into points 
void player::cal_points(){
    std::vector<float> points;//points stores all the scores in float

    for (unsigned int i = 0; i < scores.size()-1; ++i)
    {
        float point = std::stof(scores[i]);//change string into float except last one 
        points.push_back(point);
    }


    //this part is dealing with 1500m part which cannot be directly turned into float
    std::string str_time=scores[9];
    if(str_time != "0"){
    	std::string str_minute;
    	std::string str_second;
    	if(str_time.length() == 7){

    		str_minute=str_time.substr(0,1);
	    	str_second=str_time.substr(2,6);//i use substring to seperate minute and second.

    	}
    	else{//if the time start with 0 something
    		str_minute=str_time.substr(0,2);
	    	str_second=str_time.substr(3,7);//i use substring to seperate minute and second.

    	}
    	
	    


	    
	    float minute = std::stof(str_minute);
	    float second = std::stof(str_second);

	    //calculate the total time by second
	    float time_total = second + minute * 60 ;
	    

	    points.push_back(time_total);

    }
    else{
    	points.push_back(0);
    }
    
    std::vector<int> points_output;//this part stores points they get 

    for (unsigned int i = 0; i < points.size(); ++i)
    {
    	float one_point;
    	if (points[i] != 0){
	        
	        //this part is calculate the points according the table
	        if(i == 0){one_point = int(25.4347*pow((18-points[i]),1.81));}
	        if(i == 1){one_point = int(0.14354*pow((points[i]*100-220),1.4));}
	        if(i == 2){one_point = int(51.39*pow((points[i]-1.5),1.05));}
	        if(i == 3){one_point = int(0.8465*pow((points[i]*100-75),1.42));}
	        if(i == 4){one_point = int(1.53775*pow((82-points[i]),1.81));}
	        if(i == 5){one_point = int(5.74352*pow((28.5-points[i]),1.92));}
	        if(i == 6){one_point = int(12.91*pow((points[i]-4),1.1));}
	        if(i == 7){one_point = int(0.2797*pow((points[i]*100-100),1.35));}
	        if(i == 8){one_point = int(10.14*pow((points[i]-7),1.08));}
	        if(i == 9){one_point = int(0.03768*pow((480-points[i]),1.85));}
	        points_output.push_back(one_point);
    	}
        else{
        	points_output.push_back(0);
        }

    }

    int sum=0;
    //calculate the total points (sum)
    for (unsigned int i = 0; i < points_output.size(); ++i)
    {
       
        
        sum += points_output[i];

    }
    points_output.push_back(sum);

    for (unsigned int i = 0; i < points_output.size(); ++i)
    {
    	//std::cout<<points_output[i];
    }
    //std::cout<<std::endl;

    allpoints = points_output;



}
void player::cal_average(){//this function is calculate the average of points each player earn

	int sum = allpoints[allpoints.size()-1];
	allpoints.pop_back();
	
	int num = 0;
	for (unsigned int i = 0; i < allpoints.size(); ++i)//calculate how many events one player attend
	{
		if(allpoints[i] != 0){
			
			num += 1;
		}
		
	}
	int average = int(sum/num);
	

	allpoints.push_back(average);


}


