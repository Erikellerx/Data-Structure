#include "recipe.h"


Recipe::Recipe(string a_name){
	name_ = a_name;
}
//get the name of that string
string Recipe::getname() const{
	return name_;
}
//add the ingredient in the list
void Recipe::addIngredient(const std::string &name,int units){
	for (int i = 0; i < units; ++i)
	{
		ingredient.push_back(name);	
	}
	ingredient.sort();
}
//get the entire list of that that recipe
 list<string> Recipe::geting () const{
	return ingredient;
}
//print out the recipe
void Recipe::print(ostream &ostr){
	//sort is as alphabetically order 
	//the rest part is very close to how print in kitchen work:
	//creat a temp list and add everything formated into that list, then print
	ingredient.sort();
	list<string> temp_list;
	string temp = " ";
	string add;
	int num = 0;
	//add everything formatted in the temp list
	for (list<string>::iterator itr1 = ingredient.begin(); itr1 !=ingredient.end(); ++itr1){
		if(temp == *itr1){continue;}
		temp = *itr1;
		num = this -> count(temp);
		if(num == 1){add = to_string(num)+" unit of "+ temp;}
		else{add = to_string(num)+" units of "+ temp;}
		temp_list.push_back(add);
		
	}
	//print out the temp list
	ostr<<"To make "<<this->getname()<<", mix together:"<<endl;
	for (list<string>::iterator itr1 = temp_list.begin(); itr1 !=temp_list.end(); ++itr1){
		ostr<<"  "<<*itr1<<endl;
	}
}

//same as class kitchen, it counts the quantity of the item
int Recipe::count(const string& name){
	int count = 0;
	for (list<string>::iterator itr = ingredient.begin(); itr !=ingredient.end(); ++itr)
	{
		if (name == *itr)
		{
			count ++;
		}
	}
	return count;
}