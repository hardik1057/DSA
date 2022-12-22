//WAP to reverse a stack with using extra stack.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **s,int k)
{
	struct node *nw=(struct node *)malloc(sizeof(struct node));
	nw->data=k;
	if((*s)==NULL)
    {
		nw->next=NULL;
		(*s)=nw;
	}
	else
    {
		nw->next=(*s);
		(*s)=nw;
	}
}
void display(struct node *s)
{
	while(s!=NULL)
    {
		printf("%d ",s->data);
		s=s->next;
	}
}
void reverse(struct node **t1,struct node **t2,int n)
{
	struct node *arr[n];
	int i=0;
	struct node *nw=(*t1);
	while(nw!=NULL)
    {
		arr[i]=nw;
		nw=nw->next;
		i++;
	}
	for(i=0;i<n;i++)
    {
		nw=arr[i];
		if(*t2==NULL)
        {
			nw->next=NULL;
			*t2=nw;
		}
		else
        {
			nw->next=(*t2);
			*t2=nw;
		}
	}
}
int main()
{
	int size,x,key,temp;
	printf("Enter size of stack- ");
	scanf("%d",&size);
	temp=size;
	struct node *top1=NULL,*top2=NULL;
    printf("Enter the elements- ");
    while(size!=0)
        {
            scanf("%d",&key);
            push(&top1,key);
            size--;
        }
	printf("Original stack- ");
	display(top1);
	reverse(&top1,&top2,temp);
	printf("\nReversed stack- ");
	display(top2);	
	return 0;
}
