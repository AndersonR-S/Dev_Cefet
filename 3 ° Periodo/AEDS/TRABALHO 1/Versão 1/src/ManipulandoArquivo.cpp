#include "ManipulandoArquivo.hpp"

ManipulandoArquivo::ManipulandoArquivo(){}

void ManipulandoArquivo::setInputArquivo(string input_arquivo){
    this->input_arquivo = input_arquivo;
}

void ManipulandoArquivo::setOutputArquivo(string output_arquivo){
    this->output_arquivo = output_arquivo;
}

int **ManipulandoArquivo::Input(){

    fstream arquivo;
    arquivo.open(input_arquivo, ios::in);
    if(!arquivo)
    {
        cout << "Arquivo de entrada nao pode ser aberto ou não encontrado"<< endl;
        exit(0);
    }
    
    arquivo>>tamanho;
    if(tamanho < 5)
    {
        cout << "Arquivo não atende os requisitos"<< endl;
        arquivo.close();
        exit(0);
    }
    arquivo.ignore(); // para ignorar o \n

    int **tabuleiro =criarTabuleiro();
    int contagem = 0;
    for(int i = 0; i< tamanho; i++)
    {
        string linha;
        getline(arquivo,linha);
        for(int j = 0; j<tamanho; j++)
        {
            tabuleiro[i][j] = linha[j] - '0'; // coonverver o char para int

            if(linha[j]=='1')
            {
                contagem ++;
            }
        }
        cout<<endl;
    }

    if(contagem >= (tamanho*tamanho*(1/3.0)))
    {
        cout << "A quantidade de vivo tem que ser no maximo 1/3 da quantidade de elementos "<<tamanho*tamanho<<"\n"<< endl;
        arquivo.close();
        exit(0);
    }

    arquivo.close();

    return tabuleiro;
}

void ManipulandoArquivo::Output(int **tabuleiro){
    ofstream arquivo(output_arquivo, ios::app);
    if(!arquivo)
    {
        cout << "Arquivo de saida nao pode ser aberto ou não encontrado"<< endl;
        exit(0);
    }

    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j< tamanho; j++)
        {
            arquivo<<tabuleiro[i][j];
        }
        arquivo<<endl;
    }
    arquivo <<"--------------------------\n";
    arquivo.close();
}

int ManipulandoArquivo::getTamanho() const{
    return tamanho;
}

void ManipulandoArquivo::setTamanho(int tamanho){
    this->tamanho = tamanho;
}

int ** ManipulandoArquivo::criarTabuleiro(){
    int **tabuleiro = (int **)malloc(sizeof(int *)*tamanho);
    for(int i=0; i<tamanho; i++)
    {
        tabuleiro[i]=(int *)malloc(sizeof(int *)*tamanho);
    }
    return tabuleiro;
}