#include "Board.h"

Board::Board(std::string p1, std::string p2, std::string empty){
	player1 = p1;
	player2 = p2;
	empty_str = empty;
	row = 5;
	col = 4;
	//numInCol remembers how many elements has been added 
	//into that column
	numInCol = new int[col];
	//assume there are none 
	for (int i = 0; i < col; ++i){numInCol[i] = 0;}
	
	//create the pointer pointing to an array of pointers 
	m_data = new std::string *[col];
	for (int i = 0; i < col; ++i)
	{
		m_data[i] = NULL;
		//assume all are null because we haven't add anything yet
	}

}
void Board::copy(const Board &b){
	
	//copy the new private variable 
	this->player1 = b.player1;
	this->player2 = b.player2;
	this->empty_str = b.empty_str;
	this->col = b.col;
	this->row = b.row;
	//initialize the numInCol and m_data
	this-> numInCol = new int[this->col];
	this->m_data = new std::string *[this->col];

	//copy the numInCol and m_data
	for (int i = 0; i < this->col; ++i){this->numInCol[i] = b.numInCol[i];}
	//initialize the m_data
	for (int i = 0; i < this->col; ++i)
	{
		if (this->numInCol[i] != 0)
		{
			this->m_data[i] =new std::string [this->numInCol[i]];
		}
		else{this->m_data[i] = NULL;}
	}
	//copy the m_data
	for (int i = 0; i < b.col; ++i)
	{		
		for (int j = 0; j < this->numInCol[i]; ++j)
		{
			this->m_data[i][j] = b.m_data[i][j];
		}	  	
	}
}
Board& Board::operator=(const Board& b){
	if (this != &b)//avoid the extra copy if they are same
	{
		for (int i = 0; i < col; ++i)
		{
			delete [] m_data[i];
		}
		delete [] m_data;
		delete [] numInCol;
		this->copy(b);
	}
	return *this;
}
void Board::clear(){
	
	//delete everything include m_data and numINCol
	for (int i = 0; i < col ; ++i)
	{
		delete []m_data[i];
	}
	delete [] m_data;
	delete [] numInCol;

	//everything below initialize the data to the original
	//same as constructor
	row = 5;
	col = 4;
	numInCol = new int[col];
	for (int i = 0; i < col; ++i){numInCol[i] = 0;}
	m_data = new std::string *[col];
	for (int i = 0; i < col; ++i){m_data[i] = NULL;}
}


int Board::numRows () const {return row;}
int Board::numColumns () const {return col;}

//this function help print out the Board class as we need
std::ostream& operator<<(std::ostream &out, const Board& b){
	for (int i = b.row-1; i >= 0; --i)
	{
		for (int j = 0; j < b.col-1; ++j)
		{
			//this if statement check if there are elements in m_data
			// if there is, print is, or we just print empty string
			//also this is help to ensure we get data outside m_data
			if (b.numInCol[j] > i)
			{
				out << b.m_data[j][i]<<" ";
			}
			else{out<<b.empty_str<<" ";}
		}
		//this is just print the last column because there isn't whitespace 
		//at the end :(
		if (b.numInCol[b.col-1] > i)
			{
				out << b.m_data[b.col-1][i];
			}
			else{out<<b.empty_str;}
		out << "\n";
	}
	return out;
}
//this function print how many elements we stored in m_data each column
//since we created an array specially record this we just print what we need
int Board::numTokensInColumn(int num){

	if (num >= col)
	{
		return -1;
	}	
	return numInCol[num];
}
//this function print how many elements we stored in m_data each row
//though we need a little bit calculation in this part
int Board::numTokensInRow(int num){
	if (num >= row)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < col; ++i)
	{
		if (num < numInCol[i])
		{
			count += 1;
		}
	}
	return count;
}
//this function insert element in the grid
std::string Board::insert(int num, bool p){
	//knows which element and where we insert it
	std::string player;
	if (p){player = player1;}
	if (!p){player = player2;}

	if (num >= col)
	{
		//extand_col function create a new column 
		extand_col(num);
	}
	//extand_row create a new row
	//since this hw require memory efficiency, we need to "push back"
	//every time when we add a element
	extand_row(num);

	//this part is actually change that spot into the player string we need
	m_data[num][numInCol[num]-1] = player;

	//this part below is checking if there are connecting four
	//out1 remember the result horizontally 
	std::string out1;
	out1 = check_col(num);
	
	if (out1 != empty_str)
	{
		return out1;
	}
	//out2 remember the result vertically
	std::string out2;
	out2 = check_row(num);
	
	if (out2 != empty_str)
	{
		return out2;
	}
	return empty_str;
}

