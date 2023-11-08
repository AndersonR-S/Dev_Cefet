#include "ClienteBanco.hpp"


ClienteBanco::ClienteBanco(){}
ClienteBanco::ClienteBanco(string _nome, string _cpf, string _agencia, string _conta):Pessoa(_nome, _cpf), Agencia(_agencia), NumeroDaConta(_conta){}

void ClienteBanco::print(){
    Pessoa::_print();
    cout<<"Agencia: "<<Agencia;
    cout<<"\tConta: "<<NumeroDaConta;
}