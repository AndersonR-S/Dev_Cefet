#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>

using namespace std;

class Tabuleiro{
    private:
        short tamanho;
        vector<short> *tabuleiro;
    
    public:
        Tabuleiro(short tamanho);

        void print();
        void setTabuleiro(vector<short> tabuleiro);

        vector<short> getTabuleiro() const;
        short getTamanho() const;

        ~Tabuleiro();
    
        
};

#endif