/*Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void create(struct node **f,struct node **b)
{
	int n;
	struct node *nw,*q;
	printf("Enter size of queue- ");
	scanf("%d",&n);
    printf("Enter element- ");
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
}
void display(struct node *s)
{
	struct node *nw=s;
	printf("\nEntered queue is- ");
    while(nw!=NULL)
    {
		printf("%d ",nw->data);
		nw=nw->next;
	}
}
void enqueue(struct node **b)
{
	int key;
	printf("\nEnter element to be inserted- ");
	scanf("%d",&key);
	struct node *nw=(struct node *)malloc(sizeof(struct node));
	nw->data=key;
	nw->next=NULL;
	(*b)->next=nw;
	*b=nw;
}
void dequeue(struct node **f)
{
	struct node *nw=(*f);
	(*f)=(*f)->next;
	free(nw);
}
int peek(struct node *f)
{
	printf("First node is- %d",f->data);
}
void isempty(struct node *f)
{
	if(f==NULL)
		printf("\nQueue is empty");
	else
		printf("\nQueue is not empty");
}
int main()
{
	struct node *front=NULL,*rear=NULL;
	int choice;
	create(&front,&rear);
	menu:
		printf("\n\n----MENU----");
		printf("\n1)Display\n2)Enqueue\n3)Dequeue\n4)Peek\n5)Check if queue is empty\n6)Exit\n\nEnter your choice- ");
		scanf("%d",&choice);
	switch(choice)
    {
		case 1: display(front);
			    goto menu;
		case 2: enqueue(&rear);
				goto menu;
		case 3: dequeue(&front);
				goto menu;
		case 4: peek(front);
				goto menu;
		case 5: isempty(front);
				goto menu;
		case 6: break;
	}
	return 0;
}