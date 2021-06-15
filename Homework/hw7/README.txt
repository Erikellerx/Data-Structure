HOMEWORK 7: SUPER SMASH BROS. FRAMES


NAME:  < Eric Li >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Even shi, Amy >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  <6 hours >



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity for both running
time AND space along with a short justification for each of the queries below.
For the commands, do not count the space occupied by the database in the space
complexity analysis.

f: The total number of fighters
m: The number of different moves
t: The highest number of moves that have the same starting frame

reading the database/populating your initial data structure:
running time: O(fm*logm) since we need to loop though all the data including fighters and moves, which is fm, then we do 
			 the insertion which is logm.
space complexity: O(fm) since we need to create a map with all the fighters corresponding with each one's moves respectively

-q (specific move):
running time: O(logf+logm). since we need to find that specific fighter then find its specific move
space complexity: O(1): since there is no new data container created;

-q (all): running time: 
running time: O(logf+m) since we need to find that specific fighter and then go through all the moves
space complexity: o(1): there is no new container created

-f:
running time: O(m+f*logm+f*logf) since first we need to loop through all the move to find if it's a valid move
	                         then loop through all the fighters and insert into a new set. then loop through
				 all the fighters in the new set and find its specific move
space complexity: O(f) since we create a new set containing all the fighters

-s:
running time: O(m+f*logm+f*logf)
space complexity O(f)
well... I besically use the same function and to create a new set as -f command, so the running time and space complexity is 
same. The only difference between those two command is print one in order and in reverse order. So theorically the running time
and space complexity is exactly the same (the overloading on < operator is different but shouldn't cause a difference on running time
and space complexity

-d:
running time:O(m+f*logm) first we need to check if that is a valid move, then loop through all fighters with each fighter searching
for the specifed move. 
space complexity O(m) we created a new map containing f fighters

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)






