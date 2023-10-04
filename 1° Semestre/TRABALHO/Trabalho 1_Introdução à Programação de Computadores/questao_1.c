#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW 7
#define MAX_COL 9

bool percorrer_labirinto(char labirinto[MAX_ROW][MAX_COL], int linha, int coluna)
{
    
    if (labirinto[linha][coluna] == '#' || labirinto[linha][coluna] == '.')
        return false;
    if (labirinto[linha][coluna] == 'F')
        return true;


    if (labirinto[linha][coluna] != 'S')
        labirinto[linha][coluna] = '.';

    if (
        // loop e movimentacão para
        percorrer_labirinto(labirinto, linha + 1, coluna) || // frente(linha+1, coluna)
        percorrer_labirinto(labirinto, linha, coluna - 1) || // cima(linha,culina-1)
        percorrer_labirinto(labirinto, linha, coluna + 1) || // baixo(linha, coluna+1)
        percorrer_labirinto(labirinto, linha - 1, coluna))   // tras(linha, coluna+1)
    {
        return true;
    }
    else
    {
        labirinto[linha][coluna] = ' '; // apagar o ponto
        return false;
    }
}
int encontrar_caminho(char labirinto[MAX_ROW][MAX_COL])
{
    int inicio_linha = -1;
    int inicio_coluna = -1;
    int final_linha = -1;
    int final_coluna = -1;

    // Procurando onde esta a saida e a chegada
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            if (labirinto[i][j] == 'S')
            {
                inicio_linha = i;
                inicio_coluna = j;
            }
            else if (labirinto[i][j] == 'F')
            {
                final_linha = i;
                final_coluna = j;
            }
        }
    }
    // Quando não tem a saida ou a entrada
    if (inicio_linha == -1 || inicio_coluna == -1 || final_linha == -1 || final_coluna == -1)
        printf("Não tem entrda ou Saida !!\n\n");

    // Chamando a função recursiva
    if (percorrer_labirinto(labirinto, inicio_linha, inicio_coluna))
    {
        printf("Saida Encontrada!\n\n");
        for (int i = 0; i < MAX_ROW; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
                printf("%c ", labirinto[i][j]);
            printf("\n");
        }
        printf("\n\n");
    }
    else
        printf("Não tem cominho para a Saida!!\n\n");
}

int main()
{
    char labirinto[MAX_ROW][MAX_COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', 'S', '#'},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', 'F', '#'}};

    encontrar_caminho(labirinto);

    return 0;
}