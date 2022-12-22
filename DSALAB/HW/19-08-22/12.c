//WAP to findout the kth smallest and kth largest element stored in a dynamic array of n integers, where k<n.
#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int size)
{
	int i,j;
	for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
                {
                    if(a[i]>a[j])
                        {
                            int temp=a[i];
                            a[i]=a[j];
                            a[j]=temp;
                        }
                }
        }
}
int main()
{
	int size,i;
	printf("Enter the size of the array- ");
	scanf("%d",&size);
	int *arr=(int*)malloc(size*sizeof(int));
	printf("Enter %d elements- ",size);
	for(i=0;i<size;i++)
            scanf("%d",arr+i);
	sort(arr,size);
	int key;
	printf("Enter the position you want- ");
	scanf("%d",&key);
	if(key>size)
		printf("Wrong input");
	else
		printf("%dth smallest element is %d and %dth highest element is %d",key,arr[key-1],key,arr[size-key]);
	return 0;
}