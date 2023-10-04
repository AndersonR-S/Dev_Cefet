#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string texto = "";
    string caracter = "*_";
    int aux, aux1;
    aux = aux1 = 0;

    // int contagem = 0;

    ifstream file("entrada.txt");

    if (!file)
    {
        cout << "Erro ao abrir o arquivo de entrada";
        return 0;
    }
    char c;

    while (file.get(c))
    {
        if (caracter[0] == c && aux == 0)
        {
            if (aux1 == 0)
            {
                aux1++;
                texto += "<b>";
            }
            else
            {
                aux1--;
                texto += "</b>";
            }
        }
        else if (caracter[1] == c && aux1 == 0)
        {
            if (aux == 0)
            {
                aux++;
                texto += "<i>";
            }
            else
            {
                aux--;
                texto += "</i>";
            }
        }

        else if (isspace(c) || isalpha(c) || ispunct(c))
        {
            // contagem++;
            texto += c;
        }

        /*if (iscntrl(c + (c++)))
            contagem = 0;*/
    }
    file.close();
    ofstream infile("saida.txt");
    if (!infile)
    {
        cout << "Erro em abrir o arquivo de saida";
        return 0;
    }

    infile << texto;
    
    infile.close();
}