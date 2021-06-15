#include<string>
#include<list>
#include<iostream>


using namespace std;

class Kitchen{

public:

	void addIngredient(const string &name, int units);
	void print(std::ostream &ostr);
	int count(string &name);
	list<string> geting() const ;
	void remove(const string &stuff, int num);

private:
	list<string> food;

	
};
bool compare( const string &s1, const string &s2);