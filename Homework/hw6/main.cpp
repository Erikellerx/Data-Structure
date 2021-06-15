#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include "board.h"
#include "reach.h"
#include <sstream>



// ==================================================================================
// ==================================================================================

//this function help to find if that robot position as already exist in all state 
bool findInPath(const std::vector<Position>& ret, const std::vector<std::vector<Position>>& path){
  for (unsigned int i = 0; i < path.size(); i++)
  {
    bool find = true;
     for (unsigned int j = 0; j < ret.size(); j++)
     {
       if (ret[j] != path[i][j]) {
         find = false;
         break;
       }
     }
     if (find) return true;
  }

  return false;
  
}

//this function helps to find if the reachability table are all full -> all filled w/ numbers
//used on visualize 
bool all_full(const std::vector<Reachability>& rt){
  for (unsigned int i = 0; i < rt.size(); i++)
  {
     if(!rt[i].all_reachable()) return false;
  }
  return true;
  
}

// ==================================================================================
// ==================================================================================
//4 different directions just for convienence.
std::vector<const char *> directs= {"E", "S", "N", "W"};
//this function generate reachibility table (visualize command) and return the min moves within that specificed goal
//though I admit this is a non-recursive function, but I did have a recursive function on visualization in which doesn't work properly when the max_move doesn't set up
//and I tried to convert this version into recursion function but seg fault and other error occurs and I don't know how to solve those before due day :(
//however, I did use a recursive function later on to find the path(one solution and all solutions) so still I guess I maybe prove I can use non-trivial recursion 
//on solving this hw?
int create_reach_table(Board &b, 
    std::vector<Reachability> &rtable,  // recored the reachable table
     int max_moves,char visualize){
    std::list<std::pair<std::vector<Position>, int> > state;//record the current state waiting  to be solve
    std::vector<std::vector<Position>> all_state;//record all the state possible calculated
    int depth = -1;//min moves on solving goal
    state.push_back({b.getRobotPositions(), 0});
    while (!state.empty())//if there is no current state, stop the loop which means there is no solutions on this puzzle
    {
      
      //get one state first and then pop it and find the possible outcomes after that state
      std::pair<std::vector<Position>, int> top = state.front();
      state.pop_front();
      int moves = top.second;
      b.restorePositions(top.first);
      if (max_moves > 0 && moves >= max_moves) break;
      //if that state has already exist , do next one
      if (findInPath(top.first, all_state)){
        continue;
      }
      all_state.push_back(top.first);//record the situation to all state
      for (unsigned int i = 0; i < b.numRobots(); i++)
      {
        Position beforeMove = b.getRobotPosition(i);
        for (int j = 0; j < 4; j++)
        {
          std::string dirct(directs[j]);          
          if(b.moveRobot(i, dirct)){
            //record current position
            Position now = b.getRobotPosition(i);
            //record into reachibility table if thry are smaller than what I already have
            if (rtable[i].table[now.row-1][now.col-1] == -1
              || rtable[i].table[now.row-1][now.col-1] > moves + 1){
                rtable[i].table[now.row-1][now.col-1] = moves + 1;
              }
            //if I satisfied the goal, then stop the loop (tested may save some running time)
            if (b.allGoalHold() && depth == -1 && visualize == ' ' )   {
              depth = moves + 1;
              return depth;
            } 
            //if all the elements in reach table are full and valid, then stop it (only used on visualize command )
            if (all_full(rtable)&&visualize != ' '){
              b.cancelMove(i, beforeMove);
              
              return depth;
            } 
            //record the position of next move, and if they are not existed before, record it
            std::vector<Position> ret = b.getRobotPositions();
            if (!findInPath(ret, all_state))
              state.push_back({ret, moves + 1}); 
           
            b.cancelMove(i, beforeMove); //restore the robot position to previous move      
          }
         
        } 
    }
  }

  return depth;
}

