#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    for (celula *p = le->prox; p != NULL; p = p->prox)
    {
        printf("%d -> ", p->dado);
    }

    printf("NULL\n");
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

int main()
{
    celula c1, c2, c3, c4, le;

    c1.dado = 1;
    c2.dado = 2;
    c3.dado = 3;
    c4.dado = 4;

    le.prox = &c1;
    c1.prox = &c2;
    c2.prox = &c3;
    c3.prox = &c4;
    c4.prox = NULL;

    imprime(&le);
    imprime_rec(&le);
    return 0;
}