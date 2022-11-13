#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x)
{
    for (celula *p = le->prox; p != NULL && p->dado != x; p = p->prox)
    {
    }
}

celula *busca_rec(celula *le, int x)
{
    if (le->prox == NULL)
    {
        return NULL;
    }
    else if (le->prox->dado == x)
    {
        return le->prox;
    }
    else
    {
        busca_rec(le->prox, x);
    }
}

int main()
{
    celula no1, no2, no3, le;
    no1.dado = 1;
    no2.dado = 2;
    no3.dado = 3;
    le.prox = &no1;
    no1.prox = &no2;
    no2.prox = &no3;
    no3.prox = NULL;
    celula *retorna = busca_rec(&le, 2);
    if (retorna == NULL)
    {
        printf("não achamo\n");
    }
    else
    {
        printf("Achamo fi, olha aqui o endereco: %p\n", retorna);
    }
    return 0;
}