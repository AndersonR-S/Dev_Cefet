#include "PilhaProvas.hpp"
#include <limits>
void empilhar(PilhaProvas *pilha){
    string nome, curso, disciplina, codigoDaProva;
    int idade, numeroDeMatricula;
    float nota;

    cout<<endl<<"Adicionando Prova......"<<endl<<endl;

    cout<<"Nome: ";
    getline(cin,nome);

    while(true){
        cout<<"Idade: ";
        cin>>idade;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         else{
            cin.ignore();
            break;
         }   
    }

    cout<<"Curso: ";
    getline(cin, curso);


    while(true){
        cout<<"Numero de Matricula: ";
        cin>>numeroDeMatricula;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         else{
            cin.ignore();
            break;
         }   
    }    


    cout<<"Diciplina: ";
    getline(cin, disciplina);

    cout<<"Código da Prova: ";
    getline(cin,codigoDaProva);

    while(true){
        cout<<"Nota: ";
        cin>>nota;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         else{
            cin.ignore();
            break;
         }   
    }    


    pilha->push(new Prova(disciplina,codigoDaProva,nota,new Aluno(nome,idade, curso, numeroDeMatricula)));


}

int main(){
    PilhaProvas *pilha = new PilhaProvas();
    while(true){
        char opcao;
        int controlador = 1;
        cout<<"-------------------------------------------------"<<endl<<endl;
        cout<<"A. Empilhar provas"<<endl;
        cout<<"B. Desempilhar provas"<<endl;
        cout<<"C. Visualizar a prova no topo"<<endl;
        cout<<"D. Verificar se a pilha de provas está vazia"<<endl;
        cout<<"E. Sair"<<endl;

        cout<<endl<<"------------------------"<<endl<<endl;

        while(controlador){
            cout<<"Escolhe uma Opção: ";
            cin>>opcao;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
            switch(opcao){
                case 'A':
                case 'a':{
                    cout<<endl<<"--------------"<<endl;
                    empilhar(pilha);
                    controlador = 0;
                    break;
                }
                case 'B':
                case 'b':{
                    cout<<endl<<"--------------"<<endl;
                    pilha->pop();
                    controlador = 0;
                    break;
                }
                case 'C':
                case 'c':{
                    cout<<endl<<"--------------"<<endl;
                    pilha->top();
                    controlador = 0;
                    break;                    
                }
                case 'D':
                case 'd':{
                    cout<<endl<<"--------------"<<endl<<endl;
                    cout<<"A pilha de provas está vazia? "<<(pilha->isEmpty()?"Sim":"Não")<<endl<<endl;
                    controlador = 0;
                    break;                    
                }
                case 'E':
                case 'e':{
                    delete pilha;
                    cout<<endl<<"Saindo:...."<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
