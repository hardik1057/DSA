// Write a menu driven program to implement Deques (both Inputrestricted and Output-restricted) operations such as Enqueue, Dequeue, Peek, 
//Display of elements, IsEmpty, IsFull using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void create_q(struct node **f,struct node **b)
{
	int n;
	struct node *nw,*q;
	printf("Enter size- ");
	scanf("%d",&n);
    printf("Enter elements-");
    if(*f==NULL)
    {
		nw=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&nw->data);
		nw->next=NULL;
		nw->prev=NULL;
		*f=nw;
		n--;
	}
	while(n!=0)
    {
		q=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&q->data);
		q->next=NULL;
		nw->next=q;
		q->prev=nw;
		nw=q;
		n--;
	}
	*b=nw;
}
void display(struct node *s)
{
	struct node *nw=s;
	while(nw!=NULL)
    {
		printf("%d ",nw->data);
		nw=nw->next;
	}
}
void enqueue_back(struct node **b)
{	
	int key;
	printf("Enter the value to be inserted- ");
	scanf("%d",&key);
	struct node *nw=(struct node *)malloc(sizeof(struct node));
	nw->data=key;
	nw->next=NULL;
	(*b)->next=nw;
	*b=nw;
}
void enqueue_front(struct node **f)
{
	int key;
	printf("Enter the value to be inserted- ");
	scanf("%d",&key);
	struct node *nw=(struct node *)malloc(sizeof(struct node));
	nw->data=key;
	nw->prev=NULL;
	(*f)->prev=nw;
	nw->next=(*f);
	(*f)=nw;
}
void dequeue_front(struct node **f)
{
	struct node *nw=(*f);
	(*f)=(*f)->next;
	free(nw);
}
void dequeue_back(struct node **b)
{
	struct node *nw=(*b);
	(*b)=(*b)->prev;
	(*b)->next=NULL;
	free(nw);
}
void peek(struct node *f)
{
	printf("%d",f->data);
}
void isempty(struct node *f)
{
	if(f==NULL)
    {
		printf("Deque is empty");
	}
	else
    {
		printf("Deque is not empty");
	}
}
int main()
{
	struct node *front=NULL,*rear=NULL;
	int choice;
	create_q(&front,&rear);
	menu:
		printf("\n\n-----MENU-----");
        printf("\n1)Display\n2)Enqueue from front\n3)Enqueue from back\n4)Dequeue from front\n5)Dequeue from back");
		printf("\n6)Peek\n7)Check if queue is empty\n8)Exit. \n\nEnter your choice- ");
		scanf("%d",&choice);
        printf("\n");
	switch(choice)
    {
		case 1:display(front);
				goto menu;
		case 2:enqueue_front(&front);
				goto menu;
		case 3:enqueue_back(&rear);
				goto menu;
		case 4:dequeue_front(&front);
				goto menu;
		case 5:dequeue_back(&rear);
				goto menu;
		case 6:peek(front);
				goto menu;
		case 7:isempty(front);
				goto menu;
		case 8:break;
	}
	return 0; 
}