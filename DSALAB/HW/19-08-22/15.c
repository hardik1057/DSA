/*WAP program to input n number of elements in an dynamic array . Write a menu to do the following operations in the array.
    a)    Insert an element.
    b)    Delete an element.
    c)    Reverse the elements.
    d)    Search an element.
    e)    Sort all elements.
    f)    Display all the elements.
    g)    Display all composite elements.
    h)    Quit.*/
#include <stdio.h>
#include<stdlib.h>
int checkPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if ((n % i) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int master, size, num, key;
    int i, j, temp, search, flag, index = 0, a, select = 0;
    printf("Enter size of array- ");
    scanf("%d", &size);
    int *arr=(int *)malloc(size*sizeof(int));
    printf("Enter elements into array- ");
    for (int i=0;i<size;i++)
        scanf("%d", arr+i);
    menu:
        printf("\n\n-------MENU-------");
        printf("\n1)Insert an element and print the updated array.");
        printf("\n2)Delete an element.");
        printf("\n3)Reverse the elements.");
        printf("\n4)Search an element.");
        printf("\n5)Sort all elements.");
        printf("\n6)Display all the elements.");
        printf("\n7)Display all composite elements.");
        printf("\n8)Exit the code.\n");
        printf("\nEnter your choice- ");
        scanf("%d", &master);
    switch (master)
        {
            case 1: printf("Enter number you want to insert- ");
                    scanf("%d", &num);
                    printf("Enter the position at you want to insert- ");
                    scanf("%d", &key);
                    for (i=size-1;i>=key-1;i--)
                        {
                            arr[i+1]=arr[i];
                        }
                    arr[key-1]=num;
                    printf("\nEntered/ updated array is- ");
                    for (i = 0; i <=size; i++)
                        printf("%d ", arr[i]);
                    key=0;
                    goto menu;
            case 2: printf("Enter the location where you wish to delete element- ");
                    scanf("%d", &key);
                    if (key>=size+1)
                        printf("Deletion not possible.\n");
                    else
                        {
                            for (i=key-1;i<size-1;i++)
                                arr[i]=arr[i+1];
                            size--;
                        }
                    goto menu;
            case 3: for (i=0;i<size/2;i++)
                        {
                            temp = arr[i];
                            arr[i] = arr[size - i - 1];
                            arr[size - i - 1] = temp;
                        }
                    goto menu;
            case 4: printf("Enter element you want to search for-");
                    scanf("%d", &search);
                    for (i = 0; i < size; i++)
                        {
                            if (arr[i] == search)
                                flag = 1;
                            index++;
                        }
                    if (flag == 1)
                        printf("Element found at %d index.", index - 1);
                    else
                        printf("Element not found.");
                    goto menu;
            case 5: printf("Press 1 for ascending and 2 for descending.\n");
                    scanf("%d", &select);
                    if (select == 1)
                        {
                            for (i = 0; i < size; i++)
                                {
                                    for (j = i + 1; j < size; j++)
                                        {
                                            if (arr[i] > arr[j])
                                                {
                                                    a = arr[i];
                                                    arr[i] = arr[j];
                                                    arr[j] = a;
                                                }
                                        }
                                }
                        }
                    else if (select == 2)
                        {
                            for (i = 0; i < size; i++)
                                {
                                    for (j = i + 1; j < size; j++)
                                        {
                                            if (arr[i] < arr[j])
                                                {
                                                    a = arr[i];
                                                    arr[i] = arr[j];
                                                    arr[j] = a;
                                                }
                                        }
                                }
                
                        }
            case 6: printf("\nEntered/ updated array is- ");
                    for (i = 0; i <size; i++)
                        printf("%d ", arr[i]);
                    goto menu;
            case 7: printf("Composite numbers are- ");
                    for (i = 0; i <= size; i++)
                        {
                            int x = checkPrime(arr[i]);
                            if (x)
                                {
                                    printf("%d ", arr[i]);
                                }
                        }
                    goto menu;
            case 8: break;
        }
    return 0;
}