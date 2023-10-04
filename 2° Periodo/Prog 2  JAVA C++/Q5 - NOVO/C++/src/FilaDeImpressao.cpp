#include "FilaDeImpressao.hpp"  


FilaDeImpressao::FilaDeImpressao(){
    this->numeroDePessoa = 0;
    this->Fila = nullptr;
}

int FilaDeImpressao::getNumeroDePessoa(){
    return this->numeroDePessoa;
}
void FilaDeImpressao::adicionarDocumento(Documentos *docu){  
    if(this->Fila == nullptr)
        this->Fila = docu;
    else{
        Documentos *aux = this->Fila;
        Documentos *anterior = nullptr;

        while (aux != nullptr && docu->getPrioridade() < aux->getPrioridade()){
            anterior = aux;
            aux = aux->getProximo();
        }

        if(anterior==nullptr){
            docu->setInserirProximo(this->Fila);
            this->Fila = docu;
        }
        else {
            anterior->setInserirProximo(docu);
            docu->setInserirProximo(aux);
        }

        delete anterior;
        delete aux;
    }
    cout << "\nDocumento Cadastrado!! ID: " << docu->getId() << endl;
    this->numeroDePessoa++;
}
void FilaDeImpressao::listarDocumento(){

    Documentos *documento = this->Fila;

    while(documento != nullptr){
        cout<<endl<<endl<<"ID: "<< documento->getId()<<endl;
        cout<<"NOME DO ARQUIVO: "<<documento->getNomeArquivo()<<endl;
        cout<<"NUMERO DE PAGINAS: "<<documento->getNumeroPagina()<<endl;
        cout<<"PRIORIDADE: "<<documento->getPrioridade()<<endl;
        cout<<endl;
    
        documento = documento->getProximo();
    }

}

void FilaDeImpressao::consultarDocumento(int id){

    Documentos *aux = this->Fila;

    while(aux != nullptr){
        if(aux->getId() ==id ){
            cout<<"ID: "<< aux->getId()<<endl;
            cout<<"NOME DO ARQUIVO: "<<aux->getNomeArquivo()<<endl;
            cout<<"NUMERO DE PAGINAS: "<<aux->getNumeroPagina()<<endl;
            cout<<"PRIORIDADE: "<<aux->getPrioridade()<<endl;
            cout<<endl;  
        }
        aux= aux->getProximo();
    }

    if(aux == nullptr)
        cout<<"DOCUMENTO NÃO ENCONTRADO!!"<<endl;
}

void FilaDeImpressao::removerDocumento(int id){
    Documentos *aux = this->Fila;
    if(this->Fila->getId()==id)
        this->Fila = aux->getProximo();
    else{
        Documentos *anterior = aux;
        while(aux->getProximo()->getId()==id && aux != NULL){
            anterior = aux;
            aux = aux->getProximo();
        }
        
        if(aux){
            anterior->setInserirProximo(aux->getProximo()->getProximo());
            this->Fila = anterior;
        }
        else
            cout<<"\nDOCUEMNTO NÃO ENCONTRADO!";

        delete anterior;
        delete aux;
    }
    this->numeroDePessoa--;
}
    void alterarDocumento(int id);