HOMEWORK 6: RICOCHET ROBOTS RECURSION


NAME:  < Eric Li >



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Even shi, Jason, C++.com ,https://www.cnblogs.com/whywhy/p/4888632.html,https://www.cnblogs.com/kungfupanda/p/11248014.html>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  -1 hours



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

i & j = dimensions of the board
    r = number of robots on the board
    g = number of goals
    w = number of interior walls
    m = maximum total number of moves allowed
    s = number of unique board state

I used BFS to search for all the possible number shortest moves, which is a non recursive function. 
The function will loop through all the possible moves from 0 to whenever 
there isn't any unique state or if the goal is reached depending on 
the command we input. And depending on that result,
if the command required us to find its' path, I load that max moves into my recursive 
function which is a DFS algorithm. Basically I search for all
paths given the max move and check if the goal is satisfied. When it reached the goal.
In general, if we see all the possible outcome as a tree. The BFS algorithm is searching them
horizonally with 1 moves to many. The DFS, on the other hand, search the tree vertically as it keeping 
searching down until there is a valid path(reach the goal), then return back to the last call of recursive 
function and keep finding next valid solutions. 




create_reach_table: O(4srw(ijr+s)) = visualize command BFS algorithm

max move not specified: O(4srw(g+s)) 

-all_solutions: O(4srw(g+s)+2(m^(4r)wg) = included recursion part

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
Correctness & approximate wall clock running time for various command
line arguments.


time ./a.out puzzle1.txt -all_solutions > output.txt

real    0m0.076s
user    0m0.063s
sys     0m0.016s
time ./a.out puzzle1.txt -visualize A > output.txt

real    0m0.863s
user    0m0.859s
sys     0m0.000s

time ./a.out puzzle7.txt -all_solutions > output.txt

real    0m0.620s
user    0m0.594s
sys     0m0.000s

time ./a.out puzzle8.txt -all_solutions > output.txt

real    1m4.870s
user    1m4.828s
sys     0m0.047s

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


