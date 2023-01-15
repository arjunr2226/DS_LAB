#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void DFS(int graph[MAX][MAX], int start, int vertexCount)
{

    bool visited[vertexCount];
    for (int i = 0; i < vertexCount; i++)
        visited[i] = false;

    int stack[vertexCount];
    int top = -1;

    stack[++top] = start;
    visited[start] = true;
    while (top >= 0)
    {

        int current = stack[top--];
        printf("%d\t", current);

        for (int i = vertexCount - 1; i >= 0; i--)
        {
            if (graph[current][i] && !visited[i])
            {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

void BFS(int graph[MAX][MAX], int start, int vertexCount)
{

    bool visited[vertexCount];
    for (int i = 0; i < vertexCount; i++)
        visited[i] = false;
    int queue[vertexCount];
    int front = -1, rear = -1;
    queue[++rear] = start;
    front++;
    visited[start] = true;
    while (front <= rear)
    {
        int current = queue[front++];
        printf("%d\t", current);

        for (int i = vertexCount - 1; i >= 0; i--)
        {
            if (graph[current][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{

    int choice, i, j, start, vertexCount = 0;
    int graph[MAX][MAX];

    do
    {
        printf("Enter a choice :\n0) Exit\n1) Create graph\n2) Depth first traversal\n3) Breadthfirst traversal\n\n->  ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 0:
        {
            printf("Exiting....\n\n");
            exit(0);
        }
        case 1:
        {

            printf("Enter the number of vertex in the graph: ");
            scanf("%d", &vertexCount);

            printf("Enter the adjacency matrix in order: ");
            for (i = 0; i < vertexCount; i++)
            {

                for (j = 0; j < vertexCount; j++)
                {
                    scanf("%d", &graph[i][j]);
                }
            }

            printf("\n\n");
            break;
        }

        case 2:
        {

            if (vertexCount > 0)
            {
                printf("Enter the start vertex: ");
                scanf("%d", &start);
                printf("Graph elements are : ");
                DFS(graph, start, vertexCount);
                printf("\n\n");
            }
            else
            {
                printf("Can not perform depth first traversal in an empty graph!\n\n");
            }

            break;
        }

        case 3:
        {

            if (vertexCount > 0)
            {
                printf("Enter the start vertex: ");
                scanf("%d", &start);
                printf("Graph elements are : ");
                BFS(graph, start, vertexCount);
                printf("\n\n");
            }
            else
            {
                printf("Can not perform breadth first traversal in an empty graph!\n\n");
            }

            break;
        }
        }
    } while (choice != 0);

    // int graph[V][V] = {
    //     {0, 1, 1, 0, 0, 0},
    //     {0, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 0},
    //     {0, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 1, 0, 0}
    // };
    // DFS(graph, 0);
    // printf("\n");
    // return 0;
}