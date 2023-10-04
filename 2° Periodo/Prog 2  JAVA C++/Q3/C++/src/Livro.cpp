#include "Livro.hpp"

void Livro::setTitulo(string titulo){
    this->titulo = titulo;
}
string Livro::getTitulo(){
    return this->titulo;
}

void Livro::setISBN(string ISBN){
    this->ISBN=ISBN;
}

string Livro::getISBN(){
    return this->ISBN;
}

void Livro::setAutor(Autor autor){
    this->autor = autor;
}

Autor Livro::getAutor(){
    return this->autor;
}