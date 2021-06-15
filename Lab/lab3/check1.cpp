#include <iostream>
#include <cmath>


void square(unsigned int*a, unsigned int*b, unsigned int n ){

	unsigned int *p;
	unsigned int *k;
	k = b;
	
	for(p=a; p< a+n; ++p){
		
		*k = pow(p-a,2);
		++k;
	}
}

int main()
{	int n =5 ;
	unsigned int a[n] = {1,2,3,4,5};
	unsigned int b[n];

	square(a,b,n);

	for (int i = 0; i < n; ++i)
	{
		std::cout<<*(a+i)<<" ";
	}
	std::cout<<std::endl;

	for (int i = 0; i < n; ++i)
	{
		std::cout<<*(b+i)<<" ";
	}


	return 0;
}