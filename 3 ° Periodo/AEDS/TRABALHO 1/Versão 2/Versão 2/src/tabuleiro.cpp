#include "tabuleiro.hpp"
#include <iostream>
#include <cmath>

Tabuleiro::Tabuleiro(short tamanho) : tamanho(tamanho) {
    tabuleiro = new vector<short>(tamanho * tamanho, 0); 
}

void Tabuleiro::print()
{
    for(short i = 0; i < pow(tamanho,2); i++)
    {
        if(i % tamanho == 0)
        {
            cout<<endl;
            cout<<"|";
        }
        cout<<(*tabuleiro)[i]<<"|";

    }
    cout<<endl;
}

vector<short> Tabuleiro::getTabuleiro() const
{
    return (*tabuleiro);
}

void Tabuleiro::setTabuleiro(vector<short> novo_tabuleiro)
{
    for( short i = 0; i < (tamanho*tamanho);  i++)
    {
        (*tabuleiro)[i] = novo_tabuleiro[i];
    }
}

short Tabuleiro::getTamanho() const
{
    return tamanho;
}

Tabuleiro::~Tabuleiro()
{
    delete tabuleiro;
}