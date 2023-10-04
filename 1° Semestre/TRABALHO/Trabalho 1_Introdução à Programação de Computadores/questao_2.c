#include <stdio.h>
#include <stdlib.h>
void fibonacci_matriz()
{
    int n;
    printf("informe o tamanho da ordem da Matriz, precisa ser maior ou igual a 2: ");
    scanf("%i", &n);

    // Criando a Matriz de ordem n
    int **Matriz = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        Matriz[i] = (int *)malloc(n * sizeof(int));

    // Dados fixos
    int a, b;
    int aux;
    Matriz[0][0] = 0;
    Matriz[0][1] = 1;
    Matriz[1][0] = 1;
    Matriz[1][1] = 1;

    // Construção da primeira e segunda coluna
    for (int i = 0; i < 2; i++)
    {
        a = Matriz[0][i]; // 0 1
        b = Matriz[1][i]; // 1 1

        for (int j = 2; j < n; j++)
        {
            aux = a + b;
            Matriz[j][i] = aux;
            a = b;
            b = aux;
        }
    }

    // Preenchendo os que estão vazio
    for (int i = 0; i < n; i++)
    {
        a = Matriz[i][0];
        b = Matriz[i][1];
        for (int j = 2; j < n; j++)
        {
            aux = a + b;
            Matriz[i][j] = aux;
            a = b;
            b = aux;
        }
    }

    // Imprimindo resultado
    printf("\nMatriz fibonacci: \n");
    for (int i = 0; i < n; i++)
    {
        printf("[\t");
        for (int j = 0; j < n; j++)
            printf("%d\t", Matriz[i][j]);
        printf("]\n");
    }
    printf("\n");
}

int main(void)
{
    fibonacci_matriz();
    return 0;
}