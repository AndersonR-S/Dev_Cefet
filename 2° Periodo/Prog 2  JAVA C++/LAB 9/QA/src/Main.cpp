#include <iostream>
#include <stdexcept>
#include <limits>
#include "FilaBanco.hpp"

using namespace std;
void inserir(FilaBanco *fila){
    cin.ignore();
    string nome, cpf, agencia, conta;
    cout<<endl<<"Adicionando Cliente...."<<endl;

   cout << "Nome: ";
   getline(cin, nome);
   cout<<"Cpf: ";
   getline(cin, cpf);
   cout<<"Agencia: ";
   getline(cin,agencia);
   cout<<"Conta: ";
   getline(cin, conta);

    fila->enqueue(new ClienteBanco(nome, cpf, agencia, conta));
   
}

void inserirPrioridade(FilaBanco *fila){
    cin.ignore();
    string nome, cpf, agencia, conta;
    cout<<endl<<"Adicionando Cliente com Prioridade...."<<endl;

   cout << "Nome: ";
   getline(cin, nome);
   cout<<"Cpf: ";
   getline(cin, cpf);
   cout<<"Agencia: ";
   getline(cin,agencia);
   cout<<"Conta: ";
   getline(cin, conta);

    fila->enqueuePriority(new ClienteBanco(nome, cpf, agencia, conta));
   
}

int main() {
    FilaBanco *fila = new FilaBanco();

    while (true) {
        int opcao = 0;
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Adicionar Cliente" << endl;
        cout << "2. Adicionar Cliente - Atendimento Prioritário" << endl;
        cout << "3. Remover" << endl;
        cout << "4. Listar Fila" << endl;
        cout << "5. Checar Se a fila Está Vazia" << endl;
        cout << "6. Sair" << endl;
        cout << "-----------------------------------" << endl;

        while (opcao < 1 || opcao > 6) {
            cout << "Digite um Número: ";
            cin >> opcao;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                opcao = 0;
            }
        }

        cout << "-----------------------------------------------------" << endl;

        switch (opcao) {
            case 1:
                inserir(fila);
                break;
            case 2:
                inserirPrioridade(fila);
                break;
            case 3:
                fila->dequeue();
                break;
            case 4:
                 fila->printQueue();
                break;
        case 5:
               cout <<endl<< "A fila está vazia? " << (fila->isEmpty() ? "Sim" : "Não") << endl;
               break;             
            case 6:
                exit(0);
                break;
        }
    }

    return 0;
}
