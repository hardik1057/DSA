#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void create(struct node *lst,int n)
{
	while(n!=0)
    {
		int k;
		printf("enter the element-");
		scanf("%d",&k);
		lst->data=k;
		if(n==1)
			lst->next=NULL;
		else
            {
                lst->next=(struct node *)malloc(sizeof(struct node));
                lst=lst->next;
            }
		n--;
	}
}
void display(struct node *lst)
{
	while(lst->next!=NULL)
        {
            printf("%d ",lst->data);
            lst=lst->next;
        }
	printf("%d",lst->data);
}
void insert_key(struct node **lst,int k)
{
	if(k==1)
        {
            struct node *nw=(struct node *)malloc(sizeof(struct node));
            int n;
            printf("Enter the number to be inserted- ");
            scanf("%d",&n);
            nw->data=n;
            nw->next=*lst;
            *lst=nw;
        }
	else
        {
            int c=1;
            struct node *h=(*lst);
            while(h!=NULL)
            {
                c++;
                if(c==k)
                    {
                        struct node *nw=(struct node *)malloc(sizeof(struct node));
                        int n;
                        printf("Enter the number to be inserted- ");
                        scanf("%d",&n);
                        nw->data=n;
                        nw->next=h->next;
                        h->next=nw;
                    }
                h=h->next;
            }
        }
}
void delete_key(struct node **lst,int k)
{
	int c=0;
	if((*lst)->data==k)
        {
            struct node *nw=(*lst);
            (*lst) =nw->next;
            free(nw);
            c=1;
        }
	else
        {
            struct node *h=(*lst);
            while(h!=NULL)
                {
                    if(h->next->data==k)
                        {
                            struct node *nw=h->next;
                            h->next=h->next->next;
                            free(nw);
                            c=1;
                            break;
                        }
                    h=h->next;
                }
        }
	if(c==1)
		printf("Element deleted");
	else
		printf("Element not found.");
}  
void delete_pos(struct node **lst,int k)
{
	struct node *h=(*lst);
	if(k==1)
        {
            struct node *nw=(*lst)->next;
            free(*lst);
            *lst=nw;
        }
	else
        {
            int c=1;
            while(h!=NULL)
                {
                    c++;
                    if(c==k)
                        {
                            struct node *nw=h->next;
                            h->next=nw->next;
                            free(nw);
                        }
                    h=h->next;
                }
        }
}
void empty(struct node *lst)
{
	if(lst=NULL)
		printf("\nList is empty");
	else
		printf("\nList is not empty");
}
int count(struct node *lst)
{
	int n=0;
	while(lst!=NULL)
        {
            n++;
            lst=lst->next;
        }
	return n;
}
void check(struct node *lst,int c)
{
	int count=0;
	while(lst!=NULL)
        {
            if(lst->data==c)
                {
                    printf("Element found");
                    count=1;
                    break;
                }
            lst=lst->next;
        }
	if(count==0)
		printf("Element not found");
}
int main ()
{
    int opt,num,cnt;
    menu:
        printf("\n\n-----------MENU------------");
        printf("\n1)Create a new link list.");
        printf("\n2)Display the link list.");
        printf("\n3)Inserting a number at any position of the link list.");
        printf("\n4)Deleting a number at any position of the link list.");
        printf("\n5)Check whether the list is empty or not.");
        printf("\n6)Count the number of nodes.");
        printf("\n7)Deleting the number at key position of the list.");
        printf("\n8)Check wether a number is present in the link list.");
        printf("\n9)Exit the code.\n");
        printf("\nEnter your choice- ");
        scanf("%d",&opt);
    switch(opt)
        {
            case 1: printf("\nEnter size of linked list- ");
			        scanf("%d",&num);
                    struct node *list;
			        list=(struct node *)malloc(sizeof(struct node));
			        create(list,num);
                    goto menu;
            case 2: printf("\nInserted linklist-");
                    display(list);
                    goto menu;
            case 3: printf("\nEnter the position you want to delete- ");
                    scanf("%d",&num);   
                    insert_key(&list,num);
                    goto menu;
            case 4: printf("\nEnter the position you want to delete- ");
                    scanf("%d",&num);
                    delete_pos(&list,num);
                    goto menu;
            case 5: empty(list);
                    goto menu;
            case 6: cnt=count(list);
                    printf("\nTotal nodes in the list is- %d",cnt);
                    goto menu;
            case 7: printf("\nEnter the number you want to delete- ");
                    scanf("%d",&num);
                    delete_key(&list,num);
                    goto menu;
            case 8: printf("\nEnter the element you want to search for- ");
                    scanf("%d",&num);
                    check(list,num);
                    goto menu;
            case 9: break;  
        }
    return 0;
}