//this function print the one solution and its entire path and board if needed. 
void solRep(Board &b, std::vector<std::vector<Position>>& path, bool showgrid = true){
    
    unsigned int n = path.size();
    unsigned int k = 0;
    
    while (k + 1 < n)
    {
      //since I only record a vector of all robots' position
      //I only need to compare each vector's difference on position so I can know which
      //direction that robot goes
      std::vector<Position> temp = path[k];
      
      b.restorePositions(temp);
      if (showgrid){
        b.print();}      
      
        std::vector<Position> temp2 = path[k+1];

        for (unsigned int i = 0; i < temp.size(); i++)
        {
          //print one solution 
          if (temp[i] != temp2[i]){
            char c = b.getRobot(i);
            std::string dirct = "";
            if (temp[i].row > temp2[i].row){
              dirct = "north";
            }
            if (temp[i].row < temp2[i].row){
              dirct = "south";
            }
            if (temp[i].col > temp2[i].col){
              dirct = "west";
            }
            if (temp[i].col < temp2[i].col){
              dirct = "east";
            }
            std::cout << "robot " << c << " moves " << dirct << std::endl;
            break;
          }
        }      
      
      k++;
    }
    std::vector<Position> temp = path[n-1];
    b.restorePositions(temp);
    if (showgrid) b.print(); 
    std::cout << "All goals are satisfied after "<< path.size()-1 << " moves\n" << std::endl;
      
    
    
}


//this function is a recursive function which it recursive every move(depth) to find a valid given max move created by create_reach_table
//return true if it is a valid path otherwise false
bool search_for_path(Board &b, 
    // recored the reachable table
    std::vector<std::vector<Position>> & comepath, 
    int moves, int &max_moves , bool all_solutions, bool output, int & numSols) // Postion state have visited
{
  //if the moves exceed max more , just return false
  if (max_moves > 0 && moves + 1 > max_moves) return false;
  //all reobots
  for (unsigned int i = 0; i < b.numRobots(); i++)
  {
      //record the position
      Position beforeMove = b.getRobotPosition(i);
      // 4 directions
      for (int j = 0; j < 4; j++)
      {
        std::string dirct(directs[j]);
        bool finished = false;
        if(b.moveRobot(i, dirct)){
          std::vector<Position> ret = b.getRobotPositions();
          //check if we reach the goal, if it does, print the solution path and return back to last position
          if (b.allGoalHold()){
            numSols += 1;//record how many solutions we have 
            comepath.push_back(ret);
            if (!all_solutions)
              solRep(b, comepath, true);
            else if (output){
              solRep(b, comepath, false);
            }
            finished = true;            
            comepath.pop_back();//pop back the last position and keep finding
            if (finished && !all_solutions){ // only find the first solution
              return finished;
            }  
          }
          
          //if that path hasn't exited before push this path into comepath and keep searching (recursion!)
          if (!findInPath(ret, comepath))
          {
            comepath.push_back(ret);//record the path
            finished = search_for_path(b,  comepath, moves + 1, max_moves, 
            all_solutions, output, numSols);
            comepath.pop_back();//pop back the position last 
          }     
          b.cancelMove(i, beforeMove); 
          if (finished && !all_solutions){ // only find the first solution
            return finished;
          }  
        }
        
      }
      
  }
  return false;
  
}



// ==================================================================================
// ==================================================================================

// This function is called if there was an error with the command line arguments
bool usage(const std::string &executable_name) {
  std::cerr << "Usage: " << executable_name << " <puzzle_file>" << std::endl;
  std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#>" << std::endl;
  std::cerr << "       " << executable_name << " <puzzle_file> -all_solutions" << std::endl;
  std::cerr << "       " << executable_name << " <puzzle_file> -visualize <which_robot>" << std::endl;
  std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#> -all_solutions" << std::endl;
  std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#> -visualize <which_robot>" << std::endl;
  exit(0);
}

// ==================================================================================
// ==================================================================================

// load a Ricochet Robots puzzle from the input file
Board load(const std::string &executable, const std::string &filename) {

  // open the file for reading
  std::ifstream istr (filename.c_str());
  if (!istr) {
    std::cerr << "ERROR: could not open " << filename << " for reading" << std::endl;
    usage(executable);
  }

  // read in the board dimensions and create an empty board
  // (all outer edges are automatically set to be walls
  int rows,cols;
  istr >> rows >> cols;
  assert (rows > 0 && cols > 0);
  Board answer(rows,cols);

  // read in the other characteristics of the puzzle board
  std::string token;
  while (istr >> token) {
    if (token == "robot") {
      char a;
      int r,c;
      istr >> a >> r >> c;
      answer.placeRobot(Position(r,c),a);
    } else if (token == "vertical_wall") {
      int i;
      double j;
      istr >> i >> j;
      answer.addVerticalWall(i,j);
    } else if (token == "horizontal_wall") {
      double i;
      int j;
      istr >> i >> j;
      answer.addHorizontalWall(i,j);
    } else if (token == "goal") {
      std::string which_robot;
      int r,c;
      istr >> which_robot >> r >> c;
      answer.addGoal(which_robot,Position(r,c));
    } else {
      std::cerr << "ERROR: unknown token in the input file " << token << std::endl;
      exit(0);
    }
  }

  // return the initialized board
  return answer;
}

