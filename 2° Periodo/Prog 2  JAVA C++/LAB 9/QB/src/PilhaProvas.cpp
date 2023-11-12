#include "PilhaProvas.hpp"

PilhaProvas::PilhaProvas(){
    Inicio = new No();
    Inicio = nullptr;
    Final = Inicio;
    quantidade = 0;
}

void PilhaProvas::push(Prova *prova){
    No* no= new No(prova);
    if(isEmpty()){
        Inicio = no;
        Final = no;
    }
    else{
        no->setProximo(Inicio);
        Inicio = no;
    }
    quantidade++;
    cout<<endl;
    cout<<"## Adicionado:"<<endl<<endl;
    no->getProva()->print();
    cout<<endl<<"Número de provas na Pilha: "<<quantidade<<endl<<endl;
}

void PilhaProvas::pop(){
    if(isEmpty()){
        cout<<endl<<"Pilha de Provas está Vazia"<<endl<<endl;
    }
    else{
        No *aux;
        if(Inicio->getProximo()==nullptr){
            aux = Inicio;
            Inicio = nullptr;
            Final = nullptr;
        }
        else{
            aux = Inicio;
            Inicio = Inicio->getProximo();
        }
        quantidade--;

        cout<<endl<<"## Prova Retitada..."<<endl<<endl;
        aux->getProva()->print();

        cout<<endl<<endl<<"## Provas Restantes..."<<endl;
        aux= aux->getProximo();
        while(aux) {
            cout<<endl;
            aux->getProva()->print();
            cout << endl;
            aux= aux->getProximo();
        }
        if(isEmpty()){
            cout<<endl<<"Nenhuma"<<endl<<endl;
        }

        delete aux;
    }
}

void PilhaProvas::top(){
    if(isEmpty()){
        cout<<endl<<"Pilha de Provas está Vazia"<<endl<<endl;
    }
    else{
        cout<<endl;
        Inicio->getProva()->print();
        cout<<endl;
    }
}

bool PilhaProvas::isEmpty(){
    return Inicio == nullptr;
}
