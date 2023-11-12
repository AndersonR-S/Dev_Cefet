/*A PilhaProvas deve oferecer funcionalidades através de um menu interativo
para: a. Empilhar provas (push), mostrando os dados da prova e o número de
provas na pilha. b. Desempilhar provas (pop), informando os detalhes da prova
retirada e as que ainda estão na pilha. c. Visualizar a prova no topo (top). d.
Verificar se a pilha de provas está vazia (isEmpty).*/
#ifndef PILHAPROVAS_HPP
#define PILHAPROVAS_HPP
#include "Prova.hpp"

class No{
private:
    Prova *prova;
    No *proximo;
public:
    No(){}
    No(Prova *prova):prova(prova), proximo(nullptr){}

    Prova *getProva(){
        return prova;
    }

    No* getProximo(){
        return proximo;
    }

    void setProximo(No *proximo){
        this->proximo = proximo;
    }
};

class PilhaProvas{
private:
    No *Inicio;
    No *Final;
    int quantidade;
public:
    PilhaProvas();
    PilhaProvas(No *no);

    void push(Prova *prova);
    void pop();
    void top();
    bool isEmpty();

};
#endif