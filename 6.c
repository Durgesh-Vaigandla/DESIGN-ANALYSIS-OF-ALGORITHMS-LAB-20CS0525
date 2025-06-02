#include<stdio.h>
int Prim(int g[20][20], int n, int t[20][20])
{
    int u, v, min, mincost;
    int visited[20];
    int i, j, k;
    for(k = 1; k <= n; k++)
        visited[k] = 0;
    visited[1] = 1;
    mincost = 0;
    for(k = 1; k <= n - 1; k++)
    {
        min = 99;
        u = 1;
        v = 1;
        for(i = 1; i <= n; i++)
            if(visited[i] == 1)
        for(j = 1; j <= n; j++)
            if(g[i][j] < min)
            {
                min = g[i][j];
                u = i;
                v = j;
            }
        t[u][v] = t[v][u] = g[u][v];
        mincost = mincost + g[u][v];
        visited[v] = 1;
        printf("\n(%d, %d) = %d", u, v, t[u][v]);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(visited[i] && visited[j])
                    g[i][j] = g[j][i] = 99;
    }
    return (mincost);
}

void main()
{
    int n, cost[20][20], t[20][20];
    int mincost, i, j;
    printf("\nEnter the no of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
            cost[i][j] = 99;
        }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            t[i][j] = 99;
    printf("\nThe order of Insertion of edges: ");
    mincost = Prim(cost, n, t);
    printf("\nMinimum cost = %d\n\n", mincost);
}