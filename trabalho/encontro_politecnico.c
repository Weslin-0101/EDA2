#include <stdio.h>

int main()
{
    int n, m, p, pa_x = 1, pa_y = 1, pb_x, pb_y, i, mov_pa, mov_pb;
    scanf("%d %d %d", &n, &m, &p);
    pb_x = n;
    pb_y = m;
    for (i = 1; i <= p; i++)
    {
        scanf("%d %d", &mov_pa, &mov_pb);
        // Movimento do professor PA
        if (mov_pa == 1)
        {
            pa_y++;
        }
        else if (mov_pa == 2)
        {
            pa_y--;
        }
        else if (mov_pa == 3)
        {
            pa_x++;
        }
        else
        {
            pa_x--;
        }
        // Verificação de saída do professor PA
        if (pa_x < 1 || pa_x > n || pa_y < 1 || pa_y > m)
        {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i);
            return 0;
        }
        // Movimento do professor PB
        if (mov_pb == 1)
        {
            pb_y++;
        }
        else if (mov_pb == 2)
        {
            pb_y--;
        }
        else if (mov_pb == 3)
        {
            pb_x++;
        }
        else
        {
            pb_x--;
        }
        // Verificação de saída do professor PB
        if (pb_x < 1 || pb_x > n || pb_y < 1 || pb_y > m)
        {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_x, pb_y, i);
            return 0;
        }
        // Verificação de encontro dos professores
        if (pa_x == pb_x && pa_y == pb_y)
        {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i);
            return 0;
        }
    }
    printf("Nao se encontraram\n");
    return 0;
}
