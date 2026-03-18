#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] >= pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[left], &arr[j]);
    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
}
int main()
{
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % n;
    int lb = 0, hb = n - 1;
    clock_t start, end;
    double time;
    start = clock();
    quicksort(arr, lb, hb);
    end = clock();
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds", time);
    return 0;
}
