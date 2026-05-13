#include <stdio.h>
#include <stdbool.h>
#define LEFT 0
#define RIGHT 1
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int findLargestMobile(int a[], int dir[], int n, int *mobileIndex) {
    int maxMobile = 0;
    *mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        bool isMobile = false;
        if (dir[a[i]] == LEFT && i > 0 && a[i] > a[i - 1]) {
            isMobile = true;
        }
        else if (dir[a[i]] == RIGHT && i < n - 1 && a[i] > a[i + 1]) {
            isMobile = true;
        }
        if (isMobile && a[i] > maxMobile) {
            maxMobile = a[i];
            *mobileIndex = i;
        }
    }

    return maxMobile;
}
void johnsonTrotter(int n) {
    int a[n];
    int dir[n + 1];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[a[i]] = LEFT;
    }
    printPermutation(a, n);

    while (true) {
        int mobileIndex;
        int mobileElement = findLargestMobile(a, dir, n, &mobileIndex);
        if (mobileElement == 0) {
            break;
        }
        if (dir[mobileElement] == LEFT) {
            swap(&a[mobileIndex], &a[mobileIndex - 1]);
        } else if (dir[mobileElement] == RIGHT) {
            swap(&a[mobileIndex], &a[mobileIndex + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > mobileElement) {
                if (dir[a[i]] == LEFT) {
                    dir[a[i]] = RIGHT;
                } else {
                    dir[a[i]] = LEFT;
                }
            }
        }
        printPermutation(a, n);
    }
}
int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    printf("\nGenerating permutations for %d elements:\n", n);
    johnsonTrotter(n);
    return 0;
}