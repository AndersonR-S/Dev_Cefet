#include "Aluno.hpp"

Aluno::Aluno() {}

Aluno::Aluno(int matricla, string nome, string endereco) : Pessoa(nome, endereco)
{
    this->matricula = matricla;
}

void Aluno::print()
{
    Pessoa::print();
    cout << "Matricula: " << this->matricula << endl;
}