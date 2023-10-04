#ifndef CURSO_HPP
#define CURSO_HPP
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Diciplina.hpp"
#include <list>

class Curso
{
private:
    string nome;
    list<Professor> professores;
    list<Aluno> alunos;
    list<Diciplina> diciplinas;

public:
    void cadastrarProfessor();
    void cadastrarAluno();
    void cadastrarDisciplina();
    void imprimirListaDeProfessor();
    void imprimirListaDeAlunos();
    void imprimirListaDeDiciplinas();
};

#endif