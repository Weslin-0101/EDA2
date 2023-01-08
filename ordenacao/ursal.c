#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define menor(a, b) (a.value == b.value ? a.key > b.key : a.value > b.value)
#define troca(a, b) \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define comparaTroca(a, b) \
    if (menor(a, b))       \
    troca(a, b)

typedef struct
{
    int key;
    int value;
} Item;

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

void quicksort(Item *v, int l, int r)
{
    if (r <= l)
        return;

    comparaTroca(v[(l + r) / 2], v[r]);
    comparaTroca(v[l], v[(l + r) / 2]);
    comparaTroca(v[r], v[(l + r) / 2]);

    int j = separa(v, l, r);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

// ps = presidente
// ss = senadores
// dfs = deputados federais
// des = deputados estaduais
Item ps[91], ss[901], dfs[9001], des[90001];
int pn = 0, sn = 0, dfn = 0, den = 0;

int main()
{
    long long senadores, federais, estaduais;
    scanf(" %lld %lld %lld", &senadores, &federais, &estaduais);

    long long valido = 0, invalido = 0, totalp = 0;
    for (int x, l; scanf("%d%n", &x, &l) == 1;)
    {
        if (x < 0)
        {
            invalido++;
            continue;
        }

        switch (l)
        {
        case 3:
            ps[x - 10].key = x;
            ps[x - 10].value++;
            totalp++;
            break;
        case 4:
            ss[x - 100].key = x;
            ss[x - 100].value++;
            break;
        case 5:
            dfs[x - 1000].key = x;
            dfs[x - 1000].value++;
            break;
        default:
            des[x - 10000].key = x;
            des[x - 10000].value++;
            break;
        }
        valido++;
    }

    for (int i = 0; i < 91; i++)
    {
        if (ps[i].value)
            ps[pn++] = ps[i];
    }
    for (int i = 0; i < 901; i++)
    {
        if (ss[i].value)
            ss[sn++] = ss[i];
    }
    for (int i = 0; i < 9001; i++)
    {
        if (dfs[i].value)
            dfs[dfn++] = dfs[i];
    }
    for (int i = 0; i < 90001; i++)
    {
        if (des[i].value)
            des[den++] = des[i];
    }

    printf("%lld %lld\n", valido, invalido);

    quicksort(ps, 0, pn - 1);
    quicksort(ss, 0, sn - 1);
    quicksort(dfs, 0, dfn - 1);
    quicksort(des, 0, den - 1);

    if ((double)ps[0].value / totalp >= .51)
        printf("%d\n", ps[0].key);
    else
        printf("Segundo turno\n");

    for (int i = 0; i < senadores; i++)
        printf("%d%c", ss[i].key, " \n"[i == senadores - 1]);
    for (int i = 0; i < federais; i++)
        printf("%d%c", dfs[i].key, " \n"[i == federais - 1]);
    for (int i = 0; i < estaduais; i++)
        printf("%d%c", des[i].key, " \n"[i == estaduais - 1]);

    return 0;
}