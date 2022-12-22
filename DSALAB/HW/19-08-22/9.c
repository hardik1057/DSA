//WAP to input a number and check it is an Armstrong number or not.
#include<stdio.h>
#include <math.h>
int main() 
{
   int num, org, rem, n=0, result=0;
   printf("Enter an integer- ");
   scanf("%d", &num);
   org=num;
   for (org=num; org!=0;n++) 
        org/=10;
   for (org=num; org!=0; org/=10) 
    {
       rem=org%10;
       result += pow(rem, n);
    }
   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}