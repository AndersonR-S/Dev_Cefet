#ifndef JOGO_HPP
#define JOGO_HPP

#include "arquivo.hpp"

class Jogo{
    private:
    Arquivo *arquivo;
    public:
        Jogo();
        void iniciarJogo();
        ~Jogo();
};

#endif