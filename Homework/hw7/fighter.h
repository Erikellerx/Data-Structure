
#include <map>


class Fighter{
public:
	Fighter(){}
	Fighter(std::string fighter,int jab, int forward_tilt, int up_tilt, int down_tilt, int forward_smash, int up_smash, int down_smash);

	std::map<std::string, int> get_frame() const ;
	std::string get_name() const ;
	void set_comparsion(std::string a);
	void set_which();
	//use friend function so it can access private member variable
	friend bool operator< (Fighter f1, Fighter f2);







private:
	std::map <std::string, int > frame;
	std::string name;//record fighter's name
	std::string compare_name;//recorde which move to compare
	bool which;//record which type of ordering to compare



};

bool operator< (Fighter f1, Fighter f2);
