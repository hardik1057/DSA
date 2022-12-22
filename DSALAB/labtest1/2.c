#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int val;
    struct node *next;
};
typedef struct node node;
void link(struct node *a, struct node *b)
{
    a->next = b;
    b->prev = a;
}
void reverse(struct node **a)
{
    int n = 1;
    struct node *current = *a;
    while (current->next)
    {
        n++;
        current = current->next;
    }
    struct node *temp[n];
    current = *a;
    for (int i = 0; i < n; i++)
    {
        temp[i] = current;
        current = current->next;
    }
    for (int i = 0; i < (n / 2); i++)
    {
        struct node *t = temp[i];
        temp[i] = temp[n - 1 - i];
        temp[n - 1 - i] = t;
    }
    for (int i = 0; i < n; i++)
    {
        temp[i]->next = temp[i + 1];
        temp[i + 1]->prev = temp[i];
    }
    *a = temp[0];
    temp[0]->prev = NULL;
    temp[n - 1]->next = NULL;
}
void create_dlink(node **s)
{
    int n;
    struct node *nw, *q;
    printf("how many inputs:");
    scanf("%d", &n);
    if (*s == NULL)
    {
        nw = (struct node *)malloc(sizeof(struct node));
        printf("enter number:");
        scanf("%d", &nw->val);
        nw->prev = NULL;
        nw->next = NULL;
        *s = nw;
        n--;
    }
    while (n != 0)
    {
        q = (struct node *)malloc(sizeof(struct node));
        printf("enter number:");
        scanf("%d", &q->val);
        q->next = NULL;
        nw->next = q;
        q->prev = nw;
        nw = q;
        n--;
    }
}
void display(struct node *p)
{
    while (p->next != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("%d\n", p->val);
}
int main()
{
    struct node *list = NULL;
    create_dlink(&list);
    display(list);
    reverse(&list);
    display(list);
    return 0;
}