// ==================================================================================
// ==================================================================================

int main(int argc, char* argv[]) {

  // There must be at least one command line argument, the input puzzle file
  if (argc < 2) {
    usage(argv[0]);
  }

  // By default, the maximum number of moves is unlimited
  int max_moves = -1;

  // By default, output one solution using the minimum number of moves
  bool all_solutions = false;

  // By default, do not visualize the reachability
  char visualize = ' ';   // the space character is not a valid robot!

  // Read in the other command line arguments
  for (int arg = 2; arg < argc; arg++) {
    if (argv[arg] == std::string("-all_solutions")) {
      // find all solutions to the puzzle that use the fewest number of moves
      all_solutions = true;
    } else if (argv[arg] == std::string("-max_moves")) {
      // the next command line arg is an integer, a cap on the  # of moves
      arg++;
      assert (arg < argc);
      max_moves = atoi(argv[arg]);
      assert (max_moves > 0);
    } else if (argv[arg] == std::string("-visualize")) {
      // As a first step towards solving the whole problem, with this
      // option, let's visualize where the specified robot can move
      // and how many steps it takes to get there
      arg++;
      assert (arg < argc);
      std::string tmp = argv[arg];
      assert (tmp.size() == 1);
      visualize = tmp[0];
      assert (isalpha(visualize) && isupper(visualize));
      visualize = toupper(visualize);
    } else {
      std::cout << "unknown command line argument" << argv[arg] << std::endl;
      usage(argv[0]);
    }
  }

  // Load the puzzle board from the input file
  Board board = load(argv[0],argv[1]);
  std::vector<Reachability> rtable;//record all the reachbiliey table each by robots
  std::vector<std::vector<Position>> comepath;//record the path 
  comepath.push_back(board.getRobotPositions());//push back the initial position
  //push all the reach table by the number of robots
  for (unsigned int i = 0; i < board.numRobots(); i++)
  {
      rtable.push_back(Reachability(board.getRows(), board.getCols()));
      rtable[i].table[board.getRobotPosition(i).row - 1][board.getRobotPosition(i).col - 1] = 0;
  }
  
  //get the initial state of board in order for us to initialize back to origional state if needed
  std::vector<Position> init = board.getRobotPositions();

  //find the max move no matter if the max move is given and generate visualzie table
  int minDepth = create_reach_table(board, rtable, max_moves, visualize);

  //print the reachibility table 
  for (unsigned int i = 0; i < board.numRobots(); i++)  {
      if (visualize == board.getRobot(i)){
        std::cout << "Reachable by robot " << visualize << ":" << std::endl;
        for (int k = 0; k < board.getRows(); k++)
        {
          for (int l = 0; l < board.getCols(); l++)
          {
            if (rtable[i].table[k][l] != -1)
              std::cout<<std::setw(3) << (rtable[i].table[k][l]);
            else std::cout<<std::setw(3) <<  "."; 
          }
          std::cout << std::endl;
        }
        return 0;       
      }
  }
  //resore the board into initial position
  board.restorePositions(init);
  //if mindepth == -1 that means there is no solution to reach goal
  if (minDepth == -1){    
    board.print();
    if (max_moves > 0)
      std::cout <<  "no solutions with " << max_moves << " or fewer moves\n";
    else{
      std::cout <<  "no solutions\n";
    }
  }
  else{
    int num = 0;
    //i know this is a little bit dumb....
    //i have to recurse once so I could know how many solutions I have got
    //then print all the solutions respectively 
    search_for_path(board, comepath, 0, minDepth, all_solutions, false, num);
    if (all_solutions){ 
      board.restorePositions(init);
      board.print();  
      std::cout << num << " different "<< minDepth << " move solutions:\n\n";
      num = 0; 
      
      search_for_path(board, comepath, 0, minDepth, all_solutions, true, num);
    }
  }
}

// ================================================================
// ================================================================
