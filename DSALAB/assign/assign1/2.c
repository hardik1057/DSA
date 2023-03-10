//
#include <stdio.h>
#include <stdlib.h>
struct node{
    int no;
    struct node* next;
};
void swap(struct node* a){
    int n=1;
    struct node* current=a;
    while(current->next){
        n++;
        current=current->next;
    }
  struct node* temp[n];
  current=a;
    for(int i=0;i<n;i++){
        temp[i]=current;
        current=current->next;
    }
    for(int i=0;i<(n/2);i++){
        temp[i]->next=temp[n-i-1];
        temp[n-i-1]->next=temp[i+1];
    }
    temp[n/2]->next=NULL;
}
int main(){
    struct node* list=(struct node*)malloc(sizeof(struct node));
    list->next=NULL;
    int n;
    printf("Enter Size of List- ");
    scanf("%d",&n);
    struct node* copy=list;
    printf("Enter elements- ");
    for(int i=1;i<=n;i++){
        struct node* current=(struct node*)malloc(sizeof(struct node));
        int x;
        printf("Enter %d Value:\n",i);
        scanf("%d",&x);
        current->no=x;
        current->next=NULL;
        copy->next=current;
        copy=copy->next;
    }
    list=list->next;
    swap(list);
    printf("Swapped List- ");
    while(list){
        printf("%d ",list->no);
        list=list->next;
    }
    return 0;
}
