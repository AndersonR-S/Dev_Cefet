#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HDD 

#include "ManipulandoArquivo.hpp"
#include <iostream>

using namespace std;

class JogoDaVida
{
private:
public:
    JogoDaVida();

    void mostrarTabuleiro(int **tabuleiro, int tamanho = 5);
    void relatorio(int **tabuleiro, int tamanho = 5,  ManipulandoArquivo *arquivo= nullptr, string mensagem ="", bool transferir = false);

    void iniciarJogo(int **tabuleiro, int interacao, ManipulandoArquivo *arquivo= nullptr);

};

#endif