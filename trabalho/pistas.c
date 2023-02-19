#include <stdio.h>
#include <stdlib.h>

#define MAX_PISTAS 5000

typedef struct Pista
{
    int identificador;
    int valor;
    int proximo_identificador;
} Pista;

Pista pistas[MAX_PISTAS];

void imprime_pistas(int identificador)
{
    int i;
    for (i = 0; i < MAX_PISTAS; i++)
    {
        if (pistas[i].identificador == identificador)
        {
            printf("%d\n", pistas[i].valor);
            if (pistas[i].proximo_identificador != -1)
            {
                imprime_pistas(pistas[i].proximo_identificador);
            }
            break;
        }
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &pistas[i].identificador, &pistas[i].valor, &pistas[i].proximo_identificador);
    }

    imprime_pistas(pistas[0].identificador);

    return 0;
}
