#include "JogoDaVida.hpp"
JogoDaVida::JogoDaVida(){}

bool checarIgualdade(int **tabuleiro, int **sub_tabuleiro, int tamanho)
{
    for(int i = 0;i < tamanho; i++)
    {
        for(int j = 0; j< tamanho; j++)
        {
            if(tabuleiro[i][j]!=sub_tabuleiro[i][j])
                return false;
        }
    }

    return true;
}

int verificacao(int **tabuleiro, int x,  int y, int tamanho)
{
    int quantidade = 0;

    for(int i = 0; i< tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            //1
            if(i == (x-1) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            //2
            if(i == (x-1) && j == (y) && tabuleiro[i][j]==1)
                quantidade++;
            //3
            if(i == (x-1) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
            //4
            if(i == (x) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            //5
            if(i == (x) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
            //6
            if(i == (x+1) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            //7
            if(i == (x+1) && j == (y) && tabuleiro[i][j]==1)
                quantidade++;
            //8
            if(i == (x+1) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
        }
    }

    return quantidade;
}


void JogoDaVida::mostrarTabuleiro(int **tabuleiro, int tamanho){
    for(int i  = 0; i < tamanho; i++)
    {
        for(int j = 0; j< tamanho; j++)
        {
            cout<<tabuleiro[i][j];
        }
        cout<<endl;
    }
}

void JogoDaVida::relatorio(int **tabuleiro, int tamanho,  ManipulandoArquivo *arquivo, string mensagem, bool transferir){
    cout<<mensagem;

    if(transferir)
    {
        mostrarTabuleiro(tabuleiro, tamanho);
        arquivo->Output(tabuleiro);
    }
}

void JogoDaVida::iniciarJogo(int **tabuleiro, int interacao, ManipulandoArquivo *arquivo)
{
    int aux_de_interacao = 0;
    int tamanho = arquivo->getTamanho();

    int **sub_tabuleiro = arquivo->criarTabuleiro();

    relatorio(tabuleiro, tamanho, arquivo, "Começando o jogo......\n", true);

    while(aux_de_interacao < interacao)
    {
        aux_de_interacao ++;

        for(int i = 0; i< tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {
                int quantidade = verificacao(tabuleiro, i,  j, tamanho);

                if(tabuleiro[i][j]==1){
                    //morre por solidao
                    if(quantidade < 2)
                    {
                        sub_tabuleiro[i][j]= 0;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] morre por solidão\n");
                    }
                   //morre por superlotacao
                    else if( quantidade > 3)
                    {
                        sub_tabuleiro[i][j]= 0;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] morre por superlotação\n");
                    }
                    // com 2 ou 3 vizinhos vive
                    else{
                        sub_tabuleiro[i][j]= 1;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] continua vivendo\n");
                    }
                }
                else{
                    //com 3 vizinhos vive, reproducao
                    if(quantidade == 3)
                    {
                        sub_tabuleiro[i][j]= 1;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] vive por reprodução\n");
                    }
                    else
                    {
                        sub_tabuleiro[i][j]= 0;
                        //relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] continua morta\n");
                    }
                }
            }
        }

        // passar os dados de sub_tabuleiro -> tabuleiro e verificar se sao iguais 
        if(checarIgualdade(tabuleiro, sub_tabuleiro, tamanho))
        {
            relatorio(tabuleiro, tamanho, arquivo,"O tabuleiro atual é igual a ao tabuleiro da interação anterior\n");
            break;
        }

        for (int i = 0; i < tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {
                tabuleiro[i][j]= sub_tabuleiro[i][j];
            }
        }

        relatorio(tabuleiro, tamanho, arquivo, to_string(aux_de_interacao )+"° Interação: \n", true);

    }
    relatorio(tabuleiro, tamanho, arquivo,"Encerrando jogo...\nMonstrando a ultima interação obtida", true);

    delete sub_tabuleiro;
}



