#include "JogoDaVida.hpp"
#include "ManipulandoArquivo.hpp"

#define nome_input "datasets/input.mps"
#define nome_output "src/geracoes.mps"

int main(){
    ManipulandoArquivo *arquivo = new ManipulandoArquivo();
    JogoDaVida *jogo= new JogoDaVida();

    int numero_interacao;

    arquivo->setInputArquivo(nome_input);
    arquivo->setOutputArquivo(nome_output);

    int **tabuleiro = arquivo->Input();
    
    cout<<"Quantas interações que o úsuario quer: ";
    cin>>numero_interacao;

    jogo->iniciarJogo(tabuleiro, numero_interacao, arquivo);

    delete arquivo;
    delete jogo;
    return 0;
}