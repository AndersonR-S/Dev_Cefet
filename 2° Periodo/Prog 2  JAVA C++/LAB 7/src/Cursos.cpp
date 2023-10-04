#include "Curso.hpp"
void Curso::cadastrarProfessor()
{
    cin.ignore();
    string nome, endereco, titulado, curso;
    int masp;
    cout << endl
         << "-----PROFESSOR-----" << endl;
    cout << "Digite o Nome:";
    getline(cin, nome);
    cout << "Digite o Endereço:";
    getline(cin, endereco);
    cout << "Digite o Titulado:";
    getline(cin, titulado);
    cout << "Digite o Curso:";
    getline(cin, curso);
    cout << "Digite o MASP:";
    cin >> masp;
    cout << "-------------------" << endl;

    Professor professor(titulado, curso, nome, endereco, masp);
    professores.push_back(professor);
}

void Curso::cadastrarAluno()
{
    cin.ignore();
    string nome, endereco;
    int matricula;
    cout << endl
         << "-------ALUNO-------" << endl;
    cout << "Digite o Nome:";
    getline(cin, nome);
    cout << "Digite o Endereço:";
    getline(cin, endereco);
    cout << "Digite o Matricula:";
    cin >> matricula;
    cout << "-------------------" << endl;

    Aluno aluno(matricula, nome, endereco);
    this->alunos.push_back(aluno);
}
void Curso::cadastrarDisciplina()
{
    string nomeDiciplina;
    int masp, ch;
    Professor professor;
    cout << endl
         << "-----DICIPLINA-----" << endl;
    cout << "Digite o Masp do Professor:";
    cin >> masp;

    for (auto i : this->professores)
        if (i.getMasp() == masp)
            professor = i;
    if (professor.getMasp() < 0)
    {
        cout << endl
             << "Professor não cadastrado" << endl;
        return;
    }

    cout << "Digite o CH:";
    cin >> ch;
    cin.ignore();
    cout << "Digite o nome do Diciplina:";
    getline(cin, nomeDiciplina);
    cout << "-------------------" << endl;

    Diciplina diciplina(nomeDiciplina, ch, professor);
    this->diciplinas.push_back(diciplina);
}
void Curso::imprimirListaDeProfessor()
{
    if(this->professores.empty()){
        cout<<endl<<"Nenhum Professor cadastrado"<<endl;
        return;
    }
    cout << "-------------------" << endl;
    for (auto i : this->professores)
    {
        cout << endl;
        i.print();
        cout << endl;
    }
    cout << "-------------------" << endl;
}
void Curso::imprimirListaDeAlunos()
{      
    if(this->alunos.empty()){
        cout<<endl<<"Nenhum Aluno cadastrado"<<endl;
        return;
    }
    cout << "-------------------" << endl;
    for (auto i : this->alunos)
    {
        cout << endl;
        i.print();
        cout << endl;
    }
   cout << "-------------------" << endl;

}
void Curso::imprimirListaDeDiciplinas()
{
    if(this->diciplinas.empty()){
        cout<<endl<<"Nenhuma Diciplina cadastrado"<<endl;
        return;
    }

    cout << "-------------------" << endl;
    for (auto i : this->diciplinas)
    {
        cout << endl;
        i.print();
        cout << endl;
    }
    cout << "-------------------" << endl;

}
