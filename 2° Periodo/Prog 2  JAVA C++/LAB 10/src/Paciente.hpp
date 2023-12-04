#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include "Pessoa.hpp"

class Paciente : public Pessoa
{
public:
    string relato;
    string dataUltimaConsulta;
    string medicacaoQueToma;

public:
    Paciente();
    Paciente(
        string nome,
        char sexo,
        string endereco,
        int cpf,
        string telefone,
        string identidade,
        string relato,
        string dataUltimaConsulta,
        string medicacaoQueToma);

    void imprimir();

    void setRelato(string relato);
    string getRelato();

    void setDataUltimaConsulta(string data);
    string getDataUltimaConsulta();

    void setMedicacao(string medicacao);
    string getMedicacao();
};

#endif