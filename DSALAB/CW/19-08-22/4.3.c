//WAP to count the number of occurences of a node in a singular linked list of n nodes
#include <stdio.h>
#include <stdlib.h>
struct linklist
{
    int no;
    struct linklist *next;
};
typedef struct linklist node;
void disp(node *lst)
{
    while(lst!=NULL)
        {
            printf("%d ",lst->no);
            lst=lst->next;
        }
}
void create(node *lst)
{
    int size;
    printf("Enter the number of nodes you want to create- ");  
    scanf("%d",&size);
    printf("Enter numbers into the linked list- ");         
    while(size!=0)
        {
            scanf("%d",&lst->no);
            size--;
            if(size==0)
            break;
            lst->next=(node *)malloc(sizeof(node));
            lst=lst->next;
        }
	lst->next=NULL;
}
int occurence(node *ptr,int num)
{
    int ctr=0;
    while(ptr!=NULL)
        {
            if(ptr->no==num)
                ctr++;
            ptr=ptr->next;
        }
    return ctr;
}
void main()
{
    printf("Hardik Chauhan \n21052904\n");
    node *head;
    head=(node *)malloc(sizeof(node));  
    create(head);
    printf("Original linked list- ");
    disp(head);
    int search;
    printf("\nEnter element whose occurence you want to know- ");
    scanf("%d",&search);
    int ctr=occurence(head,search);
    printf("Number of occurences of %d in linked list is %d\n",search,ctr);
}
