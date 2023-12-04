#ifndef EXCECAOCONSULTAINEXISTENTE_HPP
#define EXCECAOCONSULTAINEXISTENTE_HPP

#include <stdexcept>

using namespace std;

class ExcecaoConsultaInexistente: public runtime_error{
public:
    ExcecaoConsultaInexistente(string mensagem = "Impossível remover Consulta. Paciente _CPF_ não tem consulta agendada para a data _DATA_"):runtime_error(mensagem){}
};
#endif