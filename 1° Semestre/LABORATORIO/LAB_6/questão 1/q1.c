#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena_arquivo(char *arquivo_entrada, char *arquivo_saida) {
  int recebe[100], i;
  char c;
  FILE *arquivo;
  if ((arquivo = fopen(arquivo_entrada, "r")) == NULL) {
    printf("Arquivo não encontrado\n");
    exit(0);
  }
  for( i = 0; (fscanf(arquivo, "%d", &recebe[i])) != EOF; i++){}
  fclose(arquivo);
  printf("\nOs numeros de entrada: ");
  for (int j = 0; j <= i ; j++) 
     printf("%d ",recebe[j]);
  for (int j = 0; j < i ; j++) {
    for (int m = j + 1; m < i+1; m++) {
      int menor = j;
      if (recebe[j] > recebe[m]) {
        int troca = recebe[m];
        recebe[m] = recebe[j];
        recebe[j] = troca;
        menor = m;
      }
    }
  }
   printf("\n\nOs numeros de saida para a pasta %s: ",arquivo_saida);
  for (int j = 0; j <=i ; j++) 
     printf("%d ",recebe[j]);
  
  arquivo = fopen(arquivo_saida,"w");
  for(int j=0;j<=i;j++)
      fprintf(arquivo, "%d\t", recebe[j]);
  fclose(arquivo);
  ;
}

int main() {
  char nome_arquivoEntrada[20], nome_arquivoSaida[20];
  printf("o nome do arquivo que possuem os numeros é numeros\n\n");
  printf("Digite o nome do arquivo de entrada: ");
  fgets(nome_arquivoEntrada, 20, stdin);
  nome_arquivoEntrada[strlen(nome_arquivoEntrada) - 1] = '\0';
  strcat(nome_arquivoEntrada, ".txt");

  printf("Digite o nome do arquivo de saida: ");
  fgets(nome_arquivoSaida, 20, stdin);
  nome_arquivoSaida[strlen(nome_arquivoSaida) - 1] = '\0';
  strcat(nome_arquivoSaida, ".txt");

  ordena_arquivo(nome_arquivoEntrada, nome_arquivoSaida);
  return 0;
}