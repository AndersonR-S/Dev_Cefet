#include "Consulta.hpp"

Consulta::Consulta(){}

Consulta::Consulta(Paciente paciente, Medico medico, string data, string hora)
    : paciente(paciente), medico(medico), data(data), hora(hora) {
}

void Consulta::setData(string data) {
    this->data = data;
}
string Consulta::getData() {
    return data;
}

void Consulta::setHora(string hora) {
    this->hora = hora;
}
string Consulta::getHora() {
    return hora;
}

void Consulta::setMedico(Medico medico) {
    this->medico = medico;
}
Medico Consulta::getMedico() {
    return medico;
}

void Consulta::setPaciente(Paciente paciente) {
    this->paciente = paciente;
}
Paciente Consulta::getPaciente() {
    return paciente;
}