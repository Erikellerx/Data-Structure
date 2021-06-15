#include "movie.h"


//there is only the constructor which will copy everything into the member var
Movie::Movie(std::string title, std::string year, std::string time, 
		std::pair<int, std::list<std::string> > genre,std::pair<int, std::list<std::string> > actor,
		std::pair<int, std::list<std::string> > role ){


	title_  = title;
	year_ = year;
	time_ = time;
	genre_ = genre;
	actor_ = actor;
	role_ = role;
}