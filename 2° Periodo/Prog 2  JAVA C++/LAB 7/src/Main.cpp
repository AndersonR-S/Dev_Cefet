#include "Curso.hpp"
#include <iostream>

int main(){
    Curso curso;
    while(1){
        int opcao = 0;
        cout<<endl<<"1. Cadastrar Aluno";
        cout<<endl<<"2. Cadastrar Professor";
        cout<<endl<<"3. Cadastrar Diciplina";
        cout<<endl<<"4. Imprimir Aluno";
        cout<<endl<<"5. Imprimir Professor";
        cout<<endl<<"6. Imprimir Diciplina";
        cout<<endl<<"7. Sair";

        while(opcao < 1 || opcao > 7){
            cout<<endl<<endl<<"Escolhe uma opcao: ";
            cin>>opcao;
        }
        switch(opcao){
            case 1:
                curso.cadastrarAluno();
                break;
            case 2:
                curso.cadastrarProfessor();
                break;
            case 3:
                curso.cadastrarDisciplina();
                break;
            case 4:
                curso.imprimirListaDeAlunos();
                break;
            case 5:
                curso.imprimirListaDeProfessor();
                break;
            case 6:
                
                curso.imprimirListaDeDiciplinas();
                break;
            default:
                return 0;
                break;
        }
    }

}