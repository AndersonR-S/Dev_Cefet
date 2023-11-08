#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>

using namespace std;

class Pessoa{
private:
    string nome;
    string cpf;

public:
    Pessoa(string nome, string cpf);
    Pessoa();

    void _print();
};
#endif
