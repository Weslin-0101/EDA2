#include <stdio.h>

int main()
{

    int numeros[1001];
    int cont = 0, aux = 0;

    while (scanf("%d", &numeros[cont]) != EOF)
    {
        cont++;
    }

    for (int contador = 1; contador < cont; contador++)
    {
        for (int i = 0; i < cont - 1; i++)
        {
            if (numeros[i] > numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }

    for (int i = 0; i < cont; i++)
    {
        if (i == cont - 1)
            printf("%d\n", numeros[i]);
        else
            printf("%d ", numeros[i]);
    }

    return 0;
}