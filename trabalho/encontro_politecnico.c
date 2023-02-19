#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa a posição de um professor no mapa
typedef struct
{
    int x;
    int y;
} Position;

// Estrutura que representa um grafo com matriz de adjacências
typedef struct
{
    int numVertices;
    int **adjMatrix;
} Graph;

// Função para criar um grafo com matriz de adjacências de tamanho nxm
Graph *createGraph(int n, int m)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = n * m;
    g->adjMatrix = (int **)malloc(g->numVertices * sizeof(int *));
    for (int i = 0; i < g->numVertices; i++)
    {
        g->adjMatrix[i] = (int *)calloc(g->numVertices, sizeof(int));
    }
    return g;
}

// Função para liberar a memória alocada para o grafo
void freeGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}

// Função para adicionar uma aresta entre os vértices u e v do grafo
void addEdge(Graph *g, int u, int v)
{
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
}

// Função que converte uma posição (x, y) no mapa para o número do vértice correspondente no grafo
int positionToVertex(Graph *g, int x, int y)
{
    return (x - 1) * g->numVertices / g->numVertices + (y - 1) * g->numVertices / g->numVertices;
}

// Função que verifica se a posição está fora dos limites do mapa
int outOfBounds(Position pos, int n, int m)
{
    return pos.x < 1 || pos.y < 1 || pos.x > n || pos.y > m;
}

// Função que move a posição para uma nova posição de acordo com a direção dada
void move(Position *pos, int dir)
{
    switch (dir)
    {
    case 1:
        pos->y += 1;
        break; // Norte
    case 2:
        pos->y -= 1;
        break; // Sul
    case 3:
        pos->x += 1;
        break; // Leste
    case 4:
        pos->x -= 1;
        break; // Oeste
    }
}

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    Graph *g = createGraph(n, m);
    int step = 1, found = 0, outPA = 0, outPB = 0;
    Position posPA = {1, 1}, posPB = {n, m};

    for (int i = 0; i < p; i++)
    {
        int dirPA, dirPB;
        scanf("%d %d", &dirPA, &dirPB);

        move(&posPA, dirPA);
        move(&posPB, dirPB);

        // if (outOfBounds(posPA, n, m) && outOfBounds(posPB, n, m))
        // {
        //     outPA = outPB = step;
        //     break;
        // }
        if (outOfBounds(posPA, n, m))
        {
            outPA = step;
            break;
        }
        else if (outOfBounds(posPB, n, m))
        {
            outPB = step;
            break;
        }

        if (posPA.x == posPB.x && posPA.y == posPB.y)
        {
            found = step;
            break;
        }

        int vPA = positionToVertex(g, posPA.x, posPA.y);
        int vPB = positionToVertex(g, posPB.x, posPB.y);
        addEdge(g, vPA, vPB);

        step++;
    }

    if (found)
    {
        printf("Encontram-se na posicao (%d, %d) no passo %d\n", posPA.x, posPA.y, found);
    }
    else if (outPA)
    {
        printf("PA saiu na posicao (%d, %d) no passo %d\n", posPA.x, posPA.y, outPA);
    }
    else if (outPB)
    {
        printf("PB saiu na posicao (%d, %d) no passo %d\n", posPB.x, posPB.y, outPB);
    }
    else
    {
        printf("Nao se encontraram\n");
    }

    freeGraph(g);

    return 0;
}
