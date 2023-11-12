#include "Pessoa.hpp"

Pessoa::Pessoa(){}
Pessoa::Pessoa(string nome, int idade):nome(nome), idade(idade){}

void Pessoa::_print(){
    cout<<"Nome: "<<nome<<"\tIdade: "<<idade<<endl;
}
