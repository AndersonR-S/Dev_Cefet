#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP
#include "ExcecaoPacienteInexistente.hpp"
#include "ExcecaoConsultaInexistente.hpp"
#include "ExcecaoSexoInvalido.hpp"
#include "ExcecaoMedicoInexistente.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Consulta.hpp"
#include <list>


class Consultorio{
private:
    list<Paciente> *lista_paciente;
    list<Medico> *lista_medico;
    list<Consulta> *lista_consulta;

protected:
    int contPaciente;

public: 
    Consultorio();

    void cadastrarPaciente(Paciente p);
    void removerPaciente(int cpf);
    void cadastrarMedico(Medico m);
    void removerMedico(int crm);
    void cadastrarConsulta(Consulta c);
    void removerConsulta(int cpf, string data);
    void imprimirListaDeTodosOsPaciente();
    void imprimirConsultas();
    void imprimirConsultaDoMedico(int crm, string data);
    void imprimirListaDeMedicos();

    Paciente buscarPaciente(int cpf);
    Medico buscarMedico(int crm);
    Consulta buscarConsulta(int cpf, int crm, string data);


};

#endif