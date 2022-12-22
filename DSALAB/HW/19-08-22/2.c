//WAP in C to find factorial of a number using function.
#include<stdio.h>
int fact(int n) 
{
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
}
int main() 
{
    int num;
    printf("Enter a number- ");
    scanf("%d",&num);
    printf("Factorial of %d = %d\n", num, fact(num));
    return 0;
}
