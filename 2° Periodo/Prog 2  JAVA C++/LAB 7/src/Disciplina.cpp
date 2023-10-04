#include "Diciplina.hpp"

Diciplina::Diciplina() {}

Diciplina::Diciplina(string nome, int CH, Professor professorDiciplina)
{
    this->nome = nome;
    this->CH = CH;
    this->professorDiciplina = professorDiciplina;
}

void Diciplina::print()
{
    cout << "CH :" << this->CH << endl;
    cout << "Nome da Diciplina: " << this->nome << endl;
    this->professorDiciplina.print();
    
}
