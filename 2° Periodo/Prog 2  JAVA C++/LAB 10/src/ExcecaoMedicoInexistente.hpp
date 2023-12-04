#ifndef EXCECAOMEDICOINEXISTENTE_HPP
#define EXCECAOMEDICOINEXISTENTE_HPP
#include <stdexcept>

using namespace std;

class ExcecaoMedicoInexistente: public runtime_error{
public:
    ExcecaoMedicoInexistente(string mensagem = "Impossível remover médico. CRM não existe"):runtime_error(mensagem){}
};
#endif