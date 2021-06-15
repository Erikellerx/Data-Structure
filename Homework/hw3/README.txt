HOMEWORK 3: CONNECT FOUR


NAME:  <Eric Li>


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Even shi, Jason, alac. c++.com >

Remember: Your implementation for this assignment must be done on your
own, as described in the "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 66 >



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

insert (excluding checking for connected four)
O(N*M)
insert (including checking for connected four)
O(N*M)
numTokensInColum
O(1)
numTokensInRow
O(n)
numColumns
O(1)
numRows
O(1)
print
O(N*M)
clear
O(N)

TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?
I used gdb and drmemory to debug. 
And for testing, i just add a lot of insert to wherever I want to test if there is any errors. 
Also, I checked clear function and assignment operator to see if there is any memory buy. Basically, I checked 
empty copy and if there is any aliaing that shouldn't be happening . 


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)
