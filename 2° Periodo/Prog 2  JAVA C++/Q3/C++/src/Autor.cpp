#include "Autor.hpp"

void Autor::setNome(string nome){
    this->nome = nome;
}
string Autor::getNome(){
    return this->nome;
}

void Autor::setDataNascimento(string dataNascimento){
    this->dataNascimento = dataNascimento;
}
string Autor::getDataNascimento(){
    return this->dataNascimento;
}