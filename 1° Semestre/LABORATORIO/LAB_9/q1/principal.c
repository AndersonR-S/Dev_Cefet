#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
	char *nome;
	char *cpf;
	struct no *proximo;
} No;

typedef struct
{
	No *inicio;
	int tam;
	// No *final;
} Lista;

void criaLista(Lista *lista)
{
	lista->inicio = NULL;
	lista->tam = 0;
}

void inserir_inicio(Lista *lista, char *Nome, char *Cpf)
{
	No *novo = (No *)malloc(sizeof(No));
	if (novo)
	{
		novo->nome = Nome;
		novo->cpf = Cpf;
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		printf("USUARIO CADASTRDO:\n");
		printf("NOME: %s\tCPF: %s\n", novo->nome, novo->cpf);
		printf("TEM %d RESTANTE\n\n", lista->tam);
		lista->tam++;
	}
	else
		printf("Erro na alocar memoria!\n");
}

void inserir_fim(Lista *lista, char *Nome, char *Cpf)
{
	No *aux, *novo = (No *)malloc(sizeof(No));
	if (novo)
	{
		novo->nome = Nome;
		novo->cpf = Cpf;
		novo->proximo = NULL;

		if (lista->inicio == NULL) // o primeiro da lista
			lista->inicio = novo;
		else
		{
			aux = lista->inicio;

			while (aux->proximo) // encontrando o final
				aux = aux->proximo;

			aux->proximo = novo;
			// lista->inicio = aux;
		}
		printf("\nUSUARIO CADASTRDO:\n");
		printf("NOME: %s\tCPF: %s\n", novo->nome, novo->cpf);
		printf("NA FRENTE: %d\n\n", lista->tam);
		lista->tam++;
	}
	else
		printf("Erro na alocar memoria!\n");
}

void imprimir(Lista lista)
{
	No *no = lista.inicio;
	printf("\nLISTA:\n");
	int i = 1;
	while (no)
	{
		printf("%d - %s\t%s\n", i, no->nome, no->cpf);
		no = no->proximo;
		i++;
	}
	printf("\n\n");

	/*for (int i = 1; no != NULL; no = no->proximo)
	{
		printf("%d - %s\t%s\n", i, no->nome, no->cpf);
		i++;
	}

	printf("\n\n");*/
}

int estaVazia(Lista *lista)
{
	return (lista->inicio == NULL);
}

No *retiraPessoa(Lista lista, char *Cpf)
{
	No *retirar = retirar = lista.inicio;
	No *remover = (No *)malloc(sizeof(No));

	if (strcmp(retirar->cpf, Cpf) == 0) // excluindo quando é o primeiro da lista
	{
		remover = retirar->proximo;
		retirar = remover;
	}

	else
	{ // excluindo quando não for o primeiro
		while (retirar->proximo != NULL && strcmp(retirar->proximo->cpf, Cpf) != 0)
			retirar = retirar->proximo;

		
	    if (retirar->proximo)
		{
			remover = retirar->proximo;
			retirar->proximo = remover->proximo;

		}
		else
		{
			printf("Pessoa inexistente\n");
			return retirar;
		}
	}

    if(!retirar){
		lista.tam--;
		return retirar;
	}
         
	lista.tam--;
	printf("\nUSUARIO RETIRADO:\n");
	printf("NOME: %s\tCPF: %s\n", remover->nome, remover->cpf);
	printf("RESTANTE: %d\n\n", lista.tam);

	return retirar;
}

int main()
{
	Lista lista;
	criaLista(&lista);
	while (1)
	{
		int num;
		printf("\n--------------------MENU PRINCIPAL--------------------\n\n");
		printf("1-Inserir pessoas\n2-Retirar pessoas\n3-Imprimir lista\n4-Verificar se esta vazia.\n5-Prioritario\n6-Sair");
		printf("\n------------------------------------------------------\n");
		do
		{
			printf("\nEscolhe uma opcao: ");
			scanf("%d", &num);
			getchar();

		} while (num < 1 || num > 6);
		switch (num)
		{
		case 1: // inserir
		{
			fflush(stdin);
			char *nome = (char *)malloc(sizeof(char) * 50);
			char *cpf = (char *)malloc(sizeof(char) * 15);
			printf("\nNOME: ");
			fgets(nome, 50, stdin);
			nome[strlen(nome) - 1] = '\0';
			printf("CPF: ");
			fgets(cpf, 15, stdin);
			cpf[strlen(cpf) - 1] = '\0';

			inserir_fim(&lista, nome, cpf);

			break;
		}

		case 2: // retirar
		{
			if (estaVazia(&lista))
				printf("Lista vazia\n");
			else
			{
				char *cpf = (char *)malloc(sizeof(char) * 15);
				printf("CPF: ");
				fgets(cpf, 15, stdin);
				cpf[strlen(cpf) - 1] = '\0';
				lista.inicio = retiraPessoa(lista, cpf);
				break;
			}
		}
		case 3: // mostrar lista
		{

			if (estaVazia(&lista))
				printf("Lista vazia\n");
			else
				imprimir(lista);

			break;
		}

		case 4: // verificar se esta vazio
		{
			if (estaVazia(&lista))
				printf("Lista vazia\n");
			else
				printf("Nao esta vazia\n");
			break;
		}

		case 5: // preferencial
		{

			fflush(stdin);
			char *nome = (char *)malloc(sizeof(char) * 50);
			char *cpf = (char *)malloc(sizeof(char) * 15);
			printf("\nNOME: ");
			fgets(nome, 50, stdin);
			nome[strlen(nome) - 1] = '\0';
			printf("CPF: ");
			fgets(cpf, 15, stdin);
			cpf[strlen(cpf) - 1] = '\0';

			inserir_inicio(&lista, nome, cpf);

			break;
		}
		case 6:
		{
			exit(1);
			break;
		}
		}
	}
}