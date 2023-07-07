#include <stdio.h>

void DFS(int);
int isConnected();
int A[10][10], vis[10], n;

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("DFS Traversal\n");
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    DFS(1);

    if(isConnected()==1){
        printf("\nGraph is Conncetd.");
    } 
    else{
        printf("\nGraph is Not Conncetd.");
    }
    return 0;
}

void DFS(int v)
{
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++)
    {
        if (A[v][i] == 1 && vis[i] == 0)
        {
            DFS(i);
        }
    }
}

int isConnected()
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}