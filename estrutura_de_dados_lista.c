#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
} Nodo;

void incluir(Nodo **inicio, int valor)
{
    Nodo *novo;

    novo = malloc(sizeof(Nodo));

    novo->info = valor;

    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
}

void consultar(Nodo *inicio, int valor)


{
    Nodo *atual;

    atual = inicio;

    while (atual != NULL)
    {
        if (atual->info == valor)
        {
            printf("Valor encontrado!\n");
            return;
        }

        atual = atual->prox;
    }

    printf("Valor nao encontrado!\n");
}

void listar(Nodo *inicio)
{
    Nodo *atual;

    atual = inicio;

    while (atual != NULL)
    {
        printf("%d\n", atual->info);

        atual = atual->prox;
    }
}



int main() {

    Nodo *inicio = NULL;

    return 0;
}

