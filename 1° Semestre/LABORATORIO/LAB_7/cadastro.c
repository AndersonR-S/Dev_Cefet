#include <stdio.h>
#include <string.h>
#include "cadastro.h"

int carregar_cadastro(Cadastro *pessoa)
{
  FILE *arquivo = fopen("lista_cadstro.dat", "rb");
  if (arquivo == NULL)
  {
    printf("\nArquivo não encontrado.\n");
    return 0;
  }
  int quantidade = fread(pessoa, sizeof(Cadastro), TAM, arquivo);
  fclose(arquivo);
  return quantidade;
}
void novo_cadastro(Cadastro *pessoas, int *quantidade)
{
  if (quantidade <= TAM)
  {
    printf("O limite de pessoas foi atingido.\n");
    return;
  }
  for (int i = quantidade; i < TAM; i++)
  {
    printf("Digite o nome: ");
    fgets(pessoas[i].nome, 50, stdin);
    pessoas[i].nome[strlen(pessoas[i].nome) - 1] = '\0';

    printf("Digite o endereço: ");
    fgets(pessoas[i].endereco, 60, stdin);
    pessoas[i].endereco[strlen(pessoas[i].endereco) - 1] = '\0';

    printf("Digite o telefone: ");
    fgets(pessoas[i].telefone, 15, stdin);
    pessoas[i].telefone[strlen(pessoas[i].telefone) - 1] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &pessoas[i].idade);

    printf("Digite o CPF: ");
    fgets(pessoas[i].cpf, 15, stdin);
    pessoas[i].cpf[strlen(pessoas[i].cpf) - 1] = '\0';

    printf("Pessoa cadastrada com sucesso!\n");
    *quantidade = i;
    return;
  }
}
void exibir_cadastro(Cadastro *pessoas, int quantidade)
{
  if (quantidade == 0)
  {
    printf("Nenhuma pessoa cadastrada.\n");
    return;
  }
  printf("Lista de pessoas cadastradas:\n");

  for (int i = 0; i < quantidade; i++)
  {
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Endereco: %s\n", pessoas[i].endereco);
    printf("Telefone: %s\n", pessoas[i].telefone);
    printf("Idade: %i\n", pessoas[i].idade);
    printf("CPF: %s\n", pessoas[i].cpf);
    printf("\n------------------------------\n\n");
  }
}
void excluir_cadastro(Cadastro *pessoas, int quantidade)
{
  if (quantidade == 0)
  {
    printf("Nenhuma pessoa cadastrada.\n");
    return;
  }

  char cpf[15];

  printf("Digite o CPF da pessoa que deseja excluir: ");
  fgets(cpf, 15, stdin);
  cpf[strlen(cpf) - 1] = '\0';

  for (int i = 0; i < quantidade; i++)
    if (strcmp(pessoas[i].cpf, cpf) == 0)
    {
      pessoas[i] = (Cadastro){0};
      printf("Excluído com sucesso!\n");
      return;
    }
  printf("Pessoa não encontrada.\n");
}
void alterar_cadastro(Cadastro *pessoas, int quantidade)
{
  if (quantidade == 0)
  {
    printf("Nenhuma pessoa cadastrada.\n");
    return;
  }
  char cpf[15];
  int i;

  printf("Digite o CPF da pessoa que deseja alterar: ");
  fgets(cpf, 15, stdin);
  cpf[strlen(cpf) - 1] = '\0';

  for (i = 0; i < quantidade; i++)
    if (strcmp(pessoas[i].cpf, cpf) == 0)
    {
      printf("Digite o nome: ");
      fgets(pessoas[i].nome, 50, stdin);
      pessoas[i].nome[strlen(pessoas[i].nome) - 1] = '\0';

      printf("Digite o endereço: ");
      fgets(pessoas[i].endereco, 60, stdin);
      pessoas[i].endereco[strlen(pessoas[i].endereco) - 1] = '\0';

      printf("Digite o telefone: ");
      fgets(pessoas[i].telefone, 15, stdin);
      pessoas[i].telefone[strlen(pessoas[i].telefone) - 1] = '\0';

      printf("Digite a idade: ");
      scanf("%d", &pessoas[i].idade);

      printf("Digite o CPF: ");
      fgets(pessoas[i].cpf, 15, stdin);
      pessoas[i].cpf[strlen(pessoas[i].cpf) - 1] = '\0';

      printf("Alterado com sucesso!\n");
      return;
    }

  printf("Pessoa não encontrada.\n");
}
void salvar_cadastro(Cadastro *pessoas)
{
  FILE *arquivo=arquivo = fopen("lista_cadstro.dat", "wb");
  if (arquivo == NULL)
  {
    printf("Erro de alterar ou abrir arquivo.\n");
    return;
  }

  fwrite(pessoas, sizeof(pessoas), TAM, arquivo);

  fclose(arquivo);
}
