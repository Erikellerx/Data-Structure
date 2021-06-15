
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "recipe.h"
#include "kitchen.h"



void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void printRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen);
int makeRecipe(std::istream &istr, std::ostream &ostr,  std::list<Recipe> &recipes, Kitchen &kitchen);




int main(int argc, char* argv[]) {

  // Check the number of arguments.
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
    return 1;
  }
  // Open and test the input file.
  std::ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "Could not open " << argv[1] << " to read\n";
    return 1;
  }
  // Open and test the output file.
  std::ofstream ostr(argv[2]);
  if (!ostr) {
    std::cerr << "Could not open " << argv[2] << " to write\n";
    return 1;
  }
  Kitchen kitchen;
  std::list<Recipe> recipes;

  // some variables to help with parsing
  char c;
  while (istr >> c) {
  	
    if (c == 'r') {
      // READ A NEW RECIPE
      readRecipe(istr,ostr,recipes);

    }else if (c == 'a') {
      // ADD INGREDIENTS TO THE KITCHEN
      addIngredients(istr,ostr,kitchen);

    }else if (c == 'p' ){
    	printRecipe(istr,ostr,recipes);


    }else if (c == 'm') {
      // MAKE SOME FOOD
      makeRecipe(istr,ostr,recipes,kitchen);

    } else if (c == 'k') {
      //print the kitchen list
      kitchen.print(ostr);

    }
    }
}



void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
  int units;
  std::string name, name2;  
  istr >> name;
  // build the new recipe
  Recipe r(name);
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name2;
    r.addIngredient(name2,units);
  }
  //check if that recipe has already been added 
  bool found = false;
  for(std::list<Recipe>::iterator itr = recipes.begin(); itr != recipes.end(); ++itr){
    if(name == itr ->getname()){
      found = true;
      break;
    }
  }
  //if they are print the warning
  if(found){
    ostr<<"Recipe for "<<name<<" already exists"<<std::endl;
  }
  //if not, add to the list
  else{
  recipes.push_back(r);
  ostr << "Recipe for " << name << " added" << std::endl;
}
}

void printRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
  std::string name;
  istr >> name;
  //first seach the recipes list if there is recipe we want
  bool found = false;
  for (std::list<Recipe>::iterator itr = recipes.begin(); itr != recipes.end(); ++itr)
  {
    //if there is , print it!
  	if(name == itr->getname()){
  		itr->print(ostr);
  		found = true;
  		break;
  	}
  }

//if there is not, print the warning 
  if(!found){
  	ostr<<"No recipe for "<<name<<std::endl;
  }
}
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
  int units;
  std::string name;
  int count = 0;
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name;
    // add the ingredients to the kitchen
    kitchen.addIngredient(name,units);
    count++;
  }
  //print the resule that ingredient are added to the kitchen 
  if (count != 0 && count == 1){
  ostr << count << " ingredient added to kitchen" << std::endl;}
  else if(count != 0){ostr << count << " ingredients added to kitchen" << std::endl;}
}

int makeRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes, Kitchen &kitchen) {
  std::string name;
  istr >> name;
  bool found = false;
  
  //first find it there is the recipe we want in the list, 
  Recipe rec;
  for (std::list<Recipe>::iterator itr = recipes.begin(); itr != recipes.end(); ++itr){
  	
  	if(itr->getname() == name){
  		found = true;
  		rec = *itr;
  		break;
  	}
  }
  //if not print out the resule and stop the entire function 
  if(!found){ostr<<"Don't know how to make "<<name<<std::endl;return 1;}

  //if there is, find out if there is enough ingredient we want in the kitchen 
  std::list<std::string> ingredients = rec.geting();
  std::list<std::string> k_had = kitchen.geting();
  bool enough = true;
  //go through the list of kitchen and check if our food in kitchen left are enough
  for(std::list<std::string>::iterator itr=ingredients.begin(); itr!= ingredients.end();itr++){

  	if(kitchen.count(*itr) >= rec.count(*itr)){continue;}
  	enough = false;  	
  }
  //if there is enough ingredient, start making and remove certain amount of food in the kitchen according recipe
  std::string temp = " ";
  if(enough){
  	for(std::list<std::string>::iterator itr=ingredients.begin(); itr!=ingredients.end();itr++){

  		if(temp == *itr){continue;}
  		temp = *itr;  		
  		kitchen.remove(*itr, rec.count(*itr));
  		
  	}
  	ostr<<"Made "<<name<<std::endl;
  	return 0;
  }
  //if there isn't enough ingredient, then just need to print the result and calculate what's more we need 
  if(!enough){
  	ostr<<"Cannot make "<<name<<", need to buy:"<<std::endl;
  	for(std::list<std::string>::iterator itr=ingredients.begin(); itr!=ingredients.end();itr++){
  		
  		if(kitchen.count(*itr) >= rec.count(*itr)){continue;}
  		if(temp == *itr){continue;}
      //this part is the start of calculation of whats more we need
  		temp = *itr;
  		int diff = 0;
  		diff = rec.count(*itr) - kitchen.count(*itr);
      if(diff == 1){
  		ostr<<"  "<<diff<<" unit of "<<*itr<<std::endl;}
      else{
        ostr<<"  "<<diff<<" units of "<<*itr<<std::endl;
      }
  	}
  }
  return 0;
}

















