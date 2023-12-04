#include "Pessoa.hpp"
#include "ExcecaoSexoInvalido.hpp"
#include <iostream>

Pessoa::Pessoa() {}

Pessoa::Pessoa(string nome,char sexo, string endereco,int cpf,string telefone,string identidade){
    this->nome = nome;
    this->endereco=endereco;
    this->cpf = cpf;
    this->telefone = telefone;
    this->identidade = identidade;
    this->sexo = sexo;
}
// Getters
string Pessoa::getNome() {
    return nome;
}

char Pessoa::getSexo() {
    return sexo;
}

string Pessoa::getEndereco() {
    return endereco;
}

int Pessoa::getCpf() {
    return cpf;
}

string Pessoa::getTelefone() {
    return telefone;
}

string Pessoa::getIdentidade() {
    return identidade;
}

// Setters
void Pessoa::setNome(string novoNome) {
    nome = novoNome;
}

void Pessoa::setSexo(char novoSexo) {
    if(novoSexo != 'M' && novoSexo != 'F'){
        throw ExcecaoSexoInvalido();
        return;
    }
    sexo = novoSexo;
}

void Pessoa::setEndereco(string novoEndereco) {
    endereco = novoEndereco;
}

void Pessoa::setCpf(int novoCpf) {
    cpf = novoCpf;
}

void Pessoa::setTelefone(string novoTelefone) {
    telefone = novoTelefone;
}

void Pessoa::setIdentidade(string novaIdentidade) {
    identidade = novaIdentidade;
}

void Pessoa::imprimir() {
    cout << "Nome: " << nome << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Identidade: " << identidade << endl;
}
