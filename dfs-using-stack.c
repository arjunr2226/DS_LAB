#include<stdio.h>
int total_vertices;

void dfs(int adj[][total_vertices], int start)
{
	int visited[total_vertices];
	for(int i=0; i<total_vertices; i++)
		visited[i] = 0;
	
	int stack[total_vertices], top = -1;
	stack[++top] = start;
	visited[start] = 1;
	
	while(top > -1)
	{
		start = stack[top--];
		printf("%d ", start);
		for(int i=0; i<total_vertices; i++)
		{
			if(adj[start][i] == 1 && visited[i] != 1)
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		}
	}	
}

void main()
{
	int src, dstn;
	printf("ENTER TOTAL VERTICES: ");
	scanf("%d", &total_vertices);
	int adj[total_vertices][total_vertices];
	
	for(int i=0; i<total_vertices; i++)
		for(int j=0; j<total_vertices; j++)
			adj[i][j] = 0;
	
	
	while(src != -1 && dstn != -1)
	{
		printf("ENTER THE EDGE: ");
		scanf("%d %d", &src, &dstn);
		adj[src][dstn] = adj[src][dstn] = 1;
	}
	dfs(adj, 0);
}
