#include<string>
#include<list>
#include<iostream>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class Recipe{

public:
	Recipe(){}
	Recipe(string a_name);

	void addIngredient(const string &name, int units);
	void print(ostream &ostr);
	int count(const string &name);
	string getname() const;
	list<string> geting() const;


private:

	list<string> ingredient;
	string name_;


	


};