#include "FilaBanco.hpp"

FilaBanco::FilaBanco(){
    Fila = new No();
    Fila = nullptr;

    cauda = Fila;
    quantidade = 0;
} 
void FilaBanco::enqueue(ClienteBanco *_dado){
    No* no = new No(_dado, false);

    if(isEmpty()){
        Fila = no;
        cauda = no;
    }
    else{
        cauda->_setProximo(no);
        cauda = no;
    }

    cout<<endl<<endl<<"Cliente Adicionado"<<endl<<endl;
    _dado->print();
    cout<<endl<<"Quantidade de pessoas na frente: "<< quantidade;
    cout<<endl<<endl;

    quantidade++;
}

void FilaBanco::enqueuePriority(ClienteBanco *_dado){
    No* no = new No(_dado, true);
    int tam = 0;
    if(isEmpty()){
        Fila = no;
        cauda = no;
    }
    else if(!Fila->_getPrioridade()){
        no->_setProximo(Fila);
        Fila = no;
    }
    else{
        No *aux = Fila;
        tam++;
        while (aux->_getProximo() != nullptr && aux->_getProximo()->_getPrioridade() == true) {
            aux = aux->_getProximo();
            tam++;
        }
        
        no->_setProximo(aux->_getProximo());
        aux->_setProximo(no);
 
   
        if(aux == cauda)
            cauda = aux;
    }
    quantidade ++;

    cout<<endl<<endl<<"Cliente Adicionado"<<endl<<endl;
    _dado->print();
    cout<<endl<<"Quantidade de pessoas na frente: "<< tam;
    cout<<endl<<endl;
}

bool FilaBanco::isEmpty(){
    return Fila == nullptr;
}

void FilaBanco::printQueue(){
    cout <<endl<<"**Imprimindo Fila...**"<<endl<<endl;
    No* c = Fila;
    if(FilaBanco::isEmpty())
        cout <<endl<<"A lista esta Vazia"<<endl;
    else{
        int num = 1;
        while(c) 
        {
            cout<< num <<" ........"<<endl;
            c->_getDado()->print();
            cout << endl<< endl;;

            c = c->_getProximo();
            num++;
        }
    }
}

void FilaBanco::dequeue(){
    cout<< endl<<"Removendo da Fila...."<<endl<<endl;
    if(isEmpty()){
        cout<<"Fila esta Vazia"<<endl;
    }
    else{
        No *aux;
        if(Fila->_getProximo()==nullptr){
            aux = Fila;
            Fila = nullptr;
            cauda = nullptr;
        }
        else{
            aux = Fila;
            Fila = Fila->_getProximo();
        }
        quantidade--;

        aux->_getDado()->_print();
        cout<<"Restante na fila: "<<quantidade<<endl;

        delete aux;
    }
}