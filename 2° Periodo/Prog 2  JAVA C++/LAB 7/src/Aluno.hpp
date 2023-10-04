#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "Pessoa.hpp"
#include <iostream>

class Aluno : public Pessoa
{
private:
    int matricula;

public:
    Aluno();
    Aluno(int matricula, string nome, string endereco);
    void print();
};

#endif