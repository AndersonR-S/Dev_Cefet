#include "MinMax.hpp"
#include <iostream>

MinMax::MinMax(int size):size(size){}

int *MinMax1()
{
    int max , min;
    max = min = MinMax1[0];

    for(int i = 1; i< size; i++)
    {
        if(max < MinMax1[i])
        {
            max = MinMax1[i];
        }

        if(min > MinMax[i])
        {
            min =  MinMax1[i];
        }
    }

    return [min, max];
}

int *MinMax2()
{
    int max, min;
    max = min = MinMax1[0];

    for(int i = 1; i< size; i++)
    {
        if(max < MinMax2[i])
        {
            max = MinMax2[i];
        }
        else if( min > MinMax2[i])
        {
            min = MinMax[i];
        }
    }

    return [min, max];
}

int *MinMax3()
{
    int max, min;

    if((size % 2) != 0)
    {
        MinMax3.push_back(MinMax3[0]);
    }

    if(MinMax3[0] > MinMax3[1])
    {
        max = MinMax3[0];
        min = MinMax3[1];
    }
    else 
    {
        max = MinMax3[1];
        min = MinMax3[0];
    }




    return [min, max];
}




MinMax::~MinMax()
{
    delete MinMax1;
    delete MinMax2;
    delete MinMax3;
}

