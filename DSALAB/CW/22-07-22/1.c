//WAP to find out the smallest and largest element stored in an array of n integers.
#include<stdio.h>
int main()
{
    int n, min, max;
    printf("Enter size of array-");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements into array- ");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            max=min=arr[0];
            if(arr[i]>max)
                {
                    max=arr[i];
                }
            if(arr[i]<min)
                {
                    min=arr[i];
                }
        }
    printf("Largest Element-%d\n",max);
    printf("Smallest Element-%d\n",min);
}
