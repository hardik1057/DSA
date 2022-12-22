// Write an algorithm to sort the elements inside a stack using only push and pop operation.Any number of additional stacks may be used.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void push(struct node **s,int k){
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
int top(struct node *s)
{
	return s->data;
}
void pop(struct node **s)
{
	struct node *nw=(*s);
	(*s)=(*s)->next;
	free(nw);
}
void display(struct node *s)
{
	while(s!=NULL){
		printf("%d ",s->data);
		s=s->next;
	}
}
int isempty(struct node *s)
{
	if(s==NULL)
    {
		return 1;
	}
	else
    {
		return 0;
	}
}
void sortinsert(struct node **s,int x)
{
	if(isempty(*s)||x<top(*s))
    {
		push(s,x);
		return;
	}
	int temp=top(*s);
	pop(s);
	sortinsert(s,x);
	push(s,temp);
}
void sortstack(struct node **s)
{
	if(!isempty(*s))
    {
		int x=top(*s);
		pop(s);
		sortstack(s);
		sortinsert(s,x);
	}
	else
    {
		return;
	}
}
int main(){
	int n,key;
	printf("How many elements- ");
	scanf("%d",&n);
	struct node *top=NULL;
    printf("Enter the elements- ");
    while(n!=0)
    {
		scanf("%d",&key);
		push(&top,key);
		n--;
	}
	printf("Original stack- ");
	display(top);
	sortstack(&top);
	printf("\nSorted stack- ");
	display(top);
	return 0;
}
