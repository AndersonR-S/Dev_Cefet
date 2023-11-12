#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Pessoa.hpp"

class Aluno: public Pessoa{
private:
    string curso;
    int numeroMatricula;

public:
    Aluno();
    Aluno(string nome, int idade, string curso, int numeroMatricula);

    void print();

};

#endif