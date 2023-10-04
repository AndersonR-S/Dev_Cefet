
#include <string>
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    string texto;
    string textoTrocado = "";
    string caracter = "*_";
    int aux, aux1;
    aux = aux1 = 0;
    char c;

    while (getline(cin, texto))
    {
        int tamanho = texto.length();

        for (int i = 0; i < tamanho; i++)
        {
            char c = texto[i];
            if (caracter[0] == texto[i])
            {
                if (aux1 == 0)
                {
                    aux1++;
                    textoTrocado += "<b>";
                }
                else
                {
                    aux1--;
                    textoTrocado += "</b>";
                }
            }
            else if (caracter[1] == texto[i] )
            {
                if (aux == 0)
                {
                    aux++;
                    textoTrocado += "<i>";
                }
                else
                {
                    aux--;
                    textoTrocado += "</i>";
                }
            }

            else if (isspace(texto[i]) || isalpha(texto[i]) || ispunct(texto[i]))
            {
                textoTrocado += texto[i];
            }
        }

        textoTrocado += "\n";
    }

    cout << textoTrocado;
    return 0;
}