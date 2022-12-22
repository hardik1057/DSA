//Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void create_cq(struct node **f,struct node **b)
{
	int n;
	struct node *nw,*q;
	printf("Enter size of Circular queue- ");
	scanf("%d",&n);
    printf("Enter elements- ");
	if(*f==NULL)
    {
		nw=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&nw->data);
		nw->next=NULL;
		*f=nw;
		n--;
	}
	while(n!=0)
    {
		q=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&q->data);
		q->next=NULL;
		nw->next=q;
		nw=q;
		n--;
	}
	*b=nw;
	(*b)->next=(*f);
}
void display(struct node *s)
{
	struct node *nw=s;
	while(nw->next!=s)
    {
		printf("%d ",nw->data);
		nw=nw->next;
	}
	printf("%d",nw->data);
}
void enqueue(struct node **b,struct node *f)
{
	int key;
	printf("Enter the value to be inserted- ");
	scanf("%d",&key);
	struct node *nw=(struct node *)malloc(sizeof(struct node));
	nw->data=key;
	nw->next=f;
	(*b)->next=nw; 
	*b=nw; // jo naya node banaye usko wapis se last node banane k liye 
}
void dequeue(struct node **f,struct node *b)
{
	struct node *nw=(*f);
	(*f)=(*f)->next;
	free(nw);
	b->next=(*f);
}
void peek(struct node *f)
{
	printf("%d",f->data);
}
void isempty(struct node *f)
{
	if(f==NULL)
    {
		printf("Circular queue is empty");
	}
	else
    {
		printf("Circular queue is not empty");
	}
}
int main()
{
	struct node *front=NULL,*rear=NULL;
	int choice;
	create_cq(&front,&rear);
	menu:
		printf("\n\n-----MENU-----");
        printf("\n1)Display\n2)Enqueue\n3)Dequeue\n4)Peek\n5)Check if queue is empty");
        printf("\n6)Exit.\n\nEnter your choice- ");
        scanf("%d",&choice);
        printf("\n");
	switch(choice)
    {
		case 1:display(front);
				goto menu;
		case 2:enqueue(&rear,front);
				goto menu;
		case 3:dequeue(&front,rear);
				goto menu;
		case 4:peek(front);
				goto menu;
		case 5:isempty(front);
				goto menu;
		case 6:break;
	}
	return 0;
}