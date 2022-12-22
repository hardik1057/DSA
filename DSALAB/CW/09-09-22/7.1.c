/*Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek (display the front content), Display of elements, 
IsEmpty, IsFull using static array.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create_q(int *q,int n,int **f,int **b,int size)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i>=size)
		{
			printf("\nSorry queue is full");
			break;
		}
		printf("Enter the elements- ");
		scanf("%d",(q+i));
	}
	*b=(q+size-1);
}
void display(int *s,int n)
{
	int i=0;
	while(i<n && s[i]!=0)
	{
		printf("%d ",*(s+i));
		i++;
	}
}
void enqueue(int *a,int *size,int n)
{
	if((*size)>=n)
	{
		printf("\nSorry queue is full");
		return;
	}
	else
	{
		(*size)++;
		int key;
		printf("\nEnter number to be inserted- ");
		scanf("%d",&key);
		a[(*size)-1]=key;
	}
}
void dequeue(int *a,int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
}
void peek(int *f)
{
	printf("\nElement present at the first is- %d",f[0]);
}
void isempty(int *a,int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\nQueue is empty");
	else
		printf("\nQueue is not empty");
}
void isfull(int n,int size)
{
	if(n>=size)
		printf("\nQueue is full");
	else
		printf("\nQueue is not full");
}
int main()
{
	int n,size,choice;
	printf("Enter the size of the queue- ");
	scanf("%d",&size);
	int queue[size];
	for (int i=0;i<size;i++)
	{
		queue[i]=0;
	}
	printf("Enter number of inputs- ");
	scanf("%d",&n);
	int *front=queue,*rear=queue;
	create_q(queue,n,&front,&rear,size);
	menu:
		printf("\n\n----MENU----");
		printf("\n1)Display\n2)Enqueue\n3)Dequeue\n4)Peek\n5)Check if queue is empty\n6)Check if queue is full or not\n7)Exit\n\nEnter your choice- ");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1:display(front,n);
				goto menu;
		case 2:enqueue(queue,&n,size);
				*rear= *(queue+n-1);
				goto menu;
		case 3:dequeue(queue,n);
				n--;
				goto menu;
		case 4:peek(queue);
				goto menu;
		case 5:isempty(queue,n);
				goto menu;
		case 6:isfull(n,size);
				goto menu;
		case 7:break;
	}
	return 0;
}