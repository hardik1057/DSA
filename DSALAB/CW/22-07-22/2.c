//WAP to reverse the contents of an array of n elements.
#include<stdio.h>
int main()
{
    int n;
    printf("Enter size of array-");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements into array- ");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    printf("Original Array- ");
    for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }    
    printf("\n");
    for(int i=0;i<n/2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[(n-1)-i];
            arr[n-1-i]=temp;
        }
    printf("Reversed Array- ");
    for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
}
