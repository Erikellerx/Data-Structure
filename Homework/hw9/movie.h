
#include <string>
#include <map>
#include <list>




class Movie{
public:
	//default constructor
	Movie() {}
	//regular constructor
	Movie(std::string title, std::string year, std::string time, 
		std::pair<int, std::list<std::string> > genre,std::pair<int, std::list<std::string> > actor,
		std::pair<int, std::list<std::string> > role );

	//return the title and year and others
	std::string& title()  {return title_;}
	std::string& year() {return year_;}
	std::string& time() {return time_;}
	std::pair<int, std::list<std::string> >& genre()  {return genre_;}
	std::pair<int, std::list<std::string> >& actor()  {return actor_;}
	std::pair<int, std::list<std::string> >& role()  {return role_;}


private:
	//all the member var
	std::string title_;
	std::string year_;
	std::string time_;
	std::pair<int, std::list<std::string> > genre_;
	std::pair<int, std::list<std::string> > actor_;
	std::pair<int, std::list<std::string> > role_;

};