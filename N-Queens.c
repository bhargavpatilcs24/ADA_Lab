#include<stdio.h>
#include<stdlib.h>
int x[20], count = 1;
void queens(int k, int n);
int place(int k, int j);
int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    queens(1, n);
    return 0;
}
void queens(int k, int n)
{
    int j, r, c;
    for(j = 1; j <= n; j++)
    {
        if(place(k, j))
        {
            x[k] = j;
            if(k == n)
            {
                printf("\nSolution %d:\n\n", count++);
                for(r = 1; r <= n; r++)
                {
                    for(c = 1; c <= n; c++)
                    {
                        if(x[r] == c)
                            printf("* ");
                        else
                            printf("_ ");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                queens(k + 1, n);
            }
        }
    }
}
int place(int k, int j)
{
    int i;
    for(i = 1; i < k; i++)
    {
        if(x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}
