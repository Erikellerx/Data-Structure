



class Time
{
public:
	Time();
	Time(int ahour, int aminute, int asecond );


	int getHour() const;
	int getMinute() const;
	int getSecond() const;


	void setHour(int newHour);
	void setMinute(int newMinute);
	void setSecond(int newSecond);

	void PrintAMPM();



private:
	int hour;
	int minute;
	int second;

};


bool IsEarlierThan(const Time& t1, const Time& t2);
