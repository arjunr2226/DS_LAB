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

// Implementation of BFS
void BFS(int adj[][total_vertices], int start)
{
    // Implementing queue
    int queue[total_vertices], front = -1, rear = -1;

    // Marking Visited vertices.
    int visited[total_vertices];

    // Marking all vertices as unvisited (0)
    for (int i = 0; i < total_vertices; i++)
        visited[i] = 0;

    // Initializing
    front = rear = 1;
    queue[rear] = start;
    visited[start] = 1;
    while (front <= rear)
    {
        start = queue[front];
        printf("%d ", start);
        for (int i = 0; i < total_vertices; i++)
        {
            if (adj[start][i] == 1 && visited[i] != 1)
            {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
        front++;
    }
}

// Implementation of DFS
void DFS(int adj[][total_vertices], int visited[], int start)
{
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < total_vertices; i++)
    {
        if (adj[start][i] == 1 && visited[i] != 1)
        {
            DFS(adj, visited, i);
        }
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

    // Calling BFS Function
    // printf("\n----BFS----\n");
    // BFS(adj, 1);
    // printf("\n");

    // Initializing visited array for DFS traversal
    int visited[total_vertices];
    for (int i = 0; i < total_vertices; i++)
        visited[i] = 0;
    // Calling DFS Function
    printf("\n----DFS----\n");
    DFS(adj, visited, 1);
    printf("\n");
    // printMatrix(adj);
}