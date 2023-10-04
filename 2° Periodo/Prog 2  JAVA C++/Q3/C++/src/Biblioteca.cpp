#include "Biblioteca.hpp"
#include <iostream>
#include <string>

Biblioteca::Biblioteca()
{
    this->Biblioteca::livros;
}

void Biblioteca::adicionarLivro(Livro livro)
{
    this->Biblioteca::livros.push_back(livro);
}

Livro Biblioteca::buscarLivro(string titulo, string nomeAutor)
{
    list<Livro>::iterator livro = this->Biblioteca::livros.begin();
    for (; livro != this->Biblioteca::livros.end(); livro++)
        if (livro->getTitulo() == titulo && livro->getAutor().getNome() == nomeAutor)
            return *livro;

    Livro retornaVazio;
    return retornaVazio;
}

void Biblioteca::mostrarLivros()
{
    cout << endl
         << ":+----------------------------------------------+:" << endl;
    for (Livro livro : this->Biblioteca::livros)
        cout << "Livro: " << livro.getTitulo() << endl
             << "Autor: " << livro.getAutor().getNome() << endl
             << endl;
    cout << endl
         << ":+----------------------------------------------+:" << endl;
}

bool Biblioteca::verificar()
{
    return this->Biblioteca::livros.empty();
}