/*Modify the above program to include a menu driven program and add options for the depth first traversal and breadth-first traversal and write 
code for those traversal also.*/
#include <stdio.h>
void bfs(int dptable[100][100], int *a, int h, int org)
{
    if (org > h)
    {
        return;
    }
    int i;
    for (i = 0; i <= h; i++)
    {
        if (dptable[org][i] == 1 && a[i] != 1)
        {
            a[i] = 1;
            printf("%d ", org);
            bfs(dptable, a, h, i);
        }
    }
    org++;
    bfs(dptable, a, h, org);
}
void dfs(int dptable[100][100], int *a, int g, int h)
{
    if (g > h)
    {
        return;
    }
    for (int i = 0; i <= h; i++)
    {
        if (dptable[g][i] == 1 && a[i] != 1)
        {
            a[i] = 1;
            printf("%d ", g);
            dfs(dptable, a, i, h);
        }
    }
    g++;
    dfs(dptable, a, g, h);
}
int main()
{
    int g, i, j;
    printf("Enter Number of Vertices:");
    scanf("%d", &g);
    int dptable[100][100], a[g + 1], b[g + 1];
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            dptable[i][j] = 0;
        }
    }
again:
    printf("Press 1 for insertion\nPress 2 for DFS\nPress 3 for BFS\nPress 4 to quit");
    int w;
    printf("\nEnter your choice:");
    scanf("%d", &w);
    switch (w)
    {
        case 1: while (1)
                {
                    printf("Caution Limit is %d\n", g);
                    printf("which node you want to connect?\n");
                    int k;
                    scanf("%d", &k);
                    printf("to which node you want to connect it?\n");
                    int p;
                    scanf("%d", &p);
                    if (p > g || k > g)
                    {
                        printf("You are out of limit\n");
                    }
                    else
                    {
                        dptable[k][p] = 1;
                        dptable[p][k] = 1;
                    }
                    int y;
                    printf("do you want to continue?if not press 1:\n");
                    scanf("%d", &y);
                    if (y == 1)
                    {
                        break;
                    }
                }
                goto again;
        case 2: for (i = 0; i <= g; i++)
                {
                    a[i] = 0;
                }
                dfs(dptable, a, 0, g);
                printf("\n");
                goto again;
        case 3: for (i = 0; i <= g; i++)
                {
                    b[i] = 0;
                }
                bfs(dptable, b, g, 0);
                printf("\n");
                goto again;
        case 4: break;
    }
    return 0;
}