#include<stdio.h>
#include<stdlib.h>

void sum(int a[], int n)
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum = sum + a[i];
	}
	printf("\nSUM : %d\n", sum);
}

void max(int a[], int n)
{
	int max =a[0];
	for(int i=0; i<n; i++)
	{
		if(max < a[i])
			max = a[i];
	}
	printf("\nMAXIMUM: %d\n", max);
}

void min(int a[], int n)
{
	int min = a[0];
	for(int i=0; i<n; i++)
	{
		if(min > a[i])
			min = a[i];
	}
	printf("\nMINIMUM: %d\n", min);
}

void mean(int a[], int n)
{
	int sum=0, mean;
	for(int i=0; i<n; i++)
	{
		sum = sum + a[i];
	}
	mean = sum/n;
	printf("\nMEAN : %d\n", mean);
}

void main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n, ch;
	
	printf("HOW MANY ELEMENTS: ");
	scanf("%d", &n);
	printf("ENTER ARRAY ELEMENTS: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	while(1)
	{
		printf("\nENTER\n1:SUM\n2:MIN\n3:MAX\n4:MEAN\nCHOICE: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				sum(a, n);
				break;
			case 2:
				min(a, n);
				break;
			case 3:
				max(a, n);
				break;
			case 4:
				mean(a, n);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nWRONG OPTION!\n");
		}
	}

}
