#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Pessoa.hpp"

class Medico : public Pessoa
{
private:
    int CRM;
    string especialidade;

public:
    Medico();
    Medico(
        string nome,
        char sexo,
        string endereco,
        int cpf,
        string telefone,
        string identidade,
        int CRM,
        string especialidade);

    void imprimir();

    int getCRM();
    void setCRM(int crm);

    string getEspecialidade();
    void setEspecialidade(string especialidade);

};

#endif