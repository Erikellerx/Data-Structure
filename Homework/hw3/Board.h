#include <string>
#include <iostream>


class Board{

public:

	// constructor
	Board(std::string p1, std::string p2, std::string empty );
	Board(const Board &b){copy(b);}
	//destructor
	~Board(){
	for (int i = 0; i < col; ++i)
	{
		delete [] m_data[i];
	}
	delete [] m_data;
	delete [] numInCol;
}
	

	int numRows  ()const;
	int numColumns  ()const;
	//friend means this function can use the private variable inside the class
	friend std::ostream& operator<<(std::ostream &out,const Board& b);

	int numTokensInRow(int num);
	int numTokensInColumn(int num);
	std::string insert(int num, bool p);
	void clear();
	
	Board& operator=(const Board& b);



private:

	std::string player1;
	std::string player2;
	std::string empty_str;
	int row;
	int col;
	
	int *numInCol;

	std::string **m_data;

	void copy(const  Board &b);
	void extand_col(int num);
	void extand_row(int num);
	std::string check_col(int num);
	std::string check_row(int num);

};