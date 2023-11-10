#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, string cpf):nome(nome),cpf(cpf){}
Pessoa::Pessoa(){}

void Pessoa::_print() {
    cout << "Nome: " << nome << endl; 
    cout << "CPF: " << cpf << endl;  
}