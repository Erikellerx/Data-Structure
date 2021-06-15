#include "kitchen.h"




//this function is to add ingredient in the kitchen class
void Kitchen::addIngredient(const string &name,int units){
	for (int i = 0; i < units; ++i)
	{
		food.push_back(name);
	}
	food.sort();
}

//this function gets a list of what we have now in the kitchen 
list<string> Kitchen::geting() const {
	return food;
}

//this function prints all the elements in kitchen according their number
void Kitchen::print(ostream &ostr){
	food.sort();
	list<string> temp_list;//create a temp list in order to put the output in a formatted way as we wish
	string temp = " ";
	string add;
	int num = 0;
	for (list<string>::iterator itr1 = food.begin(); itr1 !=food.end(); ++itr1){
		if(temp == *itr1){continue;}//just to make sure we won't have 2 line of tomate in the output
		temp = *itr1;
		num = this -> count(temp);//calculate the number of each item
		if(num == 1){add = to_string(num)+" unit of "+ temp;}//this line and the line below
		// add the output string into the list
		else{add = to_string(num)+" units of "+ temp;}
		temp_list.push_back(add);
		
	}
	temp_list.sort(compare);//I created a custom sort algrithm so sort as we want
	//this is print everything we have inside the temp list
	ostr<<"In the kitchen:"<<endl;
	for (list<string>::iterator itr1 = temp_list.begin(); itr1 !=temp_list.end(); ++itr1){
		ostr<<"  "<<*itr1<<endl;
	}
}

//this function count specific item inside our kitchen
int Kitchen::count(string &name){
	int count = 0;
	for (list<string>::iterator itr = food.begin(); itr !=food.end(); ++itr)
	{
		if (name == *itr)
		{
			count ++;
		}
	}
	return count;
}

//this function take in a string of what you want to remove and a int of how many of that you want ot remove
//and it will remove that many of stuff in the kitchen
// always use this function when you are sure there are enough in the kitchen !!!
void Kitchen::remove(const string &stuff, int num){
	list<string>::iterator itr = food.begin();
	//go through the list and erase until the num become 0
	while(num != 0){		
		if(*itr == stuff){	
			itr = food.erase(itr);
			num --;
		}
		else{itr++;}	
	}
}
//I created a custom compare algrthem first compare the first number from small to large, 
//if they are same, them compare the last food 
bool compare(const string &s1, const string &s2){
	//create the substring in order to compare 
	int num1 = stoi(s1.substr(0,s1.find(" ")));
	int num2 = stoi(s2.substr(0,s2.find(" ")));
	string food1 = s1.substr(s1.rfind(" ")+1, s1.size());
	string food2 = s2.substr(s2.rfind(" ")+1, s2.size());

	if(num1<num2){return true;}
	else if (num1 == num2){
		return food1 < food2;
	}
	else{return false;}

}