#include "jogo.hpp"
#include <iostream>
#include <cmath>

#define nome_input "datasets/input.mps"
#define nome_output "datasets/geracoes.mps"

bool checarIgualdade(vector<short>tabuleiro, vector<short>sub_tabuleiro, short tamanho)
{
    for(int i = 0;i < tamanho*tamanho; i++)
    {
        if(tabuleiro[i]!=sub_tabuleiro[i])
            return false;
    }
    return true;
}

void relatorio(const string& mensagem = "", Arquivo* arquivo = nullptr) 
{
    cout<<mensagem;
    if(arquivo != nullptr)
    {
        arquivo->getNovoTabuleiro()->print();
        arquivo->output();
    }
}

short verificacao(Tabuleiro *tabuleiro,  short posicao)
{
    short contador = 0;

    //1
    if((posicao - tabuleiro->getTamanho() -1 ) > 0  && tabuleiro->getTabuleiro()[(posicao - tabuleiro->getTamanho()-1)]==1)
    {
        contador++;
    }

    //2
    if((posicao - tabuleiro->getTamanho()) > 0 && tabuleiro->getTabuleiro()[posicao - tabuleiro->getTamanho()]==1)
    {
        contador++;
    }
    //3
    if((posicao - tabuleiro->getTamanho() + 1) > 0 && tabuleiro->getTabuleiro()[posicao - tabuleiro->getTamanho()+1]==1)
    {
        contador++;
    }
    //4
    if((posicao - 1)> 0 && tabuleiro->getTabuleiro()[posicao - 1]==1)
    {
        contador++;
    }
    //5
    if((posicao + 1)> 0 && tabuleiro->getTabuleiro()[posicao + 1]==1)
    {
        contador++;
    }
    //6
    if((posicao + tabuleiro->getTamanho() - 1)> 0 && tabuleiro->getTabuleiro()[posicao + tabuleiro->getTamanho() -1]==1)
    {
        contador++;
    }
    //7
    if((posicao + tabuleiro->getTamanho())> 0 && tabuleiro->getTabuleiro()[posicao + tabuleiro->getTamanho()]==1)
    {
        contador++;
    }
    //8
    if((posicao + tabuleiro->getTamanho()+1)> 0 && tabuleiro->getTabuleiro()[posicao + tabuleiro->getTamanho()+1]==1)
    {
        contador++;
    }

    return contador;
}


Jogo::Jogo()
{
    arquivo = new Arquivo(nome_input, nome_output);
}

void Jogo::iniciarJogo()
{
    arquivo->input();

    short interacao;
    cout<<"Quantas interações que o úsuario quer: ";
    cin>>interacao;

    short tamanho = arquivo->getNovoTabuleiro()->getTamanho();


    relatorio("\nComeçando o Jogo da Vida...\nTabuleiro Icicial:",arquivo);

    vector<short> *sub_tabuleiro = new vector<short>(pow(tamanho,2),0);

    for (short i = 0; i< interacao ; i++)
    {
        for(short j = 0; j < pow(tamanho, 2); j++)
        {
            short quantidade = verificacao(arquivo->getNovoTabuleiro(),j);

                if(arquivo->getNovoTabuleiro()->getTabuleiro()[j] == 1 )
                {
                    //morre por solidao
                    if(quantidade < 2)
                    {
                        (*sub_tabuleiro)[j]= 0;
                        relatorio("Posição [" + to_string(static_cast<int>(floor(j/tamanho))) + " - " + to_string(j%tamanho) + "] morre por solidão\n");
                    }
                   //morre por superlotacao
                    else if( quantidade > 3)
                    {
                        (*sub_tabuleiro)[j]= 0;
                        relatorio("Posição [" + to_string(static_cast<int>(floor(j/tamanho))) + " - " + to_string(j%tamanho) + "] morre por superlotação\n");
                    }
                    // com 2 ou 3 vizinhos vive
                    else{
                        (*sub_tabuleiro)[j]= 1;
                        relatorio("Posição [" + to_string(static_cast<int>(floor(j/tamanho))) + " - " + to_string(j%tamanho) + "] continua vivendo\n");
                    }
                }
                else{
                    //com 3 vizinhos vive, reproducao
                    if(quantidade == 3)
                    {
                        (*sub_tabuleiro)[j]= 1;
                        relatorio("Posição [" + to_string(static_cast<int>(floor(j/tamanho)))  + " - " + to_string(j%tamanho) + "] vive por reprodução\n");
                    }
                    else
                    {
                        (*sub_tabuleiro)[j]= 0;
                        //relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] continua morta\n");
                    }
                }

                
        }

         // passar os dados de sub_tabuleiro -> tabuleiro e verificar se sao iguais 
        if(checarIgualdade(arquivo->getNovoTabuleiro()->getTabuleiro(), (*sub_tabuleiro) , tamanho))
        {
            relatorio("\nO tabuleiro atual é igual a ao tabuleiro da interação anterior\n");
            break;
        }

        arquivo->setTabuleiro((*sub_tabuleiro));

        relatorio("\n"+to_string(i+1)+"° Interação:", arquivo);
        cout<<"------------\n";
    }

    relatorio("\nEncerrando jogo...\nMonstrando a ultima interação obtida",arquivo);

    delete sub_tabuleiro;
}
Jogo::~Jogo() {
    delete arquivo;
}
