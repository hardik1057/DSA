//Design algorithm to check if the content of a single linked list is forming a palindrome number or not .Compute the time complexity of your algo.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create(struct node *p, int n)
{
    struct node *lst = p;
    printf("Enter elements- ");
    while (n != 0)
    {
        int key;
        scanf("%d", &lst->data);
        n--;
        if (n != 0)
            {
                lst->next = (struct node*)malloc(sizeof(struct node));
                lst = lst->next;
            }
        else
            {
                lst->next = NULL;
            }
    }
}
struct node *last(struct node *p, int size)
{
    while (size != 1)
    {
        p = p->next;
        size--;
    }
    return p;
}
void palindrome(struct node *p, int size)
{
    int n = size, f = 0;
    struct node *bg, *lst;
    bg = p;
    lst = p;
    while (n > size / 2)
    {
        lst = bg;
        lst = last(lst, n);
        if (lst->data != p->data)
        {
            f = 1;
        }
        n--;
        p = p->next;
    }
    if (f == 0)
    {
        printf("Entered linked is a pallindrome.");
    }
    else
    {
        printf("Entered linked list is not a pallindrome.");
    }
}
int main()
{
    int size;
    printf("Enter number of nodes- ");
    scanf("%d", &size);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    create(head, size);
    palindrome(head, size);
    return 0;
}
