//Write a menu driven program to input a day number and display the day.
#include <stdio.h>
int main ()
{
    int num;
    menu:
        printf("\n\n-----MENU-----");
        printf("\n1)Monday");
        printf("\n2)Tuesday");
        printf("\n3)Wednesday");
        printf("\n4)Thursday");
        printf("\n5)Friday");
        printf("\n6)Saturday");
        printf("\n7)Sunday");
        printf("\n8)Exit the code.\n");
        printf("Enter your choice- ");
        scanf("%d",&num);
    switch(num)
        {
            case 1: printf("\nMONDAY");
                    goto menu;
            case 2: printf("\nTUESDAY");
                    goto menu;
            case 3: printf("\nWEDNESDAY");
                    goto menu;
            case 4: printf("\nTHURSDAY");
                    goto menu;
            case 5: printf("\nFRIDAY");
                    goto menu;
            case 6: printf("\nSATURDAY");
                    goto menu;
            case 7: printf("\nSUNDAY");
                    goto menu;
            case 8: break;
        }
    return 0;
}