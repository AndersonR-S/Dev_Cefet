#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>

using namespace std;
class Pessoa
{

private:
    string nome;
    char sexo;
    string endereco;
    int cpf;
    string telefone;
    string identidade;

public:
    Pessoa();
    Pessoa(string nome,
           char sexo,
           string endereco,
           int cpf,
           string telefone,
           string identidade);

    string getNome();
    char getSexo();
    string getEndereco();
    int getCpf();
    string getTelefone();
    string getIdentidade();

    void setNome(string novoNome);
    void setSexo(char novoSexo);
    void setEndereco(string novoEndereco);
    void setCpf(int novoCpf);
    void setTelefone(string novoTelefone);
    void setIdentidade(string novaIdentidade);

    void imprimir();
};

#endif
