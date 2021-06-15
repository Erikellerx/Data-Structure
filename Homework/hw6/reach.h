





//this class is just for record the reachibility table (visualize)
class Reachability{
  public:
    int rows;
    int cols;
    int ** table = nullptr;
    Reachability(int r, int c);
    bool all_reachable() const;
    

};