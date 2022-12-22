/*Write a program in C to create a double linked list having n (even number) nodes (the value of n will be given at the run time). Display the
nodes. Now, exchange the 1 st node with the n th node, 2 nd node with (n-1) th node, 3 rd node with (n-2) th , . . . likewise up to (n/2) th node.
At last, display all the nodes.*/
#include <stdlib.h>
#include <stdio.h>
struct dlink
{
    struct dlink *prev;
    int no;
    struct dlink *next;
};
typedef struct dlink node;
void create_dbl(node **s, int n)
{
    node *nw, *q;
    if (*s == NULL)
    {
        *s = (node *)malloc(sizeof(node));
        (*s)->prev = NULL;
        (*s)->no = n;
        (*s)->next = NULL;
    }
    else
    {
        q = *s;
        while (q->next != NULL)
            q = q->next;
        nw = (node *)malloc(sizeof(node));
        nw->no = n;
        nw->next = NULL;
        q->next = nw;
        nw->prev = q;
    }
}
void exchange(node **s, int n)
{
    int r;
    r = 1;
    int tmp;
    node *q, *p;
    p = *s;
    q = *s;
    while (q->next != NULL)
    {
        q = q->next;
    }
    while (r != (n / 2) + 1)
    {
        tmp = p->no;
        p->no = q->no;
        q->no = tmp;
        p = p->next;
        q = q->prev;
        r++;
    }
}
void disp(node *q)
{
    while (q != NULL)
    {
        printf("%d ", q->no);
        q = q->next;
    }
}
int main()
{
    node *head;
    int r, n, n1;
    printf("Enter size of list- ");
    scanf("%d", &r);
    n1 = r;
    head = NULL;
    printf("Enter elements- ");
    while (r != 0)
    {
        scanf("%d", &n);
        create_dbl(&head, n);
        r--;
    }
    printf("\nThe double linklist is- \t");
    disp(head);
    exchange(&head, n1);
    printf("\nThe linklist after swap is- ");
    disp(head);
    return 0;
}