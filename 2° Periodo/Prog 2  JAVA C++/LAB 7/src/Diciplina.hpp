#ifndef DICIPLINA_HPP
#define DICIPLINA_HPP
#include "Professor.hpp"

class Diciplina
{
private:
    string nome;
    int CH;
    Professor professorDiciplina;

public:
    Diciplina();
    Diciplina(string nome, int CH, Professor professorDiciplina);
    void print();
};
#endif