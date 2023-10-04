#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int **funcao_matriz(int n) // Criar matriz, Receber os valores dos elementos e Imprimir a matriz
{
    int **matriz = (int **)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        matriz[i] = (int *)malloc(sizeof(int) * n);

    printf("\nInforme os valores os elementos 1 ou 0 (conforme exista ou não estrada direta)\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matriz[i][j] = 1;
            else
            {
                printf("Posicao [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nTabela:\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }

    return matriz;
}

int quantas_estradas_e_saidas(int **matriz, int k, int n, int **transfere) // Dado k, determinar quantas estradas saem e quantas chegam à cidade k.
{
    int chegam = 0, saem = 0;

    for (int i = 0; i < n; i++)
    {
        if (matriz[k - 1][i] == 1)
            saem++;
        if (matriz[i][k - 1] == 1)
            chegam++;
    }

    int recebe[2];
    recebe[0] = chegam - 1;
    recebe[1] = saem - 1;
    *transfere = recebe;
    return *recebe;
}

void maior_numero_estradas(int **matriz, int n) // A qual das cidades chega o maior número de estradas?
{
    int maior = -1, cidade = 0, compara = 0, recebe = 0;
    int *aux;
    printf("O(s) maior(es) numero de estradas:\n");

    for (int i = 0; i < n; i++)
    {
        quantas_estradas_e_saidas(matriz, i + 1, n, &aux);
        recebe = aux[0];
        if (maior < recebe)
        {
            maior = recebe;
            cidade = i;
        }
    }
    printf("Cidade %d: %d\n", cidade + 1, maior);
    for (int i = 0; i < n; i++)
    {
        quantas_estradas_e_saidas(matriz, i + 1, n, &aux);
        recebe = aux[0];
        if (cidade != i)
            if (maior == recebe)
                printf("Cidade %d: %d\n", i + 1, maior);
    }
    printf("\n\n");
}

void mao_dupla(int **matriz, int n, int k) // Verifica se todas as ligações com uma cidade são de mão dupla!
{
    int aux = 0;

    for (int i = 0; i < n; i++)
        if (k - 1 != i)
        {
            if (matriz[k - 1][i] == 1 && matriz[i][k - 1] == 1)
                aux = 1;
            else
                aux = 0;
        }

    //
    if (aux == 1)
        printf("\nTodas as ligações são de mão dupla");
    else if (aux == 0)
        printf("\nNem todas as ligações são de mão dupla");
}

void saidas_diretas_para_k(int **matriz, int n, int k)
{
    int *cidades = (int *)malloc(sizeof(int) * n);
    int costante = 0;

    for (int i = 0; i < n; i++)
        if (k - 1 != i)
            if (matriz[i][k - 1] == 1)
            {
                cidades[costante] = i + 1;
                costante++;
            }

    printf("Cidades que tem saída direto para %d:\n", k);
    for (int i = 0; i < costante; i++)
        printf("%d, ", cidades[i]);
    printf("\b\b.");
}

void relacao_entradas_e_saidas(int **matriz, int n)
{
    int isolado;
    int saida;
    int entrada;

    for (int i = 0; i < n; i++)
    {
        isolado = 0;
        saida = 0;
        entrada = 0;
        int cost = 0;
        int *cidades_entrada = (int *)malloc(sizeof(int) * n);
        int *cidades_saida = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (matriz[j][i] == 1 || matriz[i][j] == 1) // Verificar se as cidades são isoladas
                    isolado++;
                if (matriz[j][i] == 1 && matriz[i][j] == 0) // Verificar se as cidades tem saida, mas sem entrada
                {
                    cidades_saida[cost] = j;
                    cost++;
                    saida++;
                }
                if (matriz[j][i] == 0 && matriz[i][j] == 1) // Verificar se as cidades tem entrada, mas não tem saida
                {
                    cidades_entrada[cost] = j;
                    cost++;
                    entrada++;
                }
            }
        }
        printf("\n");
        if (cidades_entrada != 0 && cidades_saida != 0 && isolado != 0)
            printf("A cidade %d tem pelo menos uma entra e saida!!\n", i + 1);
        else if (cidades_entrada == 0 && cidades_saida == 0 && isolado == 0)
            printf("A cidade %d é isolada!!\n\n", i + 1);
        else if (cidades_entrada == 0 && cidades_saida != 0 && isolado == 0)
        {
            printf("A cidade %d tem somente saidas, pelas cidades: ", i + 1);
            for (int m = 0; m < saida; m++)
                printf("%d ", cidades_entrada[m]);
        }

        else if (cidades_entrada == 0 && cidades_saida != 0 && isolado == 0)
        {
            printf("A cidade %d tem somente entradas, pelas cidades: ", i + 1);
            for (int m = 0; m < entrada; m++)
                printf("%d ", cidades_entrada[m]);
        }
        printf("\n");
    }
}

int roteiro(int **matriz, int *vetor, int n)
{
    int cost = 0;

    for (int i = 0; i < 5; i++)
    {
        if (matriz[vetor[i]][vetor[i + 1]] == 1)
            cost = 1;
        else if (matriz[vetor[i]][vetor[i + 1]] == 0)
            return 0;
    }

    return cost;
}

int main()
{
    int n, questao;
    int **matriz;
    printf("Digite o tamanho da ordem da Matriz: ");
    scanf("%i", &n);

    // Criar matriz, Receber os valores dos elementos e Imprimir a matriz
    matriz = funcao_matriz(n);

    printf("\nEscolhe uma questao de 1 a 6: ");
    scanf("%i", &questao);
    switch (questao)
    {
    case 1:
    {
        int k;
        int *recebe = (int *)malloc(sizeof(int) * 2);
        printf("\nInforme qual cidade:\n");
        scanf("%d", &k);

        quantas_estradas_e_saidas(matriz, k, n, &recebe);

        printf("\nDa cidade %d, existe(m) %d entrada(s) e %d saida(s)\n\n", k, recebe[0], recebe[1]);
        break;
    }

    case 2:
    {
        maior_numero_estradas(matriz, n);

        break;
    }
    case 3:
    {
        int k;
        printf("\nInforme qual cidade: ");
        scanf("%d", &k);

        mao_dupla(matriz, n, k);

        break;
    }
    case 4:
    {
        int k;
        printf("Informe qual cidade: ");
        scanf("%d", &k);
        saidas_diretas_para_k(matriz, n, k);
        break;
    }
    case 5:
    {
        relacao_entradas_e_saidas(matriz, n);

        break;
    }
    case 6:
    {
        int vetor[5];
        printf("Digite 5 numeros da sequencia (0 - %d):\n", n - 1);
        for (int i = 0; i < 5; i++)
        {
            scanf("%d", &vetor[i]);
            if (!(vetor[i] >= 0 && vetor[i] < n))
            {
                printf("\nCidade não existe!!");
                return 0;
            }
        }
        if (roteiro(matriz, vetor, n) == 1)
            printf("\nO roteiro da sequencia é possível\n");
        else
            printf("\nO roteiro não é possível\n");
        break; 
        
    }
    default:
        exit(0);
        break;
    }
}