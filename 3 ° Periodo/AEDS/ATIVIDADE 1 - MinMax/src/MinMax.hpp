#ifndef MINMAX_HPP
#define MINMAX_HPP

#include "File.hpp"
#include <vector>
using namespace std; 

class MinMax{
private:
    vector <int> min_max;
    int size;

    long MinMax1();
    long MinMax2();
    long MinMax3();

    void growingMinMax();
    void decreasingMinMax();

public:
    MinMax();
    MinMax(int size);

    void run(File *file, int repeat = 10);
    void generate();
    void setSize(int size);

};

#endif