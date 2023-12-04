#include "Paciente.hpp"

Paciente::Paciente() {}

Paciente::Paciente(string nome, char sexo, string endereco, int cpf, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacaoQueToma)
    :Pessoa(nome,sexo,endereco,cpf,telefone, identidade){
        this->relato = relato;
        this->medicacaoQueToma = medicacaoQueToma;
        this->dataUltimaConsulta = dataUltimaConsulta;
}

void Paciente::imprimir() {
    Pessoa::imprimir();
    cout << "Relato: " << relato << endl;
    cout << "Data da Última Consulta: " << dataUltimaConsulta << endl;
    cout << "Medicação que Toma: " << medicacaoQueToma << endl;
}

void Paciente::setRelato(string relato) {
    this->relato = relato;
}

string Paciente::getRelato() {
    return relato;
}

void Paciente::setDataUltimaConsulta(string data) {
    dataUltimaConsulta = data;
}

string Paciente::getDataUltimaConsulta() {
    return dataUltimaConsulta;
}

void Paciente::setMedicacao(string medicacao) {
    medicacaoQueToma = medicacao;
}

string Paciente::getMedicacao() {
    return medicacaoQueToma;
}