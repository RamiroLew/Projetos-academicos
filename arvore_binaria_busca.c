#include <stdio.h>
#include <stdlib.h>

typedef struct No { //criação da estrutura
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {    //criação do no na memoria
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("erro: memoria insuficiente.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {  //criação da estrutura da base da arvore
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        printf("valor %d ja existe na arvore. nao inserido.\n", valor);
    }

    return raiz;
}

No* encontrarMenor(No *raiz) { //estrutura para localizar No
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* remover(No *raiz, int valor) { //estrutura para remoção do No liberando da memoria
    if (raiz == NULL) {
        printf("Valor %d nao encontrado na arvore.\n", valor);
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No *sucessor = encontrarMenor(raiz->direita);
        raiz->valor = sucessor->valor;
        raiz->direita = remover(raiz->direita, sucessor->valor);
    }

    return raiz;
}

void preOrdem(No *raiz) { // impressão da pre ordem
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);  
    preOrdem(raiz->esquerda);     
    preOrdem(raiz->direita);     
}

void emOrdem(No *raiz) { // impressao em ordem
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);      
    printf("%d ", raiz->valor);  
    emOrdem(raiz->direita);       
}

void posOrdem(No *raiz) { 
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);     
    posOrdem(raiz->direita);    
    printf("%d ", raiz->valor);  
}

void liberarArvore(No *raiz) {  // liberação da memoria
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void imprimirPercurso(No *raiz, void (*funcaoPercurso)(No*), const char *nome) {
    printf("\n%s: ", nome);
    if (raiz == NULL) {
        printf("(arvore vazia)");
    } else {
        funcaoPercurso(raiz);
    }
    printf("\n");
}

int main() {
    No *raiz = NULL;  
    int opcao, valor;

    do {
        printf("\n* * * MENU DE OPCOES * * *\n");   //exibição do menu para aplicar as funções criadas
        printf("1. Incluir no.\n");
        printf("2. Remover no.\n");
        printf("3. Buscar pre-ordem.\n");
        printf("4. Buscar em ordem.\n");
        printf("5. Buscar pos-ordem.\n");
        printf("\nOpcao [0 para encerrar]: ");

        if (scanf("%d", &opcao) != 1) { 
            printf("dntrada invalida.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) { //case das funções
            case 1:
                printf("digite o valor a incluir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;

            case 2:
                printf("digite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;

            case 3:
                imprimirPercurso(raiz, preOrdem, "pre-ordem");
                break;

            case 4:
                imprimirPercurso(raiz, emOrdem, "em ordem");
                break;

            case 5:
                imprimirPercurso(raiz, posOrdem, "pos-ordem");
                break;

            case 0:
                printf("encerrando o programa...\n");
                break;

            default:
                printf("opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    liberarArvore(raiz); //liberação da memoria

    return 0;
}