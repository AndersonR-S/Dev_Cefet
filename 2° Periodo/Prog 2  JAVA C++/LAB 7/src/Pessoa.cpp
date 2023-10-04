#include "Pessoa.hpp"

Pessoa::Pessoa() {}

Pessoa::Pessoa(string nome, string endereco)
{
    this->nome = nome;
    this->endereco = endereco;
}

void Pessoa::print()
{
    cout << "Nome: " << this->nome << endl;
    cout << "Endereço: " << this->endereco << endl;
}