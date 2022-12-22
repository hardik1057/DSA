//Write a program to rearrange the elements of an array of n integers such that all even numbers are followed by all odd numbers
#include<stdio.h>
int modify(int *a,int size)
{
	int i,f=0,count=0;
	for(i=0;i<size;i++)
	{
		count++;
		if(a[i]%2!=0)
			{
				int j=i;
				while(a[j]%2!=0 && j<(size-1))
					{
						j++;
						count++;
					}
				if(a[j]%2!=0)
					{
						f=1;
						break;
					}
				else
					{
						int temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				count++;
			}
		if(f==1)
    			break;
	}
	return count;
}
void display(int *a,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
int main()
{
	int n,i,steps;
	printf("Enter number of elements- ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
    	{
    		printf("Enter element %d- ",i+1);
    		scanf("%d",&arr[i]);
    	}
	printf("Original array- ");
	display(arr,n);
	steps=modify(arr,n);
	printf("\nModified array- ");
	display(arr,n);
	printf("\nNo of steps it took %d",steps);
	return 0;
}