//this function is extand row in m_data (basically need to be called each time we insert stuff)
void Board::extand_row(int num){
 
 	std::string *new_data;
 	//create the new part on that row and extand one spot 
 	new_data = new std::string [numInCol[num]+1];
 	//copy from the old data
 	for (int i = 0; i < numInCol[num]; ++i)
	{
	  new_data[i] = m_data[num][i];
	}
	//delete the old one
	if (numInCol[num] != 0)
	{
	  delete [] m_data[num];
	}
	//update the numInCol for recording
	numInCol[num] += 1;
	if (numInCol[num] > row)
	{
	  row += 1; //update the actual list size
	}
	//copy from the new one 
	 m_data[num] = new_data;
}
//this function extand column if we needed
void Board::extand_col(int num){
	//this part is update the numInCol by one spot
	//simillar to push back 
	int *new_num;
	new_num = new int[num+1];
	//initiallize to 0 first
	for (int i = 0; i < num+1; ++i)
	{
		new_num[i] = 0;
	}
	//copy from the old
	for (int i = 0; i < col; ++i)
	{
	 	new_num[i] = numInCol[i]; 	
	} 

	delete [] numInCol;

	numInCol = new_num;
/////////////////////////////////////
	//this part create new_data and copy the old and create a new col
	std::string **new_data;
	new_data = new std::string *[num+1];
	//create the new m_data's col and initiallize to NULL
	for (int i = 0; i < num+1; ++i)
	{
	  	new_data[i] = NULL;
	}
	//create the new m_data's row and initiallize to the length as we need
	for (int i = 0; i < col; ++i)
	{
		if (numInCol[i] != 0)
		{
			new_data[i] =new std::string [numInCol[i]];
		}
	}
	//this part is copying the data from the old
	for (int i = 0; i < col; ++i)
	{	
		for (int j = 0; j < numInCol[i]; ++j)
		{
			new_data[i][j] = m_data[i][j];
		} 	
	}
	//this is delete the old data and assign m_data to new_data	
	for (int i = 0; i < col; ++i)
	{  	
	  	delete [] m_data[i];		
	}	
	delete [] m_data;
	m_data = new_data;
	//change the col number
	col = num+1;	
}
//this function is checking the if there are connected four in that column
std::string Board::check_col(int num){
	//if there are less than four elements in that column, of course there are no connecred four!
	if (numInCol[num] < 4)
	{
		return empty_str;
	}

	else{
		//since we check everything time when we add an element
		//we only check the four below
		int count = 0;
		for (int i = numInCol[num]; i > numInCol[num]-4; --i)
		{
			if (m_data[num][i-1] == m_data[num][numInCol[num]-1])
			{
				count += 1;
			}
		}
		//return the result
		if (count == 4)
		{
			return m_data[num][numInCol[num]-1];
		}
		return empty_str;
	}
}
//this function check that the horizontally row
//still, we check row one time when we added
std::string Board::check_row(int num){
	int line;
	line = numInCol[num];
	//if there are less than four elements in that row return empty string
	if (this->numTokensInRow(line-1) < 4)
	{
		return empty_str;
	}
	//checking the entire row
	int count = 0;
	for (int i = 0; i < col-1; ++i)
	{
		//if there is no element next to that, count back to zero
		if (numInCol[i]<line)
		{
			count = 0;
			continue;
		}
		//if there is, count ++, if not, count back to 0
		if (line <= numInCol[i+1])
		{
			if (m_data[i][line-1]==m_data[i+1][line-1])
			{				
				count ++;				
			}
			else{count=0;}
		}	
		//if there are 3 same next to the one we added, return that string
		if (count == 3)
		{
			return m_data[num][line-1];
		}
	}
	return empty_str;
}

