#include "Biblioteca.hpp"
#include "Livro.hpp"
#include <iostream>
#include <istream>
#include <list>

void adicionar(Biblioteca *biblioteca){
    string nome, ISBN, titulo, data;
            Livro livro;
            Autor autor;
            cout << endl
                 << ":+==============================================+:" << endl;
            cout << endl
                 << "DIGITE-------------------------------------------" << endl;

            cout << "TITULO: ";
            getline(cin, titulo);

            cout << "ISBN: ";
            getline(cin, ISBN);

            cout << "AUTOR: ";
            getline(cin, nome);

            cout << "DATA DE NASCIMENTO DO AUTOR: ";
            getline(cin, data);

            cout << endl
                 << ":+==============================================+:" << endl;

            autor.setNome(nome);
            autor.setDataNascimento(data);

            livro.setTitulo(titulo);
            livro.setISBN(ISBN);
            livro.setAutor(autor);

            biblioteca->adicionarLivro(livro);

}

void buscar(Biblioteca *biblioteca){
     if (!biblioteca->verificar())
            {
                string titulo, nome;

                cout << endl
                     << ":+==============================================+:" << endl;
                cout << endl
                     << "DIGITE--------------------------------------------" << endl;

                cout << "TITULO: ";
                getline(cin, titulo);

                cout << "AUTOR: ";
                getline(cin, nome);

                cout << endl
                     << ":+----------------------------------------------+:" << endl;

                Livro livro = biblioteca->buscarLivro(titulo, nome);

                if (!livro.getTitulo().empty())
                {
                    cout << "TITULO: " << livro.getTitulo()<<endl;
                    cout << "ISBN: " << livro.getISBN()<<endl;
                    cout << "AUTOR: " << livro.getAutor().getNome()<<endl;
                    cout << "DATA DE NASCIMENTO DO AUTOR: " << livro.getAutor().getDataNascimento();
                }
                else
                    cout << "Livro não encontrado: TENTE NOVALMENTE!";
                cout << endl
                     << ":+==============================================+:" << endl;
            }

            else
                cout << endl
                     << "Nenhum livro cadastrdao!" << endl;

}

int main(int argc, char const *argv[])
{
    Biblioteca * biblioteca = new Biblioteca();

    do
    {
        int opcao;
        cout << "\n1 - ADICIONAR LIVRO\n2 - BUSCAR LIVRO\n3 - MOSTRAR TODOS OS LIVROS\n4 - SAIR" << endl;
        do
        {
            cout << endl
                 << "ESCOLHE UMA OPÇÃO:";
            cin >> opcao;
        } while (opcao < 1 || opcao > 4);

        cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            adicionar(biblioteca);
            break;
        }

        case 2:
        {
           buscar(biblioteca);
            break;
        }

        case 3:
        {
            if (!biblioteca->verificar())
                biblioteca->mostrarLivros();
            else
                cout << endl
                     << "Nenhum livro cadastrdao!" << endl;
            break;
        }

        default:
            return 0;
            break;
        }
    } while (1);
}
