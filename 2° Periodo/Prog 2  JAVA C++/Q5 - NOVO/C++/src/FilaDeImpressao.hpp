#ifndef FILADEIMPRESSAO_HPP
#define FILADEIMPRESSAO_HPP
#include "Documentos.hpp"
#include <cstring>
#include <iostream>

using namespace std;

class FilaDeImpressao
{
private:
    int numeroDePessoa;
    Documentos *Fila;

public:
    FilaDeImpressao();

    void adicionarDocumento(Documentos *docu);
    void consultarDocumento(int id);
    void listarDocumento();
    void removerDocumento(int id);
    void alterarDocumento(int id);
    int getNumeroDePessoa();
};
#endif
