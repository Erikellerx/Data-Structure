
#include "fighter.h"
//constructor record the frame of all moves
Fighter::Fighter(std::string fighter,int jab, int forward_tilt, int up_tilt, int down_tilt, int forward_smash, int up_smash, int down_smash){
	frame["jab"] = jab;
	frame["forward-tilt"] = forward_tilt;
	frame["up-tilt"] = up_tilt;
	frame["down-tilt"] = down_tilt;
	frame["forward-smash"] = forward_smash;
	frame["up-smash"] = up_smash;
	frame["down-smash"] = down_smash;
	name = fighter;
	which = false;
}

//return the map reocrding the move's name the its frame
std::map <std::string, int> Fighter::get_frame() const {
	return frame;
}
//return the name of that fighter
std::string Fighter::get_name() const {
	return name;
}

//set that member variable so the operator will know how to sort based on which move
void Fighter::set_comparsion(std::string a){
	compare_name = a;
}
//set bool 'which' so the operator will know we sort them accoding
//-f command or -s command 
void Fighter::set_which(){
	which = true;
}



//overload the < operator according its member variable which and compare_name
bool operator< (Fighter f1, Fighter f2){
	if(!f1.which){//compare when -f command called
		if(f1.frame[f1.compare_name]== f2.frame[f2.compare_name]) return f1.name<f2.name;
		return f1.frame[f1.compare_name] < f2.frame[f2.compare_name];
	}
	else{//compare when -s command called
		if(f1.frame[f1.compare_name]== f2.frame[f2.compare_name]) return f1.name>f2.name;
		return f1.frame[f1.compare_name] < f2.frame[f2.compare_name];
	}
}