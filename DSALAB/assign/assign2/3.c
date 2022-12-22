//Construct a linked list that represents a polynomial expression with double variables and then write an algorithm that display the content of 
//the linked list by using user defined function.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef, expo, check;
    struct node *next;
};
void create(struct node **h)
{
    int n;
    printf("How many terms- ");
    scanf("%d", &n);
    while (n != 0)
    {
        struct node *nw = (struct node *)malloc(sizeof(struct node)), *q = *h, *cur = nw;
        printf("Enter the exponential power of the variable- ");
        scanf("%d", &nw->expo);
        printf("Enter 1 if another variable is present otherwise press 0- ");
        scanf("%d", &nw->check);
        if (nw->check)
        {
            nw->coef = 1;
            nw->next = (struct node *)malloc(sizeof(struct node));
            nw = nw->next;
            printf("Enter the exponential power of the variable- ");
            scanf("%d", &nw->expo);
            printf("Enter the coefficient of the variable- ");
            scanf("%d", &nw->coef);
            nw->check = 0;
        }
        else
        {
            printf("Enter the coefficient of the variable- ");
            scanf("%d", &nw->coef);
        }
        if (*h == NULL)
        {
            (*h) = cur;
        }
        else
        {
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = cur;
        }
        nw->next = NULL;
        n--;
    }
}
void display(struct node *h)
{
    while (h != NULL)
    {
        if (h->check == 1)
        {
            int co = (h->coef) * (h->next->coef);
            printf("%dx^%dy^%d +", co, h->expo, (h->next)->expo);
            h = h->next->next;
        }
        else
        {
            printf("%dx^%d +", h->coef, h->expo);
            h = h->next;
        }
    }
}
int main()
{
    struct node *poly = NULL;
    create(&poly);
    printf("Entered polynomial is- ");
    display(poly);
    return 0;
}
