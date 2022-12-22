/*Write a menu driven program to perform the following
operations in a double linked list by using suitable user defined functions for each case.
a) Traverse the list forward 
b) Traverse the list backward 
c)Check if the list is empty
d) Insert a node at the certain position (at beginning/end/any position)
e) Delete a node at the certain position (at beginning/end/any position)
f) Delete a node for the given key 
g) Count the total number of nodes
h) Search for an element in the linked list*/
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
	int n;
	node *nw,*q;
	printf("Enter size of list- ");
	scanf("%d",&n);
	printf("Enter number- ");
	if(*s==NULL)
	{
		nw=(node *)malloc(sizeof(node));
		scanf("%d",&nw->data);
		nw->prev=NULL;
		nw->next=NULL;
		*s=nw;
		n--;
	}
	while(n!=0)
	{
		q=(node *)malloc(sizeof(node));
		scanf("%d",&q->data);
		q->next=NULL;
		nw->next=q;
		q->prev=nw;
		nw=q;
		n--;
	}
}
void forward(node *s)
{
	node *nw=s;
	while(nw!=NULL){
		printf("%d ",nw->data);
		nw=nw->next;
	}
}
void backward(node *s)
{
	node *head=s;
	while(head->next!=NULL)
	{
		head=head->next;
	}
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->prev;
	}
}
void listempty(node *s)
{
	if(s==NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("List is not empty");
	}
}
void insert(node **s,int k)
{
	int n;
	node *nw=(node *)malloc(sizeof(node));
	printf("Enter the number to be inserted- ");
	scanf("%d",&nw->data);
	if(k==1)
	{
		nw->next=(*s);
		nw->prev=NULL;
		(*s)=nw;
	}
	else
	{
		int t=1;
		node *h=(*s);
		while(h!=NULL)
		{
			t++;
			if(t==k)
			{
				nw->next=h->next;
				nw->prev=h;
				h->next=nw;
				break;
			}
		}
	}
	printf("Updated linked list is- ");
	forward((*s));
}
void delete_p(node **s,int k)
{
	if(k==1){
		node *nw=(*s);
		(*s)=nw->next;
		(*s)->prev=NULL;
		free(nw);
	}
	else{
		int t=1;
		node *h=(*s);
		while(h!=NULL)
		{
			t++;
			if(t==k)
			{
				node *nw=h->next;
				h->next=nw->next;
				h->next->prev=h;
				free(nw);
				break;
			}
			h=h->next;
		}
	}
	printf("Updated linked list is- ");
	forward((*s));
}
void delete_k(node **s,int k)
{
	int flag=0;
	if((*s)->data==k)
	{
		flag=1;
		node *nw=(*s);
		(*s)=nw->next;
		(*s)->prev=NULL;
		free(nw);
	}
	else{
		node *h=(*s);
		while(h!=NULL){
			if(h->next->data==k)
			{
				flag=1;
				node *nw=h->next;
				h->next=nw->next;
				h->next->prev=h;
				free(nw);
				break;
			}
			h=h->next;
		}
	}
	if(flag==0)
	{
		printf("Element not found");
	}else
	{
		printf("Updated linked list is- ");
		forward((*s));
	}
}
void num(node *s)
{
	int count=0;
	while(s!=NULL)
	{
		s=s->next;
		count++;
	}
	printf("Number of nodes present linked list is %d",count);
}
void search(node *s,int k)
{
	int flag=0;
	while(s!=NULL)
	{
		if(s->data==k)
		{
			flag=1;
			break;
		}
		s=s->next;
	}
	if(flag==1)
	{
		printf("Element found");
	}
	else
	{
		printf("Element not found");
	}
}
int main()
{
	node *head=NULL;
	create(&head);
	int key,choice;
	menu:
		printf("\n\n------Menu-----");
		printf("\n1)Traverse the list from front\n2)Traverse list from back\n3)Check if the list is empty or not");
		printf("\n4)Insert an element at any position\n5)Delete an element at any position\n6)Delete an element");
		printf("\n7)Count total number of nodes\n8)Search an element\n9)Exit\n\nEnter your choice- ");
		scanf("%d",&choice);
	switch(choice){
		case 1:printf("\nTraversing the list from front- ");
			   forward(head);
			   goto menu;
		case 2:printf("\nTraversing the list from back- ");
			   backward(head);
			   goto menu;
		case 3:listempty(head);
			   goto menu;
	    case 4:printf("\nEnter the position where you want to insert- ");
			   scanf("%d",&key);
	           insert(&head,key);
	           goto menu;
	    case 5:printf("\nEnter the position which you want to delete- ");
			   scanf("%d",&key);
			   delete_p(&head,key);
			   goto menu;
		case 6:printf("\nEnter the element which you want to delete- ");
			   scanf("%d",&key);
	 		   delete_k(&head,key);
	  		   goto menu;
	  	case 7:num(head);
	  		   goto menu;
	  	case 8:printf("\nEnter the element which you want to find- ");
			   scanf("%d",&key);
			   search(head,key);
			   goto menu;
		case 9:break;
	}
	return 0;
}