// WAP to create a circular double linked list of n nodes and display the linked list by using suitable user defined
// functions for create and display operations.
#include<stdio.h>
#include<stdlib.h>
struct dlink
{
	struct dlink *prev;
	int data;
	struct dlink *next;
};
typedef struct dlink node;
void create(node **s)
{
	int size;
	node *nw,*q;
	printf("Enter size of list- ");
	scanf("%d",&size);
    printf("Enter elements- ");
    if(*s==NULL)
        {
            nw=(node *)malloc(sizeof(node));
            scanf("%d",&nw->data);
            nw->prev=nw;
            nw->next=nw;
            *s=nw;
            size--;
        }
	while(size!=0)
        {
            q=(node *)malloc(sizeof(node));
            scanf("%d",&q->data);
            q->next=(*s);
            nw->next=q;
            q->prev=nw;
            (*s)->prev=q;
            nw=q;
            size--;
        }
}
void display(node *s)
{
	node *nw=s;
	while(nw->next!=s)
        {
            printf("%d ",nw->data);
            nw=nw->next;
        }
	printf("%d\n",nw->data);
}
int main()
{
	node *head=NULL;
	create(&head);
	display(head);
	return 0;
}