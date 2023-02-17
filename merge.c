#include<stdio.h>

void merge(int a[], int beg, int mid, int end)
{
	int i, j, k;
	int n1 = mid - beg + 1;
	int n2 = end - mid;
	int L[n1], R[n2];
	for(i=0; i<n1; i++)
		L[i] = a[i + beg];
	for(j=0; j<n2; j++)
		R[j] = a[j + mid + 1];
	i = j = 0;
	k = beg;
	
	while(i<n1 && j<n2)
	{
		if(L[i] <=R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r)
{
	int mid;
	if(l < r)
	{
		mid = (l+r)/2;
		mergeSort(a, 0, mid);
		mergeSort(a, mid+1, r);
		merge(a, l, mid, r);
	}
}

void main()
{
	int n;
	printf("HOW MANY ELEMENTS: ");
	scanf("%d", &n);
	//int a[] = {12,31,25,8,32,17,40,48};
	//int size = sizeof(a)/sizeof(a[0]);
	int a[n];
	
	printf("ENTER THE ELEMENTS: ");
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	mergeSort(a, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
