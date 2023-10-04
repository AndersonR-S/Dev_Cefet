#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
#include <iostream>

using namespace std;

class Pessoa
{
private:
    string nome;
    string endereco;

public:
    Pessoa();
    Pessoa(string nome, string endereco);
    void print();
};



#endif