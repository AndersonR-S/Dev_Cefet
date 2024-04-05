#include "MinMax.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

long MinMax1( )
{
    int max , mim;

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

long MinMax2() 
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

long MinMax3()
{
    int max, min;

    if((size % 2) != 0)
    {
        MinMax.push_back(min_max[0]); 
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
            if(MinMax[i] < min)
            {
                min = min_max[i];
            }
        }
    }

    auto t2 = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
}

void ordenarCrescente()
{
    return;
}
void ordenarDecrescente()
{
    return;
}
//-------------------------------------------------

MinMax::MinMax(int size):size(size)
{
    min_max = new Vector <int>(size);
}

MinMax::MinMax()
{
    size = 0;
    min_max = nullptr;
}

void MinMax::run(int repeat, File file)
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


    mm1 = mm2 = mm3 =0;
    //crescente
    for(int i = 0;  i < repeat; i++)
    {
        MinMax1();
        MinMax2();
        MinMax3();
    }

    //decrescente
    for(int i = 0;  i < repeat; i++)
    {
        MinMax1();
        MinMax2();
        MinMax3();
    }





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
    ~MinMax();
    min_max = new Vector <int>(size); 
}

MinMax::~MinMax()
{
    if(min_max != nullptr)
    {
        delete min_max;
    }
}

