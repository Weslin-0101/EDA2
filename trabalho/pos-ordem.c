#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha
{
    no *item;
    struct pilha *prox;
} pilha;

void push(pilha **topo, no *item)
{
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->item = item;
    novo->prox = *topo;
    *topo = novo;
}

no *pop(pilha **topo)
{
    no *item = (*topo)->item;
    pilha *aux = *topo;
    *topo = (*topo)->prox;
    free(aux);
    return item;
}

void pos_ordem(no *raiz)
{
    if (raiz == NULL)
        return;

    pilha *pilha1 = NULL;
    pilha *pilha2 = NULL;
    push(&pilha1, raiz);

    while (pilha1 != NULL)
    {
        no *atual = pop(&pilha1);
        push(&pilha2, atual);

        if (atual->esq != NULL)
            push(&pilha1, atual->esq);
        if (atual->dir != NULL)
            push(&pilha1, atual->dir);
    }

    while (pilha2 != NULL)
    {
        no *atual = pop(&pilha2);
        printf("%d ", atual->dado);
    }
}

/*
int main()
{
    // Exemplo de uso
    no *raiz = (no *)malloc(sizeof(no));
    no *no5 = (no *)malloc(sizeof(no));
    no *no3 = (no *)malloc(sizeof(no));
    no *no8 = (no *)malloc(sizeof(no));
    no *no4 = (no *)malloc(sizeof(no));
    no *no7 = (no *)malloc(sizeof(no));
    no *no1 = (no *)malloc(sizeof(no));
    no *no6 = (no *)malloc(sizeof(no));
    no *no9 = (no *)malloc(sizeof(no));

    raiz->dado = 2;
    raiz->esq = no5;
    raiz->dir = no7;

    no5->dado = 5;
    no5->esq = no3;
    no5->dir = no8;

    no3->dado = 3;
    no3->esq = NULL;
    no3->dir = NULL;

    no8->dado = 8;
    no8->esq = no4;
    no8->dir = NULL;

    no4->dado = 4;
    no4->esq = NULL;
    no4->dir = NULL;

    no7->dado = 7;
    no7->esq = no1;
    no7->dir = no6;

    no1->dado = 1;
    no1->esq = NULL;
    no1->dir = no9;

    no6->dado = 6;
    no6->esq = NULL;
    no6->dir = NULL;

    no9->dado = 9;
    no9->esq = NULL;
    no9->dir = NULL;

    pos_ordem(raiz);

    return 0;
}
*/
