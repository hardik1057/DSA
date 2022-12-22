#include <stdio.h>
#include <stdlib.h>
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
    printf("\nEnter the data to be inserted (press -1 to add no new node):");
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
void count(struct node *h, int *c)
{
    if (h == NULL)
    {
        return;
    }
    (*c)++;
    count(h->left, c);
    count(h->right, c);
}
void cont_leaf(struct node *h, int *d)
{
    if (h == NULL)
    {
        return;
    }
    else if (h->left == NULL && h->right == NULL)
    {
        (*d)++;
    }
    cont_leaf(h->left, d);
    cont_leaf(h->right, d);
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
void del_leaf(struct node *h)
{
    if (h == NULL)
    {
        return;
    }
    else if (h->right->left == NULL && h->right->right == NULL)
    {
        free(h->right);
        h->right = NULL;
    }
    else if (h->left->left == NULL && h->left->right == NULL)
    {
        free(h->left);
        h->left = NULL;
    }
    del_leaf(h->left);
    del_leaf(h->right);
}

int main()
{
    struct node *tree;
    tree = create();
    int cnt = 0;
    count(tree, &cnt);
    printf("%d number of nodes are present in the binary tree", cnt);
    int c = 0;
    cont_leaf(tree, &c);
    printf("\n%d number of leaf nodes are present in the binary tree", c);
    printf("\nbinary tree before leaf node deletion:");
    inorder(tree);
    del_leaf(tree);
    printf("\nbinary tree after leaf node deletion:");
    inorder(tree);
    return 0;
}