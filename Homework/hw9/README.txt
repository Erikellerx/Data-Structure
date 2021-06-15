HOMEWORK 9: IMDB SEARCH


NAME:  < Eric Li >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Even shi, C++.com, lab code, lecture note  >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 30 >


HASH FUNCTION DESCRIPTION
I used the the hash function from lab11(If I remember correctlly)
basically, it is a string hash function takes into account each char
and its position. And then the % by the size of hash table so 
the index is within the range. 



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)
For hash table representation, I used vector<pair<string,list<int>>>
where string is my query of all query combined and int is the index pointing
to the the base data vector<Movie> where the actural movie is stored. 

I avoid to use pointer in this hw becasue the pointer pointing to the content
in vector might cause memory lose, in which vector will resize and reallocate itself
and in this case, the pointer I stored inside the hash table will be invalid. 


