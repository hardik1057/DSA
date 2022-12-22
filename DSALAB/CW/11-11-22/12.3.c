/*Given an array “container[]” and integer “hunt”. WAP to find whether “hunt” is present in container[] or not. If present, then triple the value 
of “hunt” and search again. Repeat these steps until “hunt” is not found. Finally return the value of “hunt”.*/
#include<stdio.h>
int main()
{
	int n,i,hunt,flag=0,check=1;
	printf("Enter the size of the array- ");
	scanf("%d",&n);
	int container[n];
	printf("Enter the elements into the array- ");
	for(i=0;i<n;i++)
    {
		scanf("%d",&container[i]);
	}
	printf("Enter the element to be searched- ");
	scanf("%d",&hunt);
	while(check==1)
    {
		for(i=0;i<n;i++)
        {
			if(container[i]==hunt)
            {
				flag=1;
				hunt=hunt*3;
			}
		}
		if(flag==0)
        {
			printf("%d \n",hunt);
			check=0;
		}
		flag=0;
	}
	return 0;                          
}