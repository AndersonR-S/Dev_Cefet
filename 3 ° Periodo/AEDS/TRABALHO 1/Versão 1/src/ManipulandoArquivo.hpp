#ifndef MANIPULANDOARQUIVO_HPP
#define MANIPULANDOARQUIVO_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ManipulandoArquivo{
    private:
        string input_arquivo;
        string output_arquivo;
        int tamanho;

    public:
        ManipulandoArquivo();

        int getTamanho() const;
        void setTamanho(int tamanho = 5);

        void setInputArquivo(string input_arquivo);
        void setOutputArquivo(string output_arquivo);

        int **Input();
        void Output(int **tabuleiro);

         int **criarTabuleiro();
};

#endif