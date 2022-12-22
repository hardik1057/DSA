// WAP to create an un-directed graph using Adjacency Matrix Method.// C program for the above approach
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int g, i, j;
    printf("Enter Number of Vertices- ");
    scanf("%d", &g);
    int dptable[g + 1][g + 2];
    for (i = 0; i <= g; i++)
        for (j = 0; j <= g + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dptable[i][j] = 0;
            }
            else if (i == 0)
            {
                dptable[i][j] = j - 1;
            }
            else if (j == 0)
            {
                dptable[i][j] = i;
            }
            else
            {
                dptable[i][j] = 0;
            }
        }
    while (1)
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
            dptable[k][p + 1] = 1;
            dptable[p][k + 1] = 1;
        }
        int y;
        printf("do you want to continue?if not press 1- ");
        scanf("%d", &y);
        if (y == 1)
        {
            break;
        }
    }
    printf("Adjanency Matrix of the above graph is- \n");
    for (i = 0; i <= g; i++)
    {
        for (j = 0; j <= g + 1; j++)
        {
            printf("%d ", dptable[i][j]);
        }
        printf("\n");
    }
    return 0;
}
