#include "Prova.hpp"

Prova::Prova(){}
Prova::Prova(string diciplina, string codigoDaProva, float Nota, Aluno *aluno){
    this->Disciplina = diciplina;
    this->CodigoDaProva=codigoDaProva;
    this->Nota = Nota;
    this->aluno = aluno;
}

void Prova::print(){
    aluno->print();
    cout<<"Discuplina: "<<Disciplina<<endl;
    cout<<"Codico da Prova: "<<CodigoDaProva<<endl;
    cout<<"Nota: "<<Nota<<endl;
}


