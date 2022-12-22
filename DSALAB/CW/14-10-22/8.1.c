// Write a menu driven program to implement Deques (both Inputrestricted and Output-restricted) operations such as Enqueue, Dequeue, Peek, 
//Display of elements, IsEmpty, IsFull using static array.
#include<stdio.h>
#include<stdlib.h>
void create(int *q,int n,int **f,int **b,int size)
{
	int i;
	for(i=0;i<n;i++)
    {
		if(i>=size)
        {
			printf("Sorry queue is full cannot take more inputs");
			break;
		}
		printf("Enter the element- ");
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
void enqueue_b(int *a,int *size,int n)
{
	if((*size)>=n)
    {
		printf("Sorry deque is full cannot take more inputs");
		return;
	}
	else
    {
		(*size)++;
		int key;
		printf("Enter the value to be inserted- ");
		scanf("%d",&key);
		a[(*size)-1]=key;
	}
}
void enqueue_f(int *a,int *size,int n)
{
	if((*size)>=n)
    {
		printf("Sorry deque is full cannot take more inputs");
		return;
	}
	else
    {
		(*size)++;
		int key,i;
		printf("Enter the value to be inserted- ");
		scanf("%d",&key);
		int len=*size;
		for(i=len-1;i>=1;i--)
        {
			a[i]=a[i-1];
		}
		a[0]=key;
	}
}
void dequeue_f(int *a,int n)
{
	int i;
	for(i=0;i<n-1;i++)
    {
		a[i]=a[i+1];
	}
}
void dequeue_b(int *a,int n)
{
	a[n-1]=0;
}
void peek(int *f)
{
	printf("Element present at the first is- %d",f[0]);
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
    {
		printf("deque is empty");
	}
	else
    {
		printf("deque is not empty");
	}
}
void isfull(int n,int size)
{
	if(n>=size)
    {
		printf("deque is full");
	}
	else
    {
		printf("deque is not full");
	}
}
int main()
{
	int n,size,choice;
	printf("Enter the size of the deque- ");
	scanf("%d",&size);
	int deque[size];
    for(int i=0;i<size;i++)
    {
        deque[i]=0;
    }
	printf("how many inputs you want to take:");
	scanf("%d",&n);
	int *front=deque,*rear=deque;
	create(deque,n,&front,&rear,size);
	menu:
		printf("\n1)Display\n2)Enqueue from back\n3)Enqueue from front\n4)Dequeue from front\n5)Dequeue from back");
		printf("\n6)Peek\n7)Check if deque is empty\n8)Check deque is full\n9)Exit.\nEnter your choice- ");
		scanf("%d",&choice);
	switch(choice)
    {
		case 1:display(front,n);
				goto menu;
		case 2:enqueue_b(deque,&n,size);
				rear= (deque+n-1);
				goto menu;
		case 3:enqueue_f(deque,&n,size);
				goto menu;
		case 4:dequeue_f(deque,n);
				n--;
				goto menu;
		case 5:dequeue_b(deque,n);
				n--;
				rear= (deque+n-1);
				goto menu;
		case 6:peek(deque);
				goto menu;
		case 7:isempty(deque,n);
				goto menu;
		case 8:isfull(n,size);
				goto menu;
		case 9:break;
	}
	return 0;
}