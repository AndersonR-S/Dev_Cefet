#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int *gerado_numeros(int tam)
{
    int *vetor;
    vetor = (int *)malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++)
        vetor[i] = (rand() % 18) + 2;

    return vetor;
}
int *ler_numeros(char *nome, int tam)
{
    FILE *arquivo = fopen(nome, "rb");
    if (arquivo == NULL)
    {
        printf("ERRO! Não foi possivel abrir o arquivo.");
        exit(0);
    }
    int *numeros = (int *)malloc(tam * sizeof(int));
    fread(numeros, sizeof(int), 50, arquivo);
    fclose(arquivo);
    return numeros;
}

void operacao(int *numeros, int quantidade)
{
    // Leia os números do arquivo binário e calcule a soma, a média e a quantidade deles
    float soma = 0, media;
    for (int i = 0; i < quantidade; i++)
        soma += numeros[i];
    media = soma / (quantidade * 1.0);

    float *vetor = (float *)malloc(3 * sizeof(int));
    float *vetor2 = (float *)malloc(3 * sizeof(int));
    vetor[0] = 0;
    vetor[1] = 0;
    vetor[2] = 0;

    FILE *arquivo = fopen("resultadoTotal.bin", "rb");
    if (arquivo == NULL)
    {   
        arquivo = fopen("resultadoTotal.bin", "wb");
        fwrite(vetor, sizeof(int), 3, arquivo);
    }
    fclose(arquivo);

    arquivo = fopen("resultadoTotal.bin", "rb");

    fread(vetor2, sizeof(float), 3, arquivo);
  

    printf("ATUALMENTE:.\nSOMA: %.f\tMEDIA: %.2f\tQUANTIDADE: %d", soma, media, quantidade);
    printf("\n\n------------------------------------\n\n");

    vetor2[0] += soma;
    vetor2[1] += media;
    vetor2[2] += quantidade;
    


    printf("ARQUIVO TOTAL:.\nSOMA: %.f\tMEDIA: %.2f\tQUANTIDADE: %.f", vetor2[0], vetor2[1], vetor2[2]);
    printf("\n\n------------------------------------\n\n");
    fclose(arquivo);
    arquivo = fopen("resultadoTotal.bin", "wb");
    fwrite(vetor2, sizeof(int), 3, arquivo);
    fclose(arquivo);

}
int main()
{
    int *numeros, *cpy_numeros, tam;
    char nome[15];
    printf("Informe a quantidade de numeros para ser gerados: ");
    scanf("%d", &tam);

    numeros = gerado_numeros(tam);

    printf("Informe o nome para o arquivo binario: ");
    fflush(stdin);
    fgets(nome, 15, stdin);
    nome[strlen(nome) - 1] = '\0';
    strcat(nome, ".bin");

    FILE *arquivo = fopen(nome, "wb");
    if (arquivo == NULL)
    {
        printf("ERRO! Não foi possivel criar o arquivo.");
        exit(0);
    }
    fwrite(numeros, sizeof(int), tam, arquivo);
    fclose(arquivo);

    operacao(ler_numeros(nome, tam), tam);
}