//WAP to read an array of integers and search for an element using linear search.
#include <stdio.h> 
int main()
{
    int search, c, n,flag=0;
    printf("Enter size of array- ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements- ");
    for (c = 0; c < n; c++)
        scanf("%d", &arr[c]);
    printf("Enter a number to be searched- ");
    scanf("%d", &search);
    for (c = 0; c < n; c++)
    {
        if (arr[c] == search) 
        {
            flag=1;
            printf("%d is present at index %d.\n", search, c);
            break;
        }
    }
    if (flag==0)
        printf("%d isn't present in the array.\n", search);
    return 0;
}