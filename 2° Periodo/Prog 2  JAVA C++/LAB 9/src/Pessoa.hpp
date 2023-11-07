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
    Pessoa(sring nome, string cpf);
    Pessoa();

    void _print();
};
#endif

Pessoa::Pessoa(string nome, string cpf):nome(nome),cpf(cpf){}
Pessoa::Pessoa(){}

void Pessoa::_print(){
    cout<<"Nome: "+nome;
    cout<<"Cpf: "+cpf;
}