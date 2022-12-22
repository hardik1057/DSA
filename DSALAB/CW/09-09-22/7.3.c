// WAP using a function to reverse a queue by using stack.
#include <stdlib.h>
#include <stdio.h>
struct queue
{
    int no;
    struct queue *next;
};
typedef struct queue node;
void addque(node **f, node **r, int n)
{
    node *nw;
    if (*f == NULL)
    {
        *f = (node *)malloc(sizeof(node));
        (*f)->no = n;
        (*f)->next = NULL;
        *r = *f;
    }
    else
    {
        nw = (node *)malloc(sizeof(node));
        nw->no = n;
        nw->next = NULL;
        (*r)->next = nw;
        *r = nw;
    }
}
void disp(node *q)
{
    while (q != NULL)
    {
        printf("%d  ", q->no);
        q = q->next;
    }
}
int del_que(node **f, node **r)
{
    int a;
    node *nw;
    nw = *f;
    a = nw->no;
    *f = nw->next;
    free(nw);
    if (*f == NULL)
        *r = NULL;
    return (a);
}
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
int pop(node **s)
{
    int a;
    node *nw;
    if ((*s) == NULL)
        printf("Stack is empty ");
    else
    {
        nw = *s;
        a = (*s)->no;
        (*s) = (*s)->next;
        free(nw);
    }
    return (a);
}
int main()
{
    node *front, *rear, *top, *front1, *rear1;
    top = NULL;
    int size, num, n1, n2, n3, n4;
    printf("Enter size of queue- ");
    scanf("%d", &size);
    n2 = n3 = size;
    front = rear = front1 = rear1 = NULL;
    printf("Enter elements- ");
    while (size != 0)
    {
        scanf("%d", &num);
        addque(&front, &rear, num);
        size--;
    }
    printf("Entered queue is- ");
    disp(front);
    while (n2 != 0)
    {
        n1 = del_que(&front, &rear);
        push(&top, n1);
        n2--;
    }
    printf("\nQueue in reverse is- ");
    while (n3 != 0)
    {
        n4 = pop(&top);
        addque(&front, &rear, n4);
        n3--;
    }
    disp(front);
    return 0;
}