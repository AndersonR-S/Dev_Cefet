    #include "File.hpp"
    #include <iostream>
    #include <fstream>
    #include <string>
    
    File::File()
    {
        fstream file;

        file = open( output_ordered , ios::in);
        if(!file)
        {
            exit(0);
        }
        file.close();

        file = open( output_growing , ios::in);
        if(!file)
        {
            exit(0);
        }
        file.close();
            
        file = open( output_decreasing , ios::in);
        if(!file)
        {
            exit(0);
        }
        file.close();
    }

    void File::FileOrdered(int size, int mm1, int mm2, int mm3)
    {
        return;
    }
    void File::FileDecreasing(int size, int mm1, int mm2, int mm3)
    {
        return;
    }
    void File::FileGrowing(int size, int mm1, int mm2, int mm3)
    {
        return;
    }
