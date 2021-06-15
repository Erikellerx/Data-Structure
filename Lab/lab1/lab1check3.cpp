
#include <fstream>
#include <iostream>


int main( int argc ,  char* argv[] ) {

    std::ifstream in_str(argv[1]);
    if (!in_str.good()){
        std::cerr << "Can't open " << argv[1] << "to read. \n";
        exit(1);
    }
    std::string str_num;
    int sum;
    float mean;
    int min = 100 ;
    int howmany ;
    while (in_str >> str_num){


        howmany++;

        int num = atoi(str_num.c_str());
        

        sum += num;



        if(min > num){
            min = num;
        }


    }
    mean = float(sum)/float(howmany);

    std::cout<<"How many num "<<howmany<<std::endl;
    std::cout<<"smallest "<<min<<std::endl;
    std::cout<<"mean "<<mean<<std::endl;




    return 0;
}
