/*Write a menu driven program to test the following cases.
        1)   ODD / EVEN
        2)  Prime / Not prime
        3)  Palindrome / Not Palindrome
        4)  Armstrong / Not Armstrong number
        5) Quit.*/
#include <stdio.h>
#include <math.h>
int main ()
{
    int choice, master;
    int i,j,flag=0,num1, rev1=0, rem1, org1,num2, org2, rem2, n2=0, result2=0,rem3,num3;
    printf("Enter a number- ");
    scanf("%d",&master);
    menu:
        printf("\n\n------MENU------");
        printf("\n1) Find wether the number is even/odd.");
        printf("\n2) Find wether the number is prime/ not prime.");
        printf("\n3) Find wether the number is palindrome/ no palindrome.");
        printf("\n4) Find wether the number is Armstrong/ not armstrong.");
        printf("\n5) Exit the code.\n");
        printf("Enter your choice- ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1: rem2=master%2;
                if (rem2==0)
                    printf("%d is an even integer\n", master);
                else
                    printf("%d is an odd integer\n", master);
                goto menu;
        case 2: if (master==0||master==1)
                flag = 1;
                for (i=2;i<=master/2;++i) 
                    {
                        if (master % i == 0) 
                            {
                                flag = 1;
                                break;
                            }
                    }
                if (flag == 0)
                    printf("%d is a prime number.", master);
                else
                    printf("%d is not a prime number.", master);
                goto menu;
        case 3: org1=master;
                while (master!=0)
                    {
                        rem1=master%10;
                        rev1=rev1*10+rem1;
                        master/=10;
                    }
                if (org1==rev1)
                    printf("%d is a palindrome.\n", org1);
                else
                    printf("%d is not a palindrome.\n", org1);
                goto menu;
        case 4: org2=master;
                for (org2=master; org2!=0;n2++) 
                        org2/=10;
                for (org2=master; org2!=0; org2/=10) 
                    {
                        rem2=org2%10;
                        result2+=pow(rem2, n2);
                    }
                if (result2 == num2)
                    printf("%d is an Armstrong number.", master);
                else
                    printf("%d is not an Armstrong number.", master);
                goto menu;
        case 5: break;
    }
    return 0;
}