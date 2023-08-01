#include <stdio.h>
int dist[10], cost[10][10], n, vis[10], src;
void dijkstra()
{
    int count, min, u;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = cost[src][i];
        vis[src] = 1;
    }
    count = 1;
    while (count < n)
    {
        min = 9999;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < min && vis[i] == 0)
            {
                min = dist[i];
                u = i;
            }
        }
        vis[u] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[u] + cost[u][i] < dist[i] && vis[i] == 0)
            {
                dist[i] = dist[u] + cost[u][i];
            }
        }
        count++;
    }
}

void main()
{
    int m, u, v, val;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the number of edges\n");
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = 9999;
            }
        }
    }

    printf("Enter the edge with weight\n");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v,&val);
        cost[v][u] = cost[u][v] = val;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source\n");
    scanf("%d", &src);
    dijkstra();
    for (int i = 2; i <= n; i++)
        printf("The distance to %d is %d\n", i, dist[i]);
}
