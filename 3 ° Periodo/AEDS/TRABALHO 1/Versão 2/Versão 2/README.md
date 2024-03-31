# Atividade 0: Trabalho de aquecimento

## Introdução
O objetivo principal deste trabalho é revisar e reforçar os conceitos de manipulação de matrizes, controle de fluxo e lógica de jogo proposto no laboratório da disciplina de Algoritmos e Estruturas de Dados I pelo professor Michel Pires Da Silva no CEFET-MG *campus* Divinópolis.

O trabalho é direcionado ao desenvolvimento do Jogo da Vida, um autômato celular que evolui de acordo com regras simples, mas gera padrões complexos. Ele é representado por uma matriz 2D de células, cada uma podendo estar viva ou morta.


## Desenvolvimento  


### Regras e Implementações:
1. Crie uma matriz N x N para representar o tabuleiro do Jogo da Vida.
2. Inicialize o tabuleiro com células vivas (1) e mortas (0) aleatoriamente.
3. Implemente uma função para exibir o estado atual do tabuleiro.
4. Implemente uma função para produzir um relatório de execução, guardando o histórico da evolução do jogo em arquivo.
5. Implemente uma função para calcular a próxima geração do Jogo da Vida com base nas seguintes regras:

    - Uma célula viva com menos de dois vizinhos vivos morre (solidão).
    - Uma célula viva com mais de três vizinhos vivos morre (superpopulação).
    - Uma célula viva com dois ou três vizinhos vivos sobrevive.
    - Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).
6. Execute várias gerações do jogo e mostre o estado do tabuleiro após cada geração.

<div align = "center" >
<img src="img/figura_1.png" height="40%" width="40%">
</div>


### 





