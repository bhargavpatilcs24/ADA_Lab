#include <stdio.h>
void sort(int value[], int weight[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            double r1 = (double)value[j] / weight[j];
            double r2 = (double)value[j+1] / weight[j+1];
            if (r1 < r2) {
                int temp = value[j];
                value[j] = value[j+1];
                value[j+1] = temp;
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
            }
        }
    }
}
double knapsack(int value[], int weight[], int n, int cap) {
    sort(value, weight, n);
    double total = 0;
    printf("\nObjects selected:\n");
    for (int i = 0; i < n; i++) {
        if (cap >= weight[i]) {
            cap -= weight[i];
            total += value[i];
            printf("Item %d -> Taken FULL (Profit = %d)\n", i+1, value[i]);
        } else {
            double frac = (double)cap / weight[i];
            double profit = value[i] * frac;
            total += profit;
            printf("Item %d -> Taken (Profit = %.2f)\n", i+1, profit);
            break;
        }
    }
    return total;
}
int main(){
    int p[10], w[10];
    int cap, n;
    printf("Enter the total capacity: ");
    scanf("%d", &cap);
    printf("Enter the number of objects used: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit and weight of object[%d]: ", i+1);
        scanf("%d %d", &p[i], &w[i]);
    }
    double max = knapsack(p, w, n, cap);
    printf("\nMax value = %.2f\n", max);
    return 0;
}
