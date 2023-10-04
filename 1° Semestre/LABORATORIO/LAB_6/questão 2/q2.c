#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void substitui_string(char *nome_arquivo_entrada, char *string_procurada,
                      char *string_substituta, char *nome_arquivo_saida) {
  FILE *arquivo = fopen(nome_arquivo_entrada, "r");
  if (arquivo == NULL){
       printf("Erro na criação do arquivo");
       exit(0);
  }
    
  char recebe[100];
  fgets(recebe, 100, arquivo);

  fclose(arquivo);

  char substituicao[50][100];

  if (strstr(recebe, string_procurada)) {
    int i = 0, linha = 0, j = 0;

    while (recebe[i] != '\0') {
      if (recebe[i] != ' ') {
        substituicao[linha][j] = recebe[i];
        j++;
      } else {
        substituicao[linha][i] = '\0';
        linha++;
        j = 0;
      }
      i++;
    }
    char string_recebe[100];

    for (int p = 0; p <= linha; p++)
      if (strcmp(substituicao[p], string_procurada) == 0)
        strcpy(substituicao[p], string_substituta);

    for (int p = 0; p <= linha; p++) {
      strcat(string_recebe, substituicao[p]);
      strcat(string_recebe, " ");
    }
    arquivo = fopen(nome_arquivo_saida, "w");
    fputs(string_recebe, arquivo);
    fclose(arquivo);
  }
}
int main() {
  char texto[100];
  char nome_entrada[20], nome_saida[20], string_procura[20],
      string_substitui[20];

  printf("Informe o nome do arquivo: ");
  fgets(nome_entrada, 20, stdin);
  printf("Escreva o conteudo do arquivo: ");
  fgets(texto, 100, stdin);

  fflush(stdin);
  texto[strcspn(texto, "\n")] = '\0';

  FILE *fd = fopen(nome_entrada, "w");
  fputs(texto, fd);
  fclose(fd);
  fflush(stdin);
  printf("Procurar: ");
  fgets(string_procura, 20, stdin);
  printf("Substitui: ");
  fgets(string_substitui, 20, stdin);
  printf("Informe o nome do arquivo de saida: ");
  fgets(nome_saida, 20, stdin);

  string_procura[strcspn(string_procura, "\n")] = '\0';
  string_substitui[strcspn(string_substitui, "\n")] = '\0';
  substitui_string(nome_entrada, string_procura, string_substitui, nome_saida);
  return 0;
}