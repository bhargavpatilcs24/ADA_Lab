#include <stdio.h>

int main()
{
    int n, i, j, k;
    int graph[20][20];
    int indegree[20] = {0};
    int visited[20] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Calculate indegree of each vertex */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("\nTopological Ordering: ");

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(indegree[i] == 0 && visited[i] == 0)
            {
                printf("%d ", i);

                visited[i] = 1;

                for(j = 0; j < n; j++)
                {
                    if(graph[i][j] == 1)
                        indegree[j]--;
                }
            }
        }
    }

    printf("\n");

    return 0;
}
