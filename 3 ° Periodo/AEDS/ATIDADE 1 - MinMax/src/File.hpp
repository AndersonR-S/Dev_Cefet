#ifndef FILE_HPP
#define FILE_HPP

#define output_ordered "datagets/ordenado.csv"
#define output_growing "datagets/crescente.csv"
#define output_decreasing "datagets/ordenado.csv"

using namespace std;


class File{
private:

public:
    File();
    void FileOrdered(int size, int mm1, int mm2, int mm3);
    void FileDecreasing(int size, int mm1, int mm2, int mm3);
    void FileGrowing(int size, int mm1, int mm2, int mm3);

};

#endif