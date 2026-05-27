#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapcom(int a[], int n) {
    int i, j, k, item;
    for (i = 1; i <= n; i++) {
        item = a[i];
        j = i;
        k = j / 2;
        while (k != 0 && item > a[k]) {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n) {
    int item, i, j;
    j = 1;
    item = a[j];
    i = 2 * j;
    while (i < n) {
        if ((i + 1) < n) {
            if (a[i] < a[i + 1]) {
                i++;
            }
        }
        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        } else {
            break;
        }
    }
    a[j] = item;
}

void heapsort(int a[], int n) {
    int i, temp;

    heapcom(a, n);
    for (i = n; i >= 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        adjust(a, i);
    }
}

int main() {
    int i, n, a[20], ch = 1;
    clock_t start, end;

    while (ch) {
        printf("\n Enter the number of elements to sort (max 19):\n");
        scanf("%d", &n);

        if (n > 19 || n < 1) {
            printf(" Please enter a valid number between 1 and 19.\n");
            continue;
        }

        printf("\n Enter the elements to sort:\n");
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        start = clock();
        heapsort(a, n);
        end = clock();

        printf("\n The sorted list of elements is:\n");
        for (i = 1; i <= n; i++) {
            printf("%d\n", a[i]);
        }

        printf("\n Time taken is %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\n Do you wish to run again? (0/1)\n");
        scanf("%d", &ch);
    }

    return 0;
}
