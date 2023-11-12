#include "Aluno.hpp"
    
Aluno::Aluno(){}
Aluno::Aluno(string nome, int idade, string curso, int numeroMatricula): Pessoa(nome, idade){
    this->curso = curso;
    this->numeroMatricula = numeroMatricula;
}

void Aluno::print(){
    Pessoa::_print();
    cout<<"Curso: "<<curso<<endl;
    cout<<"Numero de Matricula: "<<numeroMatricula<<endl;

}