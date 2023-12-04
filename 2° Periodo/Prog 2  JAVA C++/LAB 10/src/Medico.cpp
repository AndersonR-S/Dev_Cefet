#include "Medico.hpp"

Medico::Medico() {}

Medico::Medico(string nome, char sexo, string endereco, int cpf, string telefone, string identidade, int CRM, string especialidade)
    : Pessoa(nome,sexo,endereco,cpf,telefone, identidade) {
        this->CRM = CRM;
        this->especialidade = especialidade;
}

void Medico::imprimir() {
    Pessoa::imprimir();
    cout << "CRM: " << CRM << endl;
    cout << "Especialidade: " << especialidade << endl;
}

int Medico::getCRM() {
    return CRM;
}

void Medico::setCRM(int crm) {
    CRM = crm;
}

string Medico::getEspecialidade() {
    return especialidade;
}

void Medico::setEspecialidade(string especialidade) {
    this->especialidade = especialidade;
}