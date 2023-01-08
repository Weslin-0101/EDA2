#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Item unsigned
#define min(a, b) (a < b ? a : b)
#define menor(a, b) (a < b)
#define troca(a, b) \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define comparaTroca(a, b) \
    if (menor(b, a))       \
    troca(a, b)

int separa(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;
    for (int k = l; k < r; k++)
    {
        if (menor(v[k], pivo))
        {
            troca(v[k], v[j]);
            j++;
        }
    }
    troca(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 32)
        return;

    troca(v[(l + r) / 2], v[r - 1]);
    comparaTroca(v[l], v[r - 1]);
    comparaTroca(v[l], v[r]);
    comparaTroca(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionSort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item tmp = v[i];
        for (j = i; j > 0 && menor(tmp, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = tmp;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionSort(v, l, r);
}

void quickselect(Item *v, int l, int r, int i)
{
    if (i < l || i > r)
        return;

    comparaTroca(v[(l + r) / 2], v[r]);
    comparaTroca(v[l], v[(l + r) / 2]);
    comparaTroca(v[r], v[(l + r) / 2]);

    int m = separa(v, l, r);
    if (m > i)
        quickselect(v, l, m - 1, i);
    else if (m < i)
        quickselect(v, m + 1, r, i);
}

int main()
{
    int prod, pag, qprod;
    scanf(" %d %d %d", &prod, &pag, &qprod);
    unsigned *v = malloc(prod * sizeof(unsigned));

    for (int i = 0; i < prod; i++)
        scanf(" %u", v + i);

    quickselect(v, 0, prod - 1, min(prod - 1, pag * qprod));
    quickselect(v, 0, prod - 1, min(prod - 1, (pag + 1) * qprod - 1));
    quicksort(v, min(prod - 1, pag * qprod), min(prod - 1, (pag + 1) * qprod - 1));

    for (int i = pag * qprod; i < min(prod, (pag + 1) * qprod); i++)
        printf("%u\n", v[i]);

    return 0;
}