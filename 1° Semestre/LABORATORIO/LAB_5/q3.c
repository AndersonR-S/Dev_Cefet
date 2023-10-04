#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char frase[100];
  char troca1[] = "estuadante";
  char troca2[] = "universidade";
  printf("Informe uma frase: ");
  fgets(frase, 100, stdin);
  frase[strcspn(frase, "\n")] = '\0';

  for (int i = 0; i < strlen(frase); i++)
    frase[i] = tolower(frase[i]);

  char *resultado = strpbrk(frase, " ");
  int tamanho = 1;
  while (resultado != NULL) {
    tamanho++;
    resultado = strpbrk(resultado + 1, " ");
  }
  char recebeFrase[100][100];
  int i = 0, linha = 0, j = 0;
  while (i < strlen(frase)) {
    if (frase[i] != ' ') {
      recebeFrase[linha][j] = frase[i];
      j++;
    } else {
      recebeFrase[linha][i] = '\0';
      linha++;
      j = 0;
    }
    i++;
  }
  printf("\n");

  for (int i = 0; i < tamanho; i++) {
    if (strcmp(recebeFrase[i], "aluno") == 0)
      strcpy(recebeFrase[i], troca1);

    else if (strcmp(recebeFrase[i], "escola") == 0)
      strcpy(recebeFrase[i], troca2);
    else if (strcmp(recebeFrase[i], "aluno,") == 0) {
      strcpy(recebeFrase[i], troca1);
      strcat(recebeFrase[i], ",");
    } else if (strcmp(recebeFrase[i], "escola,") == 0) {
      strcpy(recebeFrase[i], troca2);
      strcat(recebeFrase[i], ",");
    } else if (strcmp(recebeFrase[i], "aluno.") == 0) {
      strcpy(recebeFrase[i], troca1);
      strcat(recebeFrase[i], ".");
    } else if (strcmp(recebeFrase[i], "escola.") == 0) {
      strcpy(recebeFrase[i], troca2);
      strcat(recebeFrase[i], ".");
    }
    printf("%s ", recebeFrase[i]);
  }
}