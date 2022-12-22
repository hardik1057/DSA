//WAP to find whether an array is subset of another array.
#include<stdio.h>
void subarray(int *a,int *b,int l,int m)
{
	int i,j,flag=0;
	for(i=0;i<m;i++)
        {
            int check=b[i];
            flag=1;
            for(j=0;j<l;j++)
                {
                    if(check==a[j])
                        {
                            flag=0;
                        }
                }
            if(flag==1)
                {
                    break;
                }
        }
	if(flag==0)
        {
            printf("\nthe given array is the subset of the first array");
        }
    else
        {
            printf("\nthe given array is not the subset of the first array");
        }
}
int main()
{
	int n,m,i;
	printf("How many inputs for sample array- ");
	scanf("%d",&n);
	int a[n];
    printf("Enter elements- ");
	for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
	printf("how many inputs for another array- ");
	scanf("%d",&m);
	int b[m];
    printf("Enter elements- ");
	for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
	if(m>n)
        {
            printf("the given array is not a subset of the 1st array");
        }
	else
        {
            subarray(a,b,n,m);
        }
	return 0;
}
