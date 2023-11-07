#ifndef NO_HPP
#define NO_HPP

#include "ClienteBanco.hpp"
#include <iostream>

class No{
private: 
    ClienteBanco *dado;
    bool prioridade;
    No *proximo;

public:
No();
No(ClienteBanco *dado, bool prioridade);

void _setDado(ClienteBanco *dado);
ClienteBanco* _getDado();

void _setProximo(No *dado);
No *_getProximo();

};
#endif
