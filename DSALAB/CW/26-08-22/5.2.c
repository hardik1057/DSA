// WAP to reverse the sequence elements in a double linked list.
#include <stdlib.h>
#include <stdio.h>
struct dlink
{
    struct dlink *prev;
    int no;
    struct dlink *next;
};
typedef struct dlink node;
void create(node **s, int n)
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
void disp(node *q)
{
    while (q->next != NULL)
        {
            q = q->next;
        }
    while (q != NULL)
        {
            printf("%d ", q->no);
            q = q->prev;
        }
}
int main()
{
    node *head;
    int r, n;
    printf("Enter number of nodes- ");
    scanf("%d", &r);
    head = NULL;
    printf("Enter elements- ");
    while (r != 0)
        {
            scanf("%d", &n);
            create(&head, n);
            r--;
        }
    printf("The reversed double linklist is- ");
    disp(head);
    return 0;
}