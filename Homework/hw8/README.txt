HOMEWORK 8: ROPES


NAME:  < Eric Li >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Even shi, Amy zeng>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 24 >

BALANCED/WORST CASE RUNNIG TIME ANALYSIS:
n = characters in the string of the current Rope (*this)
m = characters in the string of the Rope passed in (for functions that take
    a second rope)
v = longest "value" of a leaf
p = longest path from root to a leaf
N = the number of all nodes
Using these variables, state and explain the big-O running time of each 
of the following operations two ways: 1) with a balanced Rope, 2) with an 
extremely unbalanced Rope. Explain what you considered an extremely 
unbalanced rope for the string "Hello my name is Simon".

So the extremely unbalanced rope will be all nodes only have left subs or right subs

Copy Constructor:
balance:O(N)
unbalance:O(N)
since we need to go through all the nodes in the class

Construct from Node*:
balance: O(p) since we need to go down from root to leaf(only go right) to add up all weights
unbalance:O(p) if there are only left sub, the order will be O(1), if there are only right sub, 
it will be O(p), so the average will be O(p)

Index:
balance:O(p) 
unbalance:O(p)
since both balance and unbalance is required to loop from root to bottom leaf

Report:
balance:O(p+N)
unbalance:O(N)
for balanced tree, we need to loop from root to leaf which is p, then we useing iterator to 
find the next node to add up which is about N
for unbalanced tree, since the use of iterator is O(1) , so the running time will be O(N)

iterator operator++:
balance:O(1) even though the worse case will be O(p), but we are not always going back to root
when we call ++, and the best case will be O(1),so I assume the average will be O(1)
unbalance:O(1), for unbalanced tree, the next node will always be the one next to it, so O(1)

Split:
balance:O(p)
unbalance:O(p)
since we need to search from root to the bottom, so it will be O(p)

Concat:
balance:O(n)
unbalance:O(n)
the part for copying is O(n) and the rest of it is O(1), so no matter if it is balance or
unbalance, it will be O(n)



TESTING & DEBUGGING STRATEGY: 
Briefly describe the tests in your StudentTests() function.
How did you test the "corner cases" of your implementation?

So I mainly test report, split, and index with many different indexs so I could make sure they will work fine. 
Also the split will be many different ways to cut(3), so I test them where I can think of. 


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

