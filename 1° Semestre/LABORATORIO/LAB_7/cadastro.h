#ifndef CADASTRO_H
#define CADASTRO_H
#define TAM 100

typedef struct cdt {
    char nome[50];
    char endereco[60];
    char telefone[15];
    int idade;
    char cpf[15];
} Cadastro;

int carregar_cadastro(Cadastro *pessoas);
void novo_cadastro(Cadastro *pessoas, int *quantidade);
void exibir_cadastro(Cadastro *pessoas, int *quantidade);
void excluir_cadastro(Cadastro *pessoas, int *quantidade);
void alterar_cadastro(Cadastro *pessoas, int *quantidade);
void salvar_cadastro(Cadastro *pessoas);


#endif