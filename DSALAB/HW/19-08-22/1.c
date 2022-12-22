//WAP in C to using function input 10 numbers in an array and display it.
#include <stdio.h>
int arr[10];
void create(int n)
{
        printf("Enter 10 elements into array- ");
        for (int i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);
        }
}
void display(int n)
{
        printf("Entered array is- ");
        for (int i = 0; i < n; i++)
        {
                printf("%d  ", arr[i]);
        }
}
int main()
{
    create(10);
    display(10);
}