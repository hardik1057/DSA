//Write a menu driven program to perform the following operations of a stack using linked list by using suitable user defined functions for each
//case. a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int no;
    struct stack *next;
};
typedef struct stack node;
void push(node **s, int n)
{
    node *nw;
    if (*s == NULL)
    {
        *s = (node *)malloc(sizeof(node));
        (*s)->no = n;
        (*s)->next = NULL;
    }
    else
    {
        nw = (node *)malloc(sizeof(node));
        nw->no = n;
        nw->next = *s;
        *s = nw;
    }
}
void disp(node *q)
{
    printf("\nEntered/ updated stack is- ");
    while (q != NULL)
    {
        printf("%d  ", q->no);
        q = q->next;
    }
}
void empty(node*q)
{
    if (q==NULL)
        printf("\nStack is empty");
    else 
        printf("\nStack is not empty");
}

int main ()
{
    node *top;
    int r, n,choice,new;
    top = NULL;
    printf("Enter size of stack- ");
    scanf("%d", &r);
    printf("Enter elements- ");
    while (r != 0)
        {
            scanf("%d", &n);
            push(&top, n);
            r--;
        }
    menu :
        printf("\n\n------MENU------");
        printf("\n1)If stack is empty\n2)Display stack\n3)Push\n4)Pop\n5)Exit");
        printf("\n\nEnter your choice- ");
        scanf("%d", &choice);
    switch(choice)
        {
            case 1: empty(top);
                    goto menu;
            case 2: disp(top);
                    goto menu;
            case 3: printf("\nEnter number to be inserted- ");
                    scanf("%d",&new);
                    push(&top,new);
                    goto menu;
            case 4: pop(&top);
                    goto menu; 
            case 5: break;
        }
    return 0;
}