#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "tabuleiro.hpp"
#include <string>

class Arquivo{
    private:
        string nome_input;
        string nome_output;
        Tabuleiro *novo_tabuleiro;
    public:
        Arquivo(string nome_input, string nome_output);

        void input();

        void output();

        Tabuleiro *getNovoTabuleiro()const;

        void setTabuleiro(vector<short> tabuleiro);

        ~Arquivo();
};

#endif