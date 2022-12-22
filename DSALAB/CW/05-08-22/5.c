//Given an array of integers, WAP to count number of sub-arrays (of size more than one) that are strictly consecutively increasing.
#include<stdio.h>
int sub(int *a,int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
    {
		if(i==n-1)
            break;
		else if(a[i+1]>a[i])
        {
			int j=i;
			while(a[j+1]>a[j] && j<n-1)
            {
				count++;
				if(j<n-1)
                    j++;
				int k;
				for(k=i;k<=j;k++)
                    {
                        if(k==i)
                          printf("{%d,",a[k]);
                        else if(k==j)
                          printf("%d},",a[k]);
                        else
                          printf("%d,",a[k]);
                    }
			}
		}
	}
	return count;
}
int main()
{
	int num,i;
	printf("Enter number of inputs- ");
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++)
        {
            printf("Enter element %d- ",i+1);
            scanf("%d",&arr[i]);
        }
	int count=sub(arr,num);
	printf("\nthere are %d increasing subarray and are mentioned above",count);
	return 0;
}