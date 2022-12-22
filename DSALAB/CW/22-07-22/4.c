//WAP to sort an array of n numbers.
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
    for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    if(arr[i]>arr[j])
                        {
                            int temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
                }
        }   
    printf("Sorted Array (ascending order)- ");
    for(int i=0;i<n;i++)
        {
            printf("%d < ",arr[i]);
        }
}
