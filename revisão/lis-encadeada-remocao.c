#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    celula *lixo = p->prox;
    if (lixo != NULL)
    {
        int y = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
        return y;
    }
}

int remove_elemento(celula *le, int x)
{
    celula *p;
    for (p = le; p->prox != NULL && p->prox->dado != x; p = p->prox)
        ;
    remove_depois(p);
}

int remove_todos_elementos(celula *le, int x)
{
    celula *p1, *p2;

    do
    {
        for (p1 = le; p1->prox != NULL && p1->prox->dado != x; p1 = p1->prox)
            ;
        p2 = p1->prox;
        remove_depois(p1);
    } while (p2 != NULL);
}

int main() {}