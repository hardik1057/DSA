//Given an array of integers, and a number ‘sum’. WAP to find the number of pairs of integers in the array whose sum is equal to ‘sum.
#include<stdio.h>
int sum(int *a,int n,int key)
{
	int i=0,count=0,j;
	for(i=0;i<n;i++)
    	{
    		int temp=a[i];
    		for(j=i+1;j<n;j++)
        		{
        			if((temp+a[j])==key)
            			{
            				printf("{%d,%d},",temp,a[j]);
            				count+=1;
            			}
        		}
    	}
	return count;
}
int main()
{
	int n,i,k;
	printf("Enter size of array- ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
    	{
    		printf("enter element %d- ",i+1);
    		scanf("%d",&a[i]);
    	}
	printf("Enter the number which should be equal to the sum of pair of intergers- ");
	scanf("%d",&k);
	int count=sum(a,n,k);
	if(count==0)
	    {
    		printf("no such pairs were found");
    	}
	else
    	{
    		printf("\n%d pairs were found and are mentioned above\n",count);
    	}
	return 0;
}