//Write a menu driven program to input a number and display your choice.
#include <stdio.h>
int main ()
{
    int num;
    menu:
        printf("\n\n-----MENU-----");
        printf("\n1)One");
        printf("\n2)Two");
        printf("\n3)Three");
        printf("\n4)Four");
        printf("\n5)Exit the code.\n");
        printf("Enter your choice- ");
        scanf("%d",&num);
    switch(num)
        {
            case 1: printf("\nONE");
                    goto menu;
            case 2: printf("\nTWO");
                    goto menu;
            case 3: printf("\nTHREE");
                    goto menu;
            case 4: printf("\nFOUR");
                    goto menu;
            case 5: break;
        }
    return 0;
}