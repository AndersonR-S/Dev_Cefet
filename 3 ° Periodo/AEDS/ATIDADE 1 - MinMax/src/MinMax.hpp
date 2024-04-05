#ifndef MINMAX_HPP
#include MINIMAX_HPP

#include <vector>
using namespace std; 

class MinMax{
private:
    vector <int> min_max;
    int size;

public:
    MinMax();
    MinMax(int size);

    void run(int repeat = 10);
    void generate();

    void setSize(int size);

   //vector<int> getMinMax1()const;
   // vector<int> getMinMax2()const;
   // vector<int> getMinMax3()const;

    ~MinMax();
};

#endif