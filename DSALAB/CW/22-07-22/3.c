//WAP to search an element in an array of n numbers
#include<stdio.h>
int main()
{
    int n,c,flag=0, i ;
    printf("Enter length of array- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements into the array- ");
    for( i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched for- ");
    scanf("%d",&c);
    for( i=0;i<n;i++)
        {
            if (arr[i]==c)
                {
                    flag=1;
                    break;
                }
        }
    if (flag==1)
        printf("%d found in array at %d index",c, i);
    else
        printf("%d not found in array",c);
}