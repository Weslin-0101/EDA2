#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_V 2000

int graph[MAX_V][MAX_V]; // matriz de adjacência para armazenar as conexões entre as cidades
int V;                   // número de cidades

bool visited[MAX_V]; // vetor de visitados

typedef enum
{
    IDA_VOLTA,
    APENAS_IDA,
    APENAS_VOLTA,
    IMPOSSIBRU
} TipoViagem;

// algoritmo DFS para percorrer o grafo a partir do vértice atual
void DFS(int current)
{
    visited[current] = true;
    for (int i = 0; i < V; i++)
    {
        if (graph[current][i] < INT_MAX && !visited[i])
        {
            DFS(i);
        }
    }
}

// função para verificar se é possível ir de t a x e vice-versa
TipoViagem check(int t, int x)
{
    // inicializa o vetor de visitados com 0
    memset(visited, 0, sizeof visited);

    // verifica se é possível ir de t a x
    DFS(t);
    bool t_x = visited[x];

    // inicializa o vetor de visitados com 0 novamente
    memset(visited, 0, sizeof visited);

    // verifica se é possível ir de x a t
    DFS(x);
    bool x_t = visited[t];

    if (t_x && x_t)
    {
        return IDA_VOLTA;
    }
    else if (t_x)
    {
        return APENAS_IDA;
    }
    else if (x_t)
    {
        return APENAS_VOLTA;
    }
    else
    {
        return IMPOSSIBRU;
    }
}

int main()
{
    int v, w, d;
    scanf("%d", &V);

    // inicializa a matriz de adjacência com INT_MAX
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    while (true)
    {
        scanf("%d %d %d", &v, &w, &d);
        if (v == 0 && w == 0 && d == 0)
        {
            break;
        }

        // adiciona a conexão entre as cidades na matriz de adjacência
        graph[v][w] = d;
        if (d == 2)
        {
            graph[w][v] = 1;
        }
    }

    int t, x;
    while (scanf("%d %d", &t, &x) != EOF)
    {
        TipoViagem tipo = check(t, x);
        switch (tipo)
        {
        case IDA_VOLTA:
            printf("Ida e Volta\n");
            break;
        case APENAS_IDA:
            printf("Apenas Ida\n");
            break;
        case APENAS_VOLTA:
            printf("Apenas Volta\n");
            break;
        case IMPOSSIBRU:
            printf("Impossibru\n");
            break;
        }
    }

    return 0;
}
