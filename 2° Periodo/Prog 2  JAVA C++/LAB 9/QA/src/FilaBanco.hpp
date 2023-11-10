#ifndef FILABANCO_HPP
#define FILABANCO_HPP

#include "ClienteBanco.hpp"
#include "No.hpp"
class FilaBanco{
private:
    No *Fila;
    No *cauda;
    int quantidade;

public:
    FilaBanco();
    void enqueue(ClienteBanco *dado);
    void enqueuePriority(ClienteBanco *dado);
    void dequeue();
    void printQueue();
    bool isEmpty();

};
#endif