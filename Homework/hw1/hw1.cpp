//file name:hw1.cpp
//purpose:this program is to take in a pattern and print our a shaped parrern txt pic
#include <fstream>
#include <iostream>
#include <string>



void square( std::string patt,  int num, std::ofstream &file, int size ){//this fuction is to help take in several parameter 
//including file itself and change file itself to add square picture

    int o = 0; //this part is helping tracing the single letter in pattern / print and repeat itself
    for (int i = 0; i < num; ++i)
        {
            if (i==0 || i == num-1)//this part is for the first line and last line 
            {
                file<<std::string(num,'*')<<std::endl;//print * on very left
            }
            else{

                file<<'*';
                for (int j = 0 ;j<num-2 ; ++j)
                {
                    if (o == size){o=0;}//this is help checking if the letter is reach the end of pattern 
                    file<<patt[o];
                    ++o;//++o allows the pattern to repeat itself
                }
                file<<'*'<<std::endl;//print * on very right side

            }

        }
    

}


void right_triangle( std::string patt,  int num, std::ofstream &file, int size ){//this fuction is to help take in several parameter 
    //including file itself and change file itself to add right triangle picture

    int o = 0; //this part is helping tracing the single letter in pattern / print and repeat itself


    for (int i = 0; i < num; ++i)
        {
            if(i==0){file<<'*'<<std::endl;}//this is the first line of triangle
            //if(i==1){std::cout<<"**"<<std::endl;}
            else if(i==num-1){file<<std::string(num,'*')<<std::endl;}//this is the last line of it
            else{
                file<<'*';
                for (int j = 0; j < i-1; ++j)
                {
                    if (o == size){o=0;}
                    file<<patt[o];
                    ++o;//++o allows the pattern to repeat itself
                }
                file<<'*'<<std::endl;
            }
        }
        
}

void isosceles_triangle( std::string patt,  int num, std::ofstream &file, int size){//this fuction is to help take in several parameter
// including file itself and change file itself to add isosceles triangle picture

    int o = 0; //this part is helping tracing the single letter in pattern / print and repeat itself

    for (int i = 0; i < num; ++i)
        {
            file<<std::string(num-1-i,' ');//this line is printing the left side white space
            
            if(i==num-1){file<<std::string(num*2-1,'*')<<std::endl;}
            else if(i==0){file<<'*'<<std::endl;}
            else{
                file<<'*';
                for (int j = 0; j < i*2-1; ++j)
                {
                if (o == size){o=0;}
                file<<patt[o];
                ++o;
                }
                file<<'*'<<std::endl;
            }
            
        }
}



int main(int argc, char* argv[]){//the main function is to take in command
// typed in the terminal and create a file and creat an output

    std::ofstream file; 


    if( argc != 5){
        std::cerr<<"Missing argument"<<std::endl;//this part is checking if correct number command argunment are putting into the terminal
        exit(1);

    }

    std::string f = argv[4];
    file.open(f);



    if(!file.is_open()){
        std::cerr<<"Can not open the file"<<std::endl;//this part is check if the file can be open
        exit(1);
    }


    //this part is reading the command and store what we need to use later
    std::string patt=argv[1];//this is the pattern of letters repeating in side the picture

    std::string str_num = argv[2];//this is the height of that picture

    std::string shape = argv[3];//this is the shape you chose 
    
    std::string out;
    int size = patt.size();
    
    int num = atoi(str_num.c_str());//change the string into int
    
    

    if(num < 1 ){
        std::cerr<<"The number is too small"<<std::endl;
        exit(1);
    }

        

    if (shape=="square")// to print out square shape 
    {
    square( patt,  num, file,size );	
    }

    else if (shape=="right_triangle")//print out right triangle shape
    {
    right_triangle( patt,  num, file,size );
    }
    

    else if (shape=="isosceles_triangle")//print out isosceles trangles
    {
    isosceles_triangle( patt,  num, file,size);	
    }

    else{
        std::cerr<<"Don't have such shape"<<std::endl;
        exit(1);
    }

}









