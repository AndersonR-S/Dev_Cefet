#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int verificar_palindromo(char *string_frase, char *inverso, int i)
{
    if (string_frase[i] != inverso[i])
        return 0;
    else if (i == strlen(string_frase) - 1)
        return 1;
    else
        return verificar_palindromo(string_frase, inverso, i + 1);
}

int main()
{
    char frase[100];
    char string_frase[100];

    // Recebendo a frase e colocando tudo minusculo
    printf("\nDigite a palavra ou frase: ");
    fflush(stdin);
    fgets(frase, 100, stdin);

    frase[strcspn(frase, "\n")] = '\0';
    for (int i = 0; i < strlen(frase); i++)
        frase[i] = tolower(frase[i]);


    // Tirando os espaços da frase
    
    for (int i = 0, k = 0; i < strlen(frase); i++)
    {
        if (frase[i] != ' ')
        {
            string_frase[k] = frase[i];
            k++;
        }
    }

    // Bug do strrev
    string_frase[strcspn(string_frase, "'")] = '\0';

    // Chamando Função
    char *inversa = (char *)malloc(strlen(string_frase) * sizeof(int));

    strcpy(inversa, string_frase);
    strrev(inversa);

    // Outra alternativa para inverter a frase
    
  // int j=(strcspn(string_frase,"\0"));
  // for(int i=0; i<j; i++)
  //    inversa[j-i-1] = string_frase[i];
    


    int resultado = verificar_palindromo(string_frase, inversa, 0);
    if (resultado == 1)
        printf("\nA frase e palindromo\n\n");
    else
        printf("\nA frase nao e palindromo\n\n");

    return 0;
}
