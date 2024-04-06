    #include "File.hpp"
    #include <iostream>
    #include <fstream>
    #include <string>

    File::File()
    {
        fstream file1, file2, file3;

        file1.open(output_ordered, ios:: out);
        if(!file1)
        {
            cerr<<"Erro ao abrir o arquivo ordenado.csv"<<endl;
            exit(1);
        }

        file1<<"size"<<","<<"mm1"<<","<<"mm2"<<","<<"mm3"<<endl;

        file1.close();
    
        file2.open(output_growing,ios:: out);
        if(!file2)
        {
            cerr<<"Erro ao abrir o arquivo crescente.csv"<<endl;
            exit(1);
        }

        file2<<"size"<<","<<"mm1"<<","<<"mm2"<<","<<"mm3"<<endl;

        file2.close();

        file3.open(output_decreasing,ios:: out);
        if(!file3)
        {
            cerr<<"Erro ao abrir o arquivo crescente.csv"<<endl;
            exit(1);
        }

        file3<<"size"<<","<<"mm1"<<","<<"mm2"<<","<<"mm3"<<endl;

        file3.close();
    }


    void File::FileOrdered(int size, int mm1, int mm2, int mm3)
    {
        fstream file(output_ordered, ios::app);
        if(!file)
        {
            cerr<<"Erro ao acessar o arquivo ordenado.csv"<<endl;
            exit(1);
        }

        file << size <<","<<mm1<<","<<mm2<<","<<mm3<<endl;

        file.close();  
    }

    void File::FileDecreasing(int size, int mm1, int mm2, int mm3)
    {
        fstream file(output_decreasing, ios::app);
        if(!file)
        {
            cerr<<"Erro ao acessar o arquivo decrescente.csv"<<endl;
            exit(1);
        }

        file << size <<","<<mm1<<","<<mm2<<","<<mm3<<endl;

        file.close();  
    
    }
    void File::FileGrowing(int size, int mm1, int mm2, int mm3)
    {
        fstream file(output_growing, ios::app);
        if(!file)
        {
            cerr<<"Erro ao acessar o arquivo crescente.cvs"<<endl;
            exit(1);
        }

        file << size <<","<<mm1<<","<<mm2<<","<<mm3<<endl;

        file.close();  
    }
