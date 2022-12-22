//WAP in C to find maximum among 2 numbers using function.
#include<stdio.h>  
int biggest(int x, int y)  
    {  
        return( x>y?x:y );  
    }  
int main()  
{  
    int a, b;  
    printf("Enter 2 integer numbers- ");  
    scanf("%d%d", &a, &b);  
    printf("Biggest of %d and %d is %d.\n", a, b, biggest(a, b));  
    return 0;  
}  