//Write a program to rearrange the elements of an array of n integers such that all even numbers are followed by all odd numbers
#include<stdio.h>
int main ()
{
    int num,temp=0;
    printf("Enter length of array- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers into the array- ");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    printf("Original array- ");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
    for(int i=0;i<(num-1);i++)
        {
            for(int j=0;j<(num-i-1);j++)
                {
                    if(arr[j+1]%2==0)
                        {
                            temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                }
        }
    printf("\nArray sorted with even elements at first- ");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
}