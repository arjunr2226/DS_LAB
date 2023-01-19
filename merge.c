#include<stdio.h>
void merge(int arr[], int p, int q, int r)
{
  int n1, n2;
  int i, j, k;
  n1 = (q-p)+1;
  n2 = r-q;
  int L[n1], R[n2];
  for(i=0; i<n1; i++)
    L[i] = arr[p+i];
  for(j=0; j<n2; j++)
    R[j] = arr[q+1+j];
  i = 0;
  j = 0;
  k = p;
  while(i<n1 && j<n2)
  {
    if(L[i]<R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i<n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}
int mergeSort(int arr[], int l, int r)
{
  int mid;
  if(l<r)
  {
    mid =  l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
  }
}
void main()
{
  int arr[] = {4, 2, 6, 3, 7, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  mergeSort(arr, 0, size);
  for(int i = 0; i< 6; i++)
  {
    printf("%d",arr[i]);
  }
}
