#include "ClienteBanco.hpp"

ClienteBanco::ClienteBanco(){}
ClienteBanco::ClienteBanco(string nome, string cpf, string agencia, string conta):Pessoa(nome, cpf), Agencia(agencia), NumeroDaConta(conta){}

void ClienteBanco::_print(){
    Pessoa::_print();
    cout<<"Agencia: "+Agencia;
    cout<<"Conta: "+ NumeroDaConta;
}