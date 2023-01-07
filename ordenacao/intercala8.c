#include <stdio.h>
#include <stdlib.h>

void printarr(int *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", v[i], (i == n - 1 ? '\n' : ' '));
}

void merge(int *a, int sizea, int *b, int sizeb)
{
    int *temp = (int *)malloc((sizea + sizeb) * sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < sizea && j < sizeb; k++)
    {
        if (a[i] <= b[j])
            temp[k] = a[i++];
        else
            temp[k] = b[j++];
    }

    while (i < sizea)
        temp[k++] = a[i++];
    while (j < sizeb)
        temp[k++] = b[j++];

    for (k = 0, i = 0; i < (sizea + sizeb); i++, k++)
        a[i] = temp[k];

    free(temp);
}

int ans[800008], v[100001];

int main()
{
    int n = 0;
    for (int i = 0; i < 8; i++)
    {
        int vsize = 0;
        scanf(" %d", &vsize);
        for (int j = 0; j < vsize; j++)
            scanf(" %d", &v[j]);
        merge(ans, n, v, vsize);
        n += vsize;
    }

    printarr(ans, n);

    return 0;
}