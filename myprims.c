#include <stdio.h>
#define INF 999
#define n 5
int G[n][n] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

void main()
{
    int edges = 0, visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int x, y;
    visited[0] = 1;
    printf("Edge : Weight\n");

    while (edges < n - 1)
    {
        int min = INF;
        x = y = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && G[i][j] != 0)
                    {
                        if (G[i][j] < min)
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        visited[y] = 1;
        edges++;
    }
}