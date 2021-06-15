
#include "reach.h"



Reachability::Reachability(int r, int c){
    rows = r;
    cols = c;
    table = new int *[r];
    for (int i = 0; i < r; i++)
    {
      table[i] = new int[c];
      for (int j = 0; j < c; j++)
      {
        table[i][j] = -1; // means not reachable
      }        
    }      
  }
bool Reachability::all_reachable() const{
    for (int i = 0; i < rows; i++)
    {
      
      for (int j = 0; j < cols; j++)
      {
        if(table[i][j] == -1) return false ; // means not reachable
      }        
    }    
    return true;
  }

