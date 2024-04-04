#ifndef MINMAX_HPP
#include MINIMAX_HPP

#include <vector>
using namespace std; 

class MinMax{
private:
    vector <int> MinMax1;
    vector <int> MinMax2;
    vector <int> MinMax3;
    int size;

public:
    MinMax(int size);

    void run();

    vector<int> getMinMax1()const;
    vector<int> getMinMax2()const;
    vector<int> getMinMax3()const;

    ~MinMax();
};

#endif