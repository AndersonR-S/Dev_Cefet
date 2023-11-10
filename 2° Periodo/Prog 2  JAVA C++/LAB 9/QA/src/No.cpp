#include "No.hpp"


No::No(){
    this->dado = nullptr;
    this->proximo = nullptr;
    
}

No::No(ClienteBanco* _dado, bool _prioridade){
    this->dado = _dado;
    this->prioridade = _prioridade;
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