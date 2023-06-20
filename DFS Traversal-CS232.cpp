#include <stdio.h>

void DFS(int);
void isConnected();
int A[10][10], vis[10], n;
int count=1;
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
   
   
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i);
        }
    }

    isConnected();
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
                 count++;
            DFS(i);
        }
    }
}

void isConnected()
{
    // Keeps track of the number of connected components

    if (count == n)
    {
        printf("\nGraph is Connected");
    }
    else
    {
        printf("%d",count);
        printf("\nGraph is not connected");
    }
}


////INPUTS: 0 1 1 99999 99999 1 0 99999 1 1 1 99999 0 99999 99999 99999 1 99999 0 99999 99999 1 99999 99999 0

//0 1 99999 99999 1 0 99999 99999 99999 99999 0 1 99999 99999 1 0
