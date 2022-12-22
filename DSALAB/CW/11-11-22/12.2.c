//WAP to read an array of integers and search for an element using binary search.
#include<stdio.h>
int main ()
{
    int size, temp=0,search=0, flag=0;
    printf("Enter size of array- "); 
    scanf("%d", &size );
    int arr[size];
    printf("Enter elements- ");
    for (int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp=arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array- ");
    for (int i=0;i<size;i++)
    {
        printf("%d < ", arr[i]);
    }
    printf("\nEnter number to be searched- ");
    scanf("%d", &search);
    int lb = 0,hb = size,mid;
    while (lb <= hb)
    {
        mid = (lb + hb) / 2;
        if (arr[mid] == search)
        {
            flag = 1;
            printf("Found\n");
            break;
        }
        if (search< arr[mid])
            hb = mid - 1;
        else
            lb = mid + 1;
    }
    if (flag == 0)
        printf("\n%d isn't present in the array.\n", search);
    return 0;
}