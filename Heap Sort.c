#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapcom(int a[], int n)
{
    int i, j, k, item;

    for(i = 1; i <= n; i++)
    {
        item = a[i];
        j = i;
        k = j / 2;

        while(k != 0 && item > a[k])
        {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n)
{
    int item, i, j;

    j = 1;
    item = a[j];
    i = 2 * j;

    while(i < n)
    {
        if((i + 1) < n && a[i] < a[i + 1])
            i++;

        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        }
        else
            break;
    }
    a[j] = item;
}

void heapsort(int a[], int n)
{
    int i, temp;

    heapcom(a, n);

    for(i = n; i >= 1; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        adjust(a, i);
    }
}

int main()
{
    int i, n;
    int *a;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc((n + 1) * sizeof(int));

    srand(time(NULL));

    /* Generate random numbers from 1 to n */
    for(i = 1; i <= n; i++)
    {
        a[i] = rand() % n + 1;
    }

    printf("\nGenerated Elements:\n");
    for(i = 1; i <= n; i++)
        printf("%d ", a[i]);

    start = clock();

    heapsort(a, n);

    end = clock();

    printf("\n\nSorted Elements:\n");
    for(i = 1; i <= n; i++)
        printf("%d ", a[i]);

    printf("\n\nExecution Time = %lf seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    free(a);

    return 0;
}
