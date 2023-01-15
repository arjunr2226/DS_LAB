#include <stdio.h>
int total_vertices;

// Printing the Adjucency Matrix
void printMatrix(int adj[total_vertices][total_vertices])
{
    for (int i = 0; i < total_vertices; i++)
    {
        for (int j = 0; j < total_vertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int src, dstn;
    // Total number of vertices
    printf("ENTER THE TOTAL NUMBER OF VERTICES :");
    scanf("%d", &total_vertices);

    // Initializing matrix
    int adj[total_vertices][total_vertices];

    // Initializing all entries to 0
    for (int i = 0; i < total_vertices; i++)
        for (int j = 0; j < total_vertices; j++)
            adj[i][j] = 0;

    // Inserting values into matrix
    while (src != -1 && dstn != -1)
    {
        printf("ENTER THE EDGES :");
        scanf("%d %d", &src, &dstn);

        // Since implementing on Un-directed graph, parallel edges.
        adj[src][dstn] = 1;
        adj[dstn][src] = 1;
    }

    printMatrix(adj);
}