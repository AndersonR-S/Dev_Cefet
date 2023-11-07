#include "No.hpp"


No::No(){}

No::No(ClienteBanco* dado, bool prioridade){
    this->dado = dado;
    this->prioridade = prioridade;
    this->proximo = nullptr;

    }

void No::_setDado(ClienteBanco* dado){
    this->dado = dado;
}
ClienteBanco* No::_getDado(){
    return this->dado;
}

void No::_setProximo(No *dado){
    this->proximo = dado;
}

No* No::_getProximo(){
    return this->proximo;
}