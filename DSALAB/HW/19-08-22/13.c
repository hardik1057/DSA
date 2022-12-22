/*Let A be n*n square matrix array. WAP by using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/
#include<stdio.h>
int main ()
{
    int num, row, col,i ,j;
    int sum1=0,sum2=0,pro1=1,pro2=1,count=0;
    printf("Enter number of rows- ");
    scanf("%d",&row);
    while (getchar()!='\n');
    printf("Enter number of colums- ");
    scanf("%d",&col);
    if (row!=col)
            printf("Please enter a square matrix of same number of row and column. "); 
    else
        {
        int arr[row][col];
        printf("Enter elements into matrix- ");
        for (i=0;i<row;i++)
            for(j=0;j<col;j++)
                scanf("%d",&arr[i][j]);
        for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                    {
                        if (arr[i][j]!=0)
                            count++;
                        if (j>i)
                            sum1=sum1+arr[i][j];
                        if(i==j)
                            pro1=pro1*arr[i][j];
                        if(j==col-1-i)
                            pro2=pro2*arr[i][j];
                    }
                for(j=col-1;j>col-1-i;j--)
                    {
                        sum2+=arr[i][j];
                    }
            }
                printf("Total non zero elements in matix is- %d\n", count);
                printf("Sum of elements above leading diagonal is- %d\n", sum1);
                printf("Product of leading diagonal elements is- %d",pro1);
                printf("\nProduct of minor diagonal elements is- %d\n",pro2);
                printf("Sum of elements below minor diagonal is- %d\n", sum2);
    return 0;
    }
}