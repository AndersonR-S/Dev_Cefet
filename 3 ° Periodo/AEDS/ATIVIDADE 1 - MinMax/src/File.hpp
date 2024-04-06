#ifndef FILE_HPP
#define FILE_HPP

#include <string>
using namespace std;

class File{
private:
    const string output_ordered = "datagets/ordered.csv";
    const string output_growing = "datagets/growing.csv";
    const string output_decreasing = "datagets/decreasing.csv";


public:
    File();
    void FileOrdered(int size, int mm1, int mm2, int mm3);
    void FileDecreasing(int size, int mm1, int mm2, int mm3);
    void FileGrowing(int size, int mm1, int mm2, int mm3);

};

#endif