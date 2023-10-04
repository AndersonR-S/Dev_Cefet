#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "Pessoa.hpp"

class Professor : public Pessoa
{
private:
    string titulacao;
    string curso;
    int MASP;

public:
    Professor();
    Professor(string titulado, string curso, string nome, string esdereco, int MASP);
    int getMasp();
    void print();
    bool vazio();
};

#endif