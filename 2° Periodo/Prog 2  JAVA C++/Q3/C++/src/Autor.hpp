#ifndef _AUTOR_HPP
#define _AUTOR_HPP
#include <string>

using namespace std;

class Autor
{
private:
    string nome;
    string dataNascimento;
    
public:
    void setNome(string nome);
    string getNome();

    void setDataNascimento(string dataNascimento);
    string getDataNascimento();
    
};

#endif
