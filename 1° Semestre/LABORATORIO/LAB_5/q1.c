#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char nome[100];
  printf("Informe um nome: ");
  fgets(nome, 100, stdin);
  nome[strlen(nome) - 1] = '\0';
  for (int i = 0; i < strlen(nome); i++)
    nome[i] = tolower(nome[i]);
  int comp;
  for (char i = 'a'; i <= 'z'; i++) {
    comp = 0;
    for (int j = 0; j < strlen(nome); j++) {
      if (i == nome[j])
        comp++;
    }
    if (comp != 0) {
      printf("%c = %d\n", i, comp);
    }
  }
}
