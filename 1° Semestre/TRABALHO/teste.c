#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int **distancia(int **matriz, int cost,int linha,int coluna)
{  
    //printf("\nrodou uma vez\n\n");
    for (int i = 1; i < linha- 1; i++)
        for (int j = 1; j < coluna - 1; j++)
        {
            if (matriz[i][j] > 0)
            {
                if (matriz[i - 1][j] > matriz[i][j] + 1)
                    matriz[i - 1][j] = matriz[i][j] + 1;

                if (matriz[i + 1][j] > matriz[i][j] + 1)
                    matriz[i + 1][j] = matriz[i][j] + 1;

                if (matriz[i][j - 1] > matriz[i][j] + 1)
                    matriz[i][j - 1] = matriz[i][j] + 1;

                if (matriz[i][j + 1] > matriz[i][j] + 1)
                    matriz[i][j + 1] = matriz[i][j] + 1;
            }
        }

    if (cost == 0)
        return matriz;
    else
        return distancia(matriz, cost - 1, linha, coluna);
}

int main()
{
    int **labirinto = (int **)malloc(sizeof(int *) * 7);
    for (int i = 0; i < 7; i++)
        labirinto[i] = (int *)malloc(sizeof(int) * 9);
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 || j == 0 || i == 6 || j == 8)
                labirinto[i][j] = 0;
            else
                labirinto[i][j] = 1000;
        }
    labirinto[3][5] = 1; // onde começa
    labirinto[4][5] = 0; //monte
    labirinto[5][3] = 0;//monte

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", labirinto[i][j]);
        printf("\n");
    }

    int cost = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 9; j++)
            if (labirinto[i][j] == 1000)
            {
                cost++;
            }

    printf("%d\n\n\n", cost);


    labirinto = distancia(labirinto, cost, 7,9);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", labirinto[i][j]);
        printf("\n");
    }
}