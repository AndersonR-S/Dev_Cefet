#include "Professor.hpp"

Professor::Professor() {
    this->MASP = -1;
}

Professor::Professor(string titulado, string curso, string nome, string endereco, int MASP) : Pessoa(nome, endereco)
{
    this->titulacao = titulado;
    this->curso = curso;
    this->MASP = MASP;
}

int Professor::getMasp()
{
    return this->MASP;
}

void Professor::print()
{
    Pessoa::print();
    cout << "Titulação: " << this->titulacao << endl;
    cout << "Curso: " << this->curso << endl;
    cout << "MASP: " << this->MASP << endl;
}
