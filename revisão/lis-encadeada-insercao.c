#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void imprime_rec(celula *le)
{
    if (le->prox == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}

void insere_antes(celula *le, int x, int y)
{
    celula *p;
    for (p = le; p->prox != NULL && p->prox->dado != y; p = p->prox)
        ;
    insere_inicio(p, x);
}

int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    insere_inicio(le, 10);
    insere_inicio(le, 20);
    insere_inicio(le, 30);
    imprime_rec(le);

    int x, y;

    printf("Digite qual número quer inserir: ");
    scanf("%d", &x);
    printf("Antes de qual número queira inserir: ");
    scanf("%d", &y);
    insere_antes(le, x, y);
    printf("Inserido com sucesso!\n");
    imprime_rec(le);
    return 0;
}