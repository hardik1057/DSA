//WAP to find number of elements between two elements a and b(both inclusive)
#include<stdio.h>
int main(){
    int n,a,b;
    printf("Enter length of the array- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements into array- ");
    for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
    printf("Enter the two numbers you want to search betwee- ");
    scanf("%d %d",&a,&b);
    int ctr=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
            {
                ctr++;
                for(int j=i;j<n;j++)
                    {
                        if(arr[j]==b)
                            break;
                        else
                            ctr++;
                    }
                break;
            }
    }
    printf("Number of elements found between %d and %d (both inclusive)- %d",a,b,ctr);
}
