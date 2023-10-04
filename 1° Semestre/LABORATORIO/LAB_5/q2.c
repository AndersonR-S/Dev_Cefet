#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char frase[100], cpyfrase[100][100], troca[] = " ou mouse";
  printf("Escreva a Frase: ");
  fgets(frase, sizeof(frase), stdin);
  frase[strcspn(frase, "\n")] = '\0';
  for (int i = 0; i < strlen(frase); i++)
    frase[i] = tolower(frase[i]);
  int i = 0, linha = 0, j = 0;
  while (i < strlen(frase)) {
    if (frase[i] != ' ') {
      cpyfrase[linha][j] = frase[i];
      j++;
    } else {
      cpyfrase[linha][i] = '\0';
      linha++;
      j = 0;
    }
    i++;
  }
  printf("\n");
  for (int m = 0; m <= linha; m++) {
    if (strcmp(cpyfrase[m], "teclado") == 0)
      strcat(cpyfrase[m], troca);
    else if (strcmp(cpyfrase[m], "teclado,") == 0) {
      cpyfrase[m][strcspn(cpyfrase[m], ",")] = '\0';
      strcat(cpyfrase[m], troca);
      strcat(cpyfrase[m], ",");
    }
    printf("%s ", cpyfrase[m]);
  }
}