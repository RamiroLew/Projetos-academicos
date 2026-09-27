#include <stdio.h>
#include <stdlib.h>

// definindo a estrutura do Nodo (nó)
typedef struct Nodo {
    int valor;
    struct Nodo *prox;
} Nodo;

// função para incluir (inserir no final da lista)
void incluir(Nodo **inicio, int valor) {
    Nodo *novo = malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("\n[Erro] Memoria cheia!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo; // primeiro elemento da lista
    } else {
        Nodo *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox; // navega ate o ultimo nodo
        }
        atual->prox = novo; // conecta o novo nodo no final
    }
    printf("\nValor %d incluido com sucesso!\n", valor);
}

// função para consultar (buscar um valor na lista)
void consultar(Nodo *inicio, int valor) {
    Nodo *atual = inicio;
    int posicao = 1;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("\nValor %d encontrado na posicao %d.\n", valor, posicao);
            return;
        }
        atual = atual->prox;
        posicao++;
    }
    printf("\nValor %d nao encontrado na lista.\n", valor);
}

// função para alterar (trocar o valor de um nodo existente)
void alterar(Nodo *inicio, int valorAntigo, int valorNovo) {
    Nodo *atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valorAntigo) {
            atual->valor = valorNovo;
            printf("\nValor %d alterado com sucesso para %d!\n", valorAntigo, valorNovo);
            return;
        }
        atual = atual->prox;
    }
    printf("\nValor %d nao foi encontrado para alteracao.\n", valorAntigo);
}

// função para remover (excluir um elemento da lista)
void remover(Nodo **inicio, int valor) {
    Nodo *atual = *inicio;
    Nodo *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\nValor %d nao encontrado para remocao.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->prox; // o elemento a remover e o primeiro
    } else {
        anterior->prox = atual->prox; // pula o elemento a ser removido
    }

    free(atual); // libera o espaço de memória alocado
    printf("\nValor %d removido com sucesso!\n", valor);
}

// função para exibir todos os elementos da lista
void exibir(Nodo *inicio) {
    if (inicio == NULL) {
        printf("\nA lista esta vazia.\n");
        return;
    }

    Nodo *atual = inicio;
    printf("\nLista atual: ");
    while (atual != NULL) {
        printf("[%d] -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// função para çiberar a memória antes de fechar o programa
void liberarLista(Nodo **inicio) {
    Nodo *atual = *inicio;
    Nodo *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

int main() {
    Nodo *lista = NULL; // Lista inicia vazia
    int opcao, valor, novoValor;

    do {
        printf("\n=============================");
        printf("\n   LISTA SIMPLESMENTE ENCADEADA");
        printf("\n=============================");
        printf("\n1. Incluir elemento");
        printf("\n2. Consultar elemento");
        printf("\n3. Alterar elemento");
        printf("\n4. Remover elemento");
        printf("\n5. Exibir lista");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para incluir: ");
                scanf("%d", &valor);
                incluir(&lista, valor);
                break;
            case 2:
                printf("Digite o valor para consultar: ");
                scanf("%d", &valor);
                consultar(lista, valor);
                break;
            case 3:
                printf("Digite o valor atual a ser alterado: ");
                scanf("%d", &valor);
                printf("Digite o novo valor: ");
                scanf("%d", &novoValor);
                alterar(lista, valor, novoValor);
                break;
            case 4:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                remover(&lista, valor);
                break;
            case 5:
                exibir(lista);
                break;
            case 0:
                liberarLista(&lista);
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}