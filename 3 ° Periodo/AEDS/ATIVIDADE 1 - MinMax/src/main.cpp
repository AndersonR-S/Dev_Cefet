#include "MinMax.hpp"


int main()
{
    File *file = new File();
    MinMax *mm = new MinMax();

    int sizes[] = {1000, 10000, 100000, 500000};

    for(auto i: sizes)
    {
        mm->setSize(i);
        mm->generate();
        mm->run(file);
    }

    delete file;
    delete mm;

}