/*1. Write the following menu driven program for the binary search tree 0. Quit 1. Create2. In-Order Traversal3. Pre-Order Traversal4. Post-Order 
traversal 5. Search 6. Find Smallest Element 7. Find Largest Element 8. Deletion of Tree*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    int key;
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted (press -1 to add no new node)- ==");
    scanf("%d", &key);
    if (key == -1)
    {
        nw = NULL;
        return nw;
    }
    else
    {
        nw->data = key;
        printf("Enter the left child of %d- ", key);
        nw->left = create();
        printf("Enter the right child of %d- ", key);
        nw->right = create();
        return nw;
    }
}
void inorder(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    inorder(h->left);
    printf("%d ", h->data);
    inorder(h->right);
}
void pre(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    printf("%d ", h->data);
    pre(h->left);
    pre(h->right);
}
void post(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    post(h->left);
    post(h->right);
    printf("%d ", h->data);
}
void search(struct node *h,int key, int *f)
{
    if (h == NULL)
    {
        return;
    }
    else if (h->data == key)
    {
        (*f) = 1;
        return;
    }
    search(h->left, key, f);
    search(h->right, key, f);
}
void smallest(struct node *h, int *s)
{
    if (h == NULL)
    {
        return;
    }
    else if (h->data < *(s))
    {
        *s = h->data;
    }
    smallest(h->left, s);
    smallest(h->right, s);
}
void largest(struct node *h, int *s)
{
    if (h == NULL)
    {
        return;
    }
    else if (h->data > *(s))
    {
        *s = h->data;
    }
    largest(h->left, s);
    largest(h->right, s);
}
void deltree(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    deltree(h->left);
    deltree(h->right);
    free(h);
}
int main()
{
    struct node *tree;
    int key,flag=0,choice;
    menu:
        printf("\n\n---MENU---");
        printf("\n1)Quit\n2)Create\n3)In-order\n4)Pre-Order\n5)Post-Order\n6)Search\n7)Smallest element\n8)Largest elment\n9)Deletion of Tree");
        printf("\n\nEnter your choice- ");
        scanf("%d",&choice);
    switch(choice)
        {
            case 1: break;
            case 2: tree=create();
                    goto menu;
            case 3: printf("\nInorder- ");
                    inorder(tree);
                    goto menu;
            case 4: printf("\nPre-order-");
                    pre(tree);
                    goto menu;
            case 5: printf("\nPost-order- ");
                    post(tree);
                    goto menu;
            case 6: printf("\nEnter element to be searched- ");
                    scanf("%d",&key);
                    search(tree,key,&flag);
                    if (flag == 0)
                        {
                            printf("Element not found");
                        }
                    else
                        {
                            printf("Element found");
                            flag=0;
                        }
                    goto menu; 
            case 7: int small=tree->data;
                    smallest(tree,&small);
                    printf("\nSmallest element- %d", small);
                    goto menu; 
            case 8: int larg=tree->data;
                    largest(tree,&larg);
                    printf("\nLargest element- %d",larg);
                    goto menu; 
            case 9: deltree(tree);
                    tree=NULL;
                    goto menu;
        }
    return 0;
}