//Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
// a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop
#include<stdio.h>
#include<stdlib.h>
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
            printf("\nStack is empty");
	    }
	else
        {
            printf("\nStack is not empty");
        }
}
void display(int *a,int n)
{
	printf("\nEntered stack is- ");
	for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
}
void push(int **a,int n,int k)
{
	int *nw=(int *)malloc((n+1)*sizeof(int)),*old=*a;
	nw[0]=k;
	for(int i=0;i<n;i++)
        {
            nw[i+1]=old[i];
        }
	*a=nw;
}
void pop(int **a,int n)
{
	int *nw=(int *)malloc((n-1)*sizeof(int)),*old=*a;
	for(int i=0;i<n-1;i++)
        {
            nw[i]=old[i+1];
        }
	*a=nw;
}
int main()
{
	int size,t=0,choice,key;
	printf("Enter size of stack- ");
	scanf("%d",&size);
	int *arr=(int *)malloc(sizeof(int));
    printf("Enter elements- ");
    while(t!=size)
        {
            t++;
            scanf("%d",&key);
            push(&arr,t,key);
        }
	menu:
        printf("\n\n------MENU------");
        printf("\n1)If stack is empty\n2)Display stack\n3)Push\n4)Pop\n5)Exit");
        printf("\n\nEnter your choice- ");
        scanf("%d", &choice);
    switch (choice)
        {
            case 1: isempty(arr,size);
                    goto menu;
            case 2: display(arr,size);
                    goto menu;
            case 3: printf("\nEnter the element to be inserted- ");
                    scanf("%d",&key);
                    push(&arr,size,key);
                    size++;
                    goto menu;
            case 4: pop(&arr,size);
                    size--;
                    goto menu;
            case 5:break;
	    }
	return 0;	
}