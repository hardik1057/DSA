// wap to search for an element in a single linked list and delete the node and print the node at the staring of the link listS
#include <stdio.h>
#include <stdlib.h>
int l;
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
void create_list(node *lst)
{
    int size;
    printf("Enter the size of link list- ");  
    scanf("%d",&size);
    l=size;
    printf("Enter elements into linked list- ");         
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
node *update(node *ptr,int num)
{
    node *nw,*head=ptr,*prev=ptr;
    ptr=ptr->next;
    int f=0;
    while(ptr!=NULL)
        {
            if(ptr->no==num)
                {
                    prev->next=ptr->next;
                    free(ptr);
                    nw=(node *)malloc(sizeof(node));
                    nw->no=num;
                    nw->next=head;
                    head=nw;
                    break;
                }
            prev=prev->next;
            ptr=ptr->next;
        }
    printf("Link list after updating- ");
    disp(ptr);
}
void main()
{
    printf("Hardik Chauhan \n21052904\n");
    node *head;
    head=(node *)malloc(sizeof(node));  
    create_list(head);
    printf("Original linked list- ");
    disp(head);
    int n;
    printf("\nEnter element to be searched for- ");
    scanf("%d",&n);
    head=update(head,n);
}