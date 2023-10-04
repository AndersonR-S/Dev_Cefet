#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no
{
    char *nome;
    char *ISBN;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criaLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}
void inserir_inicio(Lista *lista, char *Nome, char *isbn)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->nome = Nome;
        novo->ISBN = isbn;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
        printf("\nLIVRO SALVO:\n");
        printf("NOME: %s\tISBN: %s\n", novo->nome, novo->ISBN);
        printf("QUANTIDADE DE LIVROS SALVOS: %d \n\n", lista->tam);
    }
    else
        printf("Erro na alocar memoria!\n");
}
No *retirando(Lista lista, char *isbn)
{
    No *retirar = retirar = lista.inicio;
    No *remover = (No *)malloc(sizeof(No));

    if (strcmp(retirar->ISBN, isbn) == 0) // excluindo quando é o primeiro da lista
    {
        remover = retirar->proximo;
        retirar = remover;
    }

    else
    { // excluindo quando não for o primeiro
        while (retirar->proximo != NULL && strcmp(retirar->proximo->ISBN, isbn) != 0)
            retirar = retirar->proximo;

        if (retirar->proximo)
        {
            remover = retirar->proximo;
            retirar->proximo = remover->proximo;
        }
        else
        {
            printf("\nLivro inexistente\n");
            return retirar;
        }
    }

    if (!retirar)
    { // quando o ultimo elemento for NULL, fiz isso para não imprimir os printf abaixo
        lista.tam--;
        return retirar;
    }

    lista.tam--;
    printf("\n\nLIVRO RETIRADO:\n");
    printf("NOME: %s\tISBN,: %s\n", remover->nome, remover->ISBN);
    printf("RESTANTE: %d\n\n", lista.tam);

    return retirar;
}
int estaVazia(Lista *lista)
{
    return (lista->inicio == NULL);
}

int main()
{
    Lista livro;
    criaLista(&livro);
    while (1)
    {
        int num;
        printf("\n\n0 - Sair\n1 - Inserir Livro\n2 - Retirar Livro\n3 - Ver se esta vazio\n4 - Mostra o livro do Topo\n");

        do
        {
            printf("\nEscolhe uma opcao: ");
            scanf("%d", &num);
            getchar();
        } while (num < 0 && num > 4);
        switch (num)
        {
        case 1:
        {
            char *nome = (char *)malloc(sizeof(char) * 50);
            char *isbn = (char *)malloc(sizeof(char) * 10);
            printf("\nNOME: ");
            fgets(nome, 50, stdin);
            printf("ISBN: ");
            fgets(isbn, 10, stdin);
            nome[strlen(nome) - 1] = '\0';
            isbn[strlen(isbn) - 1] = '\0';

            inserir_inicio(&livro, nome, isbn);
            printf("\n\n");
            break;
        }
        case 2:
        {

            if (estaVazia(&livro))
                printf("\nNao tem LIVROS NA PILHA\n");
            else
            {
                char *isbn = (char *)malloc(sizeof(char) * 10);
                printf("ISBN: ");
                fgets(isbn, 10, stdin);
                isbn[strlen(isbn) - 1] = '\0';

                livro.inicio=retirando(livro, isbn);
            }

            break;
        }
        case 3:
        {
            if (estaVazia(&livro))
                printf("\nNao tem LIVROS NA PILHA\n");
            else
                printf("\nA quantidade de livros na pilha : %d\n", livro.tam);

            break;
        }
        case 4:
        {
            if (estaVazia(&livro))
                printf("Nao tem LIVROS NA PILHA\n");
            else
            {   No * no = livro.inicio;
                printf("\nO LIVRO QUE ESTA NO TOPO:\n");
                printf("%s\nISBN: %s\n", no->nome, no->ISBN);
                //free(no);
            }

            break;
        }
        case 0:
            return 0;
            break;
        }
    }
}