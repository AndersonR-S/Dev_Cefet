#ifndef CLIENTEBANCO_HPP
#define CLIENTEBANCO_HPP

#include "Pessoa.hpp"

class ClienteBanco: public Pessoa{
private:
    string NumeroDaConta;
    string Agencia;
public:

    ClienteBanco();
    ClienteBanco(string nome, string cpf, string agencia, string conta);

    void _print();

};

#endif