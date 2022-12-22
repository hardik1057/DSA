//Write a program to test whether a number n, entered through keyboard is prime or not by using different algorithms.
#include<stdio.h>
void A1(int n)
{
    int cntA1=0,i, flag=0;
    if (n==0||n==1)
    flag = 1;
    for (i=2;i<=(n-1);i++) 
        {
            cntA1++;
            if (n%i==0) 
                {
                    flag = 1;
                    break;
                }
        }
    if (flag==0)
        printf("%d is a prime number\n", n);
    else
        printf("%d is not a prime number\n", n);
    printf("The number of the steps involved in algorithm 1 is %d\n", cntA1);
}
void A2(int n)
{
    int cntA2=0,i, flag=0;
    if (n==0||n==1)
    flag=1;
    for (i=2;i<=n/2;i++) 
        {
            cntA2++;
            if (n%i==0) 
                {
                    flag=1;
                    break;
                }
        }
    printf("The number of the steps involved in algorithm 2 is %d\n", cntA2);
}
void A3(int n)
{
    int cntA3=0,i, flag=0;
    if (n==0||n==1)
    flag=1;
    for (i=2;i*i<=n;i++) 
        {
            cntA3++;
            if (n%i==0) 
                {
                    flag=1;
                    break;
                }
        }
    printf("The number of the steps involved in algorithm 3 is %d\n", cntA3);
}
int main()
{
    int num;
    printf("Enter a number- ");
    scanf("%d", &num);
    A1(num);
    A2(num);
    A3(num);
    return 0;
}