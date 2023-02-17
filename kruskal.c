#include<stdio.h>
int G[10][10], parent[10];

int findP(int i)
{
	while(parent[i])
		i = parent[i];
	return i;
}

int uni(int i, int j)
{
	if(i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}

void main()
{
	int i, j, a, b, v, u, min, n, edges=0, minCost=0;
	printf("HOW MANY VERTICES: ");
	scanf("%d", &n);
	printf("ENTER THE EDGES:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &G[i][j]);
			if(G[i][j] == 0)
				G[i][j] = 999;
		}
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	
	printf("EDGES : WEIGHT\n");
	while(edges < n-1)
	{
		for(i=0, min = 999; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(G[i][j] < min)
				{
					min = G[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = findP(u);
		v = findP(v);
		if(uni(u,v))
		{
			printf("%d-%d : %d\n", a, b, min);
			edges++;
			minCost += min;
		}
		G[a][b] = G[b][a] = 999;
	}
	printf("Min Cost: %d\n", minCost);
}
