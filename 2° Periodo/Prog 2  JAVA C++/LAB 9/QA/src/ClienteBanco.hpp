#ifndef CLIENTEBANCO_HPP
#define CLIENTEBANCO_HPP
#include "Pessoa.hpp"

class ClienteBanco: public Pessoa{
private:
    string Agencia;
    string NumeroDaConta;
public:

    ClienteBanco();
    ClienteBanco(string nome, string cpf, string agencia, string conta);

    void print();

};

#endif