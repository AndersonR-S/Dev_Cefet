#include "Documentos.hpp"
#include "FilaDeImpressao.hpp"
#include <iostream>

void adicionar(FilaDeImpressao *fila){
    string nomeArquivo;
    int id, numeroPagina, prioridade;
    Documentos *documento = new Documentos();

    cout<<endl<<endl<<"DIGITE O ID: ";
    cin>>id;
    cout<<"DIGITE A PRIORIDADE: ";
    cin>>prioridade;
    cout<<"DIGITE O NUMERO DE PAGINAS: ";
    cin>>numeroPagina;

    cin.clear();
    cin.get();
    cout<<"INFORME O NOME DO ARQUIVO: ";
    getline(cin,nomeArquivo);

    documento->setId(id);
    documento->setPrioridade(prioridade);
    documento->setNumeroPagina(numeroPagina);
    documento->setNomeArquivo(nomeArquivo);

    documento->setInserirProximo(nullptr);
    fila->adicionarDocumento(documento);
}

int main(){
FilaDeImpressao *fila = new FilaDeImpressao();
while(1){
    int opcao = 0;
    cout<<endl<<"1- CADASTRAR DOCUMENTO"<<endl;
    cout<<"2- MOSTRAR DOCUMENTOS"<<endl;
    cout<<"3- CONSULTAR DOCUMENTO"<<endl;
    cout<<"6- SAIR"<<endl;

    while(opcao<1 || opcao > 6){
        cout<<"ESCOLHE UMA OPCAO: ";
        cin>>opcao;
    }

    switch(opcao){
        case 1:{
            adicionar(fila);
            break;
        }
        case 2:{

            if(fila->getNumeroDePessoa()!=0){
                fila->listarDocumento();
                break;
            }
            else
                cout<<"\nNENHUM DOCUMENTO CADASTRADO!\n";
            break;
        }
        case 3:{

            if(fila->getNumeroDePessoa()!=0){
                int id;
                cout<<"\nINFORME O ID PARA CONSULTA: ";
                cin>>id;

                fila->consultarDocumento(id);
            }
            else
                cout<<"\nNENHUM DOCUMENTO CADASTRADO!\n";
            break;
        }
        case 6:
            return 1;
            break;

    }
}
return 0;
}
