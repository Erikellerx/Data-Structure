#include <iostream>
#include <string>
#include <cassert>
#include "Board.h"

void SimpleTest(); //Some basic tests
void StudentTest(); //Write your own test cases here

int main(){
	SimpleTest();
	std::cout << "Completed all simple tests." << std::endl;

	StudentTest();
	std::cout << "Completed all student tests." << std::endl;

	return 0;
}

// Do not modify this function - a fresh copy will be used on Submitty
void SimpleTest(){
	Board b("R","Y",".");

	std::cout << "Initial board:" << std::endl << b << std::endl;
	std::cout << "Row 0 has " << b.numTokensInRow(0) << std::endl;
	std::cout << "Row 4 has " << b.numTokensInRow(4) << std::endl;
	std::cout << "Row 5 has " << b.numTokensInRow(5) << std::endl;
	std::cout << "Column 0 has " << b.numTokensInColumn(0) << std::endl;
	std::cout << "Column 3 has " << b.numTokensInColumn(3) << std::endl;
	std::cout << "Column 4 has " << b.numTokensInColumn(4) << std::endl;

	b.insert(0,true);
	std::cout << "Second handout figure" << std::endl << b << std::endl;

	b.insert(1,false);
	b.insert(2,true);
	b.insert(3,true);
	std::cout << "Third handout figure" << std::endl << b;
	std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
			  << std::endl << std::endl;

	b.insert(1,true);
	b.insert(1,false);
	b.insert(1,true);
	b.insert(1,false);
	b.insert(1,true);
	std::cout << "Fourth handout figure" << std::endl << b;
	std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
			  << std::endl << std::endl;

	b.insert(4,true);
	std::cout << "Fifth handout figure" << std::endl << b;
	std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
			  << std::endl << std::endl;

	//Looks ugly if we don't make all tokens the same length, but not required
	Board b2("Puppy","Kitty","-----"); 
	std::string result;
	std::cout << "Starting a new board!" << std::endl;
	std::cout << "Board is now" << std::endl << b2 << std::endl;
	result = b2.insert(1,true);
	std::cout << "Board is now" << std::endl << b2 << std::endl;
	if(result == "-----"){
		std::cout << "No winner yet." << std::endl;
	}
	else{
		std::cout << "The winner is: " << result << std::endl;
	}
	result = b2.insert(1,true);
	std::cout << "Board is now" << std::endl << b2 << std::endl;
	if(result == "-----"){
		std::cout << "No winner yet." << std::endl;
	}
	else{
		std::cout << "The winner is: " << result << std::endl;
	}
	result = b2.insert(1,true);
	std::cout << "Board is now" << std::endl << b2 << std::endl;
	if(result == "-----"){
		std::cout << "No winner yet." << std::endl;
	}
	else{
		std::cout << "The winner is: " << result << std::endl;
	}
	result = b2.insert(1,true);
	std::cout << "Board is now" << std::endl << b2 << std::endl;
	if(result == "-----"){
		std::cout << "No winner yet." << std::endl;
	}
	else{
		std::cout << "The winner is: " << result << std::endl;
	}
}

////////STUDENT CODE//////

//Write your own test cases here
void StudentTest(){

	std::cout<<"Gap test"<<std::endl;
	 std::string result;
	 Board b("X","O",".");
	 std::cout<<b<<std::endl;
	 b.insert(10,true);
	 std::cout<<b<<std::endl;
	 b.insert(1,true);
	 b.insert(10,false);
	 b.insert(10,true);
	 b.insert(10,false);
	 b.insert(10,true);
	 b.insert(10,false);
	 b.insert(10,true);
	 b.insert(10,false);
	 b.insert(10,true);
	 b.insert(10,false);

	 b.insert(1,false);
	 b.insert(4,false);
	 b.insert(4,false);

	
	std::cout<<b<<std::endl;
	Board b1(b);

	b.clear();
	std::cout<<"Clear function test"<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<"copy constructor test\n"<<std::endl;
	std::cout<<b1<<std::endl;
	b1.insert(2,false);
	result = b1.insert(2,false);
	std::cout<<b1<<std::endl;
	if (result == ".")
	{
		std::cout<<"NO winner yet"<<std::endl;
	}
	else{
		std::cout<<"The winner is "<<result<<std::endl;
	}
	b1.insert(3,false);
	result = b1.insert(3,false);
	std::cout<<b1<<std::endl;
	if (result == ".")
	{
		std::cout<<"NO winner yet"<<std::endl;
	}
	else{
		std::cout<<"The winner is "<<result<<std::endl;
	}

	b.insert(1,true);
	b.insert(10,false);
	b.insert(10,true);
	b.insert(10,false);
	b.insert(10,true);
	b.insert(10,false);
	b.insert(10,true);
	b.insert(10,false);
	b.insert(10,true);
	b.insert(10,false);

	std::cout<<"assignment operator test"<<std::endl;
	std::cout<<"this is b\n"<<b<<std::endl;
	Board b2 = b;
	std::cout<<"this is b2\n"<<b2<<std::endl;

	b.insert(4,true);
	std::cout<<"this is b2 after b added(b.insert(4,true))\n"<<b2<<std::endl;
	b2.insert(6,false);
	std::cout<<"this is b after b2 added(b2.insert(6,false))\n"<<b<<std::endl;


	b2 = b2;
	std::cout<<"This is b2\n"<<b2<<std::endl;
	
	std::cout << "Row 0 has " << b.numTokensInRow(0) << std::endl;
	std::cout << "Row 4 has " << b.numTokensInRow(4) << std::endl;
	std::cout << "Row 100 has " << b.numTokensInRow(100) << std::endl;
	std::cout << "Column 0 has " << b.numTokensInColumn(0) << std::endl;
	std::cout << "Column 10 has " << b.numTokensInColumn(10) << std::endl;
	std::cout << "Column 14 has " << b.numTokensInColumn(14) << std::endl;
	std::cout<<std::endl;
	b.clear();
	std::cout<<"testing copy from empty(aftet b.clear())"<<std::endl;
	b=b;
	std::cout<<"This is b\n"<<b<<std::endl;



}

