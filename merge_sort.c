#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[],int lb,int mid,int p,int hb)
{
    int b[hb+1];
    int i=lb,j=p,k=lb;
    while(i<= mid&&j< hb)
    {
        if(arr[i]<arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];
    }
    while(i<=mid)
        b[k++]=arr[i++];
    while(j<=hb)
        b[k++]=arr[j++];
    for(int x=lb;x<=hb;x++)
        arr[x]= b[x];
}
void merge_sort(int arr[],int lb,int hb)
{
    if(lb<hb)
    {
        int mid=(lb+hb)/2;
        int p=mid+1;
        merge_sort(arr, lb, mid);
        merge_sort(arr, p, hb);
        merge(arr, lb, mid, p, hb);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand()%n;
    int lb=0,hb = n-1;
    clock_t start,end;
    double time;
    start = clock();
    merge_sort(arr, lb, hb);
    end=clock();
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    time =((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds", time);
    return 0;
}
