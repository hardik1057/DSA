// WAP to delete duplicate numbers from a linked list
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
    while(lst != NULL)
        {
            printf("%d  ",lst->no);
            lst=lst->next;
        }
}
void create(node *lst)
{
    int num;
    printf("Enter the size of link list- ");  
    scanf("%d",&num);
    printf("Enter elements into the linked list- ");         
    while(num!=0)
    {
	    scanf("%d",&lst->no);
	    num--;
	    if(num==0)
	       break;
	    lst->next=(node *)malloc(sizeof(node));
	    lst=lst->next;
	}
	lst->next=NULL;
}
node *rem(node *ptr)
{
    node *lst=ptr,*dup,*temp;
    int f=0;
    while(lst!=NULL)
        {
            node *l2=lst;
            while(l2!=NULL)
                {
                    while(l2->next!=NULL && lst->no==l2->next->no)
                        {
                            f=1;
                            dup=l2->next;
                            l2->next=dup->next;
                            free(dup);
                        }
                    l2=l2->next;
                }
            lst=lst->next;
        }
    if (f==0)
       printf("No duplicate numbers found");
    else
        {
            printf("\nLink list after removing duplicates- ");
            disp(ptr);
        }
}
void main()
{
    printf("Hardik Chauhan \n21052904\n");
    node *head;
    head=(node *)malloc(sizeof(node));  
    create(head);
    printf("Original link list- ");
    disp(head);
    rem(head);
}
