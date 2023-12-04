#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#include "Paciente.hpp"
#include "Medico.hpp"

class Consulta{
private:
    Paciente paciente;
    Medico medico;
    string data;
    string hora;
public:
    Consulta();
    Consulta(Paciente paciente, Medico medico, string data, string hora);

    void setData(string data);
    string getData();

    void setHora(string hora);
    string getHora();

    void setMedico(Medico medico);
    Medico getMedico();

    void setPaciente(Paciente paciente);
    Paciente getPaciente();
};

#endif