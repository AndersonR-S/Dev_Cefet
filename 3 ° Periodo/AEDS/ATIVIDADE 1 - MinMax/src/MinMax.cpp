#include "MinMax.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

MinMax::MinMax(int size) : min_max(size), size(size) {}

MinMax::MinMax():min_max(),size(0){}

long MinMax::MinMax1( )
{
    int max , min;

    auto t1 = chrono::steady_clock::now();

    max = min = min_max[0];
    for(int i = 1; i< size; i++)
    {
        if(max < min_max[i])
        {
            max = min_max[i];
        }

        if(min > min_max[i])
        {
            min = min_max[i];
        }
    }
    auto t2 = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
}

long MinMax::MinMax2() 
{
    int max, min;
    auto t1 = chrono::steady_clock::now();

    max = min = min_max[0];

    for(int i = 1; i< size; i++)
    {
        if(max < min_max[i])
        {
            max = min_max[i];
        }
        else if( min > min_max[i])
        {
            min = min_max[i];
        }
    }
    auto t2 = chrono::steady_clock::now();



    return chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
}

long MinMax::MinMax3()
{
    int max, min;

    if((size % 2) != 0)
    {
        min_max.push_back(min_max[0]); 
    }

    auto t1 = chrono::steady_clock::now();

    if(min_max[0] > min_max[1])
    {
        max = min_max[0];
        min = min_max[1];
    }
    else 
    {
        max = min_max[1];
        min = min_max[0];
    }

    for(int i = 2; i <= size ; i+=2)
    {
        if(min_max[i] > min_max[i+1])
        {
            if(min_max[i] > max)
            {
                max = min_max[i];
            }
            if(min_max[i+1] < min)
            {
                min = min_max[i+1];
            }
        }
        else 
        {
            if(min_max[i+1] > max)
            {
                max = min_max[i+1];
            }
            if(min_max[i] < min)
            {
                min = min_max[i];
            }
        }
    }

    auto t2 = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
}

void MinMax::growingMinMax()
{
    sort(min_max.begin(), min_max.end());
}

void MinMax::decreasingMinMax()
{
    sort(min_max.begin(), min_max.end(), std::greater<int>());
}

void MinMax::run(File *file, int repeat)
{
    long mm1, mm2, mm3;
    //ordenado
    mm1 = mm2 = mm3 =0;
    for(int i = 0;  i < repeat; i++)
    {
        mm1 += MinMax1();
        mm2 += MinMax2();
        mm3 += MinMax3();
    }
    mm1 /= repeat;
    mm2 /= repeat;
    mm3 /= repeat;

    file->FileOrdered(size, mm1, mm2, mm3);

    //crescente
    mm1 = mm2 = mm3 =0;
    growingMinMax();
    for(int i = 0;  i < repeat; i++)
    {
        mm1 += MinMax1();
        mm2 += MinMax2();
        mm3 += MinMax3();
    }
    mm1 /= repeat;
    mm2 /= repeat;
    mm3 /= repeat;

    file->FileGrowing(size, mm1, mm2, mm3);


    //decrescente
    mm1 = mm2 = mm3 =0;
    decreasingMinMax();
    for(int i = 0;  i < repeat; i++)
    {
        mm1 += MinMax1();
        mm2 += MinMax2();
        mm3 += MinMax3();
    }
    mm1 /= repeat;
    mm2 /= repeat;
    mm3 /= repeat;

    file->FileDecreasing(size, mm1, mm2, mm3);





}

void MinMax::generate()
{
    for(int i = 0; i < size; i++)
    {
        min_max[i] = rand()%1001;
    }
}

void MinMax::setSize(int size)
{
    this->size = size;
    min_max = std::vector<int>(size);
}

