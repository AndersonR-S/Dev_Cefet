#ifndef EXCECAOPACIENTEINEXISTENTE_HPP
#define EXCECAOPACIENTEINEXISTENTE_HPP

#include <stdexcept>

using namespace std;

class ExcecaoPacienteInexistente: public runtime_error{
public:
    ExcecaoPacienteInexistente(string mensagem = "Impossível remover paciente. CPF não existe"):runtime_error(mensagem){}
};
#endif