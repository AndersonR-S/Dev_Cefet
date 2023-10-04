#ifndef _LIVRO_HPP
#define _LIVRO_HPP
#include "Autor.hpp"
#include <string>

using namespace std;

class Livro{
    private:
        string titulo;
        string ISBN;
        Autor autor;
    
    public:
        void setTitulo(string titulo);
        string getTitulo();

        void setISBN(string ISBN);
        string getISBN();

        void setAutor(Autor autor);
        Autor getAutor();

};
#endif