#ifndef _BIBLIOTECA_HPP
#define _BIBLIOTECA_HPP
#include "Livro.hpp"
#include <string>
#include <list>

using namespace std;

class Biblioteca{
    private: 
        list <Livro> livros;

    public:
        Biblioteca();

        void adicionarLivro(Livro livro);
        Livro buscarLivro(string titulo, string nomeAutor);
        void mostrarLivros();
        bool verificar();
};


#endif
