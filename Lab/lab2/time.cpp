#include "time.h"
#include <iostream>
#include <string>
#include <algorithm>


Time::Time(){
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(int ahour, int aminute, int asecond){
	hour = ahour;
	minute = aminute;
	second = asecond;
}
int Time::getHour() const{
	return hour;
}
int Time::getMinute() const{
	return minute;
}
int Time::getSecond() const{
	return second;
}
void Time:: setHour(int newHour){
	hour=newHour;
}
void Time:: setMinute(int newMinute){
	minute=newMinute;
}
void Time:: setSecond(int newSecond){
	second=newSecond;
}
void Time::PrintAMPM(){
	std::string a = ":";
	std::string b = ":";

	if (minute < 10){
		a = ":0";
	}
	if (second < 10){
		b = ":0";
	}
	if(hour <12){
		if(hour==0){hour=12;}
		std::cout<<hour<<a<<minute<<b<<second<<" am\n";
	}



	else{
		hour-=12;
		if(hour==0){hour=12;}
		std::cout<<hour<<a<<minute<<b<<second<<" pm\n";
	}
}

bool IsEarlierThan(const Time& t1, const Time& t2){

	if(t1.getHour()<t2.getHour() || (t1.getHour() == t2.getHour() && t1.getMinute() < t2.getMinute()) ||
(t1.getHour() == t2.getHour() && t1.getMinute() == t2.getMinute() && t1.getSecond() < t2.getSecond())){

		return true;
	}

		
	else{return false;}
}
