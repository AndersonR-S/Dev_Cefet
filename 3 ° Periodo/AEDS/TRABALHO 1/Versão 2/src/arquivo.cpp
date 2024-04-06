#include "arquivo.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

Arquivo::Arquivo(string nome_input, string nome_output): nome_input(nome_input),nome_output(nome_output)
{}

void Arquivo::input()
{
    fstream file(nome_input, ios:: in);
    if(!file)
    {
        cerr<<"Erro em abrir o arquivo "+ nome_input<<endl;
        exit(0);
    }


    //leitura do tamanho n do tabuleiro
    short tamanho_n;
    
    file>>tamanho_n;
    file.ignore();

    if(tamanho_n < 5)
    {
        cout<<"O tamanho do tabuleiro tem ser pelo menos 5x5\n";
        file.close();
        exit(0);
    }

    vector<short> *aux_tabuleiro = new vector<short>(tamanho_n*tamanho_n,0);

    //leitura do tabuleiro
    char c;
    short contador = 0;
    for(short i = 0; i < tamanho_n * tamanho_n; i++)
    {
        file>>c;
        (*aux_tabuleiro)[i]=c-'0'; //transformar o char em int/short

        if(c == '1')
        {
            contador++;
        }
    }

    if(contador > (pow(tamanho_n,2)*(1.0/3)))
    {
        cout<<"A quantidade de vivos presente no arquivo de entrada tem que ser menor ou igual à 1/3 da quantidade de elementos do tabuleiro\n";
        file.close();
        exit(0);
    }

    novo_tabuleiro = new Tabuleiro(tamanho_n);
    novo_tabuleiro->setTabuleiro((*aux_tabuleiro));

    delete aux_tabuleiro;

    file.close();

    //limpar o arquivo de saida
    file.open(nome_output, ios::out);
    if(!file)
    {
        cerr<<"Erro em abrir o arquivo "+ nome_output<<endl;
        exit(0);
    }
    file.clear();
    file.close();

}

void Arquivo::output()
{
    fstream file(nome_output, ios::app);
    if(!file)
    {
        cerr<<"Erro em abrir o arquivo "+ nome_output<<endl;
        exit(0);
    }

    for(short i = 0; i< pow(novo_tabuleiro->getTamanho(),2); i++)
    {
        if(i!=1 && i%novo_tabuleiro->getTamanho() == 0)
        {
            file<<endl;
        }

        file<<novo_tabuleiro->getTabuleiro()[i];

    }

    file<<"\n-------------------";

    file.close();
}

Tabuleiro *Arquivo::getNovoTabuleiro() const
{
    return novo_tabuleiro;
}

void Arquivo::setTabuleiro(vector<short> set_tabuleiro)
{
    novo_tabuleiro->setTabuleiro(set_tabuleiro);
}

Arquivo::~Arquivo()
{
    delete novo_tabuleiro;
}


