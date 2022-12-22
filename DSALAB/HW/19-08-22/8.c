// WAP to input a number and test it is palindrome or not.
#include <stdio.h>
int main()
{
    int num, rev = 0, rem, org;
    printf("Enter an integer- ");
    scanf("%d", &num);
    org = num;
    while (num != 0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    if (org == rev)
        printf("%d is a palindrome.\n", org);
    else
        printf("%d is not a palindrome.\n", org);
    return 0;
}