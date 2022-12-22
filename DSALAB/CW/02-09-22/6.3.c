//WAP to convert infix to postfix
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
void push(struct node **s, char k)
{
    struct node *nw=(struct node*)malloc(sizeof(struct node));
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
    if (s==NULL)
        return '1';
    return s->data;
}
void pop(struct node **s)
{
    struct node *nw=(*s);
    (*s)=(*s)->next;
    free(nw);
}
int check(char c, struct node *s)
{
    switch (c)
    {
    case '*': if (top(s)=='/' || top(s)=='^' || top(s)=='*')
                return 0;
            else
                return 1;
            break;
    case '+': if (top(s)=='-' || top(s)=='^' || top(s)=='*' || top(s)=='/' || top(s)=='+')
                return 0;
            else
                return 1;
            break;
    case '-':if (top(s)=='-' || top(s)=='^' || top(s)=='*' || top(s)=='/' || top(s)=='+')
                return 0;
            else
                return 1;
            break;
    case '/':if (top(s)=='/' || top(s)=='^' || top(s)=='*')
                return 0;
            else
                return 1;
            break;
    case '^':if (top(s)=='^')
                return 0;
            else
                return 1;
            break;
    }
}
int main()
{
    char expression[40];
    printf("Enter the infix expression- ");
    scanf("%[^\n]s", expression);
    struct node *stack=NULL;
    int size=0, i, index=0;
    for (i=0;expression[i]!='\0';i++)
        size++;
    char result[size];
    for (i=0;i<size;i++)
    {
        if (expression[i]=='(')
            push(&stack, expression[i]);
        else if (expression[i]==')')
        {
            while (top(stack)!='(')
            {
                char add=top(stack);
                if (add=='1')
                {
                    printf("Stack is empty.");
                    break;
                }
                result[index]=add;
                pop(&stack);
                index++;
            }
            pop(&stack);
        }
        else if (expression[i]=='+' || expression[i]=='-' || expression[i]=='/' || expression[i]=='*' || expression[i]=='^')
        {
            if (check(expression[i], stack))
                push(&stack, expression[i]);
            else
            {
                while (!check(expression[i], stack))
                {
                    char ch=top(stack);
                    result[index]=ch;
                    pop(&stack);
                    index++;
                }
                push(&stack, expression[i]);
            }
        }
        else
        {
            result[index]=expression[i];
            index++;
        }
    }
    while(stack!=NULL)
    {
        result[index]=top(stack);
        pop(&stack);
        index++;
    }
    printf("Postfix expression- ");
    for (i=0;i<index;i++)
        printf("%c", result[i]);
    return 0;
}