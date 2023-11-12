#ifndef PROVA_HPP
#define PROVA_HPP

#include "Aluno.hpp"

class Prova {
private:
  string Disciplina;
  string CodigoDaProva; 
  float Nota;
  Aluno *aluno;

public:
    Prova();
    Prova(string diciplina, string codigoDaProva, float Nota, Aluno *aluno);

    void print();

};

#endif
