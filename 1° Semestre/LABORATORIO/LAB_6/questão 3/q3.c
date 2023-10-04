#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void filtra_nomes(char *nome_arquivo_entrada, char letra_inicial, char *nome_arquivo_saida){
  
    FILE *arquivoEntrada = fopen(nome_arquivo_entrada, "r");
    if (arquivoEntrada== NULL){
        printf("Erro, arquivo não existe.\n");
        exit(0);
    }
     FILE *arquivoSaida = fopen(nome_arquivo_saida, "w");
    if (arquivoSaida == NULL){
        printf("Erro, na criação do arquivo.\n");
        exit(0);
    }
  
    char nome[30], sobrenome[40];
    int idade, i =0;
    for(; (fscanf(arquivoEntrada, "%s %s %d", nome,sobrenome,&idade)) != EOF;)
      if (nome[0] == tolower(letra_inicial) || nome[0] == toupper(letra_inicial)) {
         fprintf(arquivoSaida, "%s %s %d\n", nome, sobrenome, idade);
        i++;
      }
    if(i==0){
      printf("Não tem nomes que começam com a letra %c",letra_inicial);
      exit(0);
    }
  
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    printf("Nomes filtrados!\n");

}
int main() {
    char nome_entrada[100],nome_saida[100], letra;
    
    printf("Digite o nome do arquivo (lista_nomes):");
    scanf("%s",nome_entrada);
    printf("Digite a letra inicial dos nomes: ");
    scanf("%s", &letra);
    printf("Informe o nome do arquivo de saida: ");
    scanf("%s", nome_saida);
    strcat(nome_entrada,".txt");
    strcat(nome_saida,".txt");
    filtra_nomes(nome_entrada, letra, nome_saida);

    return 0;
}