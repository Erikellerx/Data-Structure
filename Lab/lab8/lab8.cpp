
#include <string>
#include <iostream>

int count(int x,int y){
	if(x == 0){
		return 1;
	}
	else if (y == 0){
		return 1;
	}
	else{
		return count(x-1,y)+count(x,y-1);
	}
}




int main()
{
	int a;
	a = count(0,0);
	std::cout<<count(0,0)<<std::endl;
	std::cout<<count(2,1)<<std::endl;
	std::cout<<count(2,2)<<std::endl;
	std::cout<<count(0,0)<<std::endl;
	return 0;
}