/*Two brackets are considered to be a matched pair if an opening bracket (i.e., (, [, or { ) occurs to the left of a closing bracket (i.e., ), ],
or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and (). A matching pair of brackets is not balanced
if the set of brackets it encloses are not matched. Write an algorithm to determine whether the input sequence of brackets is balanced or
not. If a string is balanced, it print YES on a new line; otherwise, print NO on a new line. You can use any data structures known to
you (i.e., stack, array, linked list) to solve the problem. Example: Input: {[()]} and Output: YES Input: {[(])} and Output: NO*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *next;
};
void push(struct node **s,char k){
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
char top(struct node *s)
{
	if(s==NULL)
    {
		return '1';
	}
	return s->data;
}
void pop(struct node **s)
{
	struct node *nw=(*s);
	(*s)=(*s)->next;
	free(nw);
}
int check(char c,struct node **s)
{
	switch(c)
    {
		case '(':push(s,c);
					return 2;
		case '[':push(s,c);
					return 2;
		case '{':push(s,c);
					return 2;
		case ']':if(top((*s))=='[')
                {
					return 1;
				}
				return 0;
		case ')':if(top((*s))=='(')
                {
					return 1;
				}
				return 0;
		case '}':if(top((*s))=='{')
                {
					return 1;
				}
				return 0;
	}
}
int main(){
	char e[20];
	printf("Enter the expression- ");
    scanf("%[^\n]s",e);
	struct node *stack=NULL;
	int size=0,i,flag=0;
	for(i=0;e[i]!='\0';i++)
    {
		size++;
	}
	for(i=0;i<size;i++)
    {
		int b=check(e[i],&stack);
		if(b==1)
        {
			pop(&stack);
		}
		else if(b==2)
        {
			continue;
		}
		else
        {
			flag=1;
			break;
		}
	}
	if(flag==0)
    {
		printf("Yes\n");
	}
	else
    {
		printf("No\n");
	}
	return 0;
}