//WAP to add and multiply two sparse matrices.
//only addition
#include<stdio.h>
void create_triple(int *arr,int *t,int n)
{
	int i,j,c=1;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				{
					if(*((arr+i*n) + j)!=0)
						{
							*((t+c*3)+0)=i;
							*((t+c*3)+1)=j;
							*((t+c*3)+2)=*((arr+i*n)+j);
							c+=1;
						}
				}
		}
}
void display(int *t,int count)
{
	int i,j;
	for(i=0;i<=count;i++)
		{
			for(j=0;j<3;j++)
				{
					printf("%d\t",*((t+i*3) + j));
				}
			printf("\n");
		}
}
int add(int result[10][3],int a[10][3],int b[10][3],int n1,int n2)
{
	int count=0,n=(n1>n2)?n1:n2,i=1;
	for(i;i<=n;i++)
	{
		if(i>n1 || i>n2)
		{
			count++;
			continue;
		}
		if((a[i][0]>b[i][0]) || (a[i][1]>b[i][1])){
			count+=2;
		}
		else if((a[i][0]<b[i][0]) || (a[i][1]<b[i][1])){
			count+=2;
		}
		else{
			count++;
		}
	}
	int j,z=1;
	i=1;
	for(j=0;j<count;j++){
		if(j>n1){
			result[j][0]=b[z][0];
			result[j][1]=b[z][1];
			result[j][2]=b[z][2];
			z++;
			continue;
		}
		else if(j>n2){
			result[j][0]=a[i][0];
			result[j][1]=a[i][1];
			result[j][2]=a[i][2];
			i++;	
		}
		else if((a[i][0]>b[z][0]) || a[i][1]>b[z][1]){
			result[j][0]=b[z][0];
			result[j][1]=b[z][1];
			result[j][2]=b[z][2];
			z++;
		}
		else if((a[i][0]<b[z][0]) || a[i][1]<b[z][1]){
			result[j][0]=a[i][0];
			result[j][1]=a[i][1];
			result[j][2]=a[i][2];
			i++;
		}
		else{
			result[j][0]=b[z][0];
			result[j][1]=b[z][1];
			result[j][2]=b[z][2]+a[i][2];
			z++;
			i++;
		}
	}
	return count;
}
int main(){
	int n,m,i,j,count1=0,count2=0;
	printf("enter the order for 1st sparse matrix:");
	scanf("%d",&n);
	int sm1[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("enter element:");
			scanf("%d",&sm1[i][j]);
			if(sm1[i][j]!=0){
				count1++;
			}
		}
	}
	int t_sm1[count1+1][3];
	t_sm1[0][0]=n;
	t_sm1[0][1]=n;
	t_sm1[0][2]=count1;
	create_triple((int *)sm1,(int *)t_sm1,n);
	printf("enter the order for 2nd sparse matrix:");
	scanf("%d",&m);
	int sm2[m][m];
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("enter element:");
			scanf("%d",&sm2[i][j]);
			if(sm2[i][j]!=0){
				count2++;
			}
		}
	}
	int t_sm2[count2+1][3];
	t_sm2[0][0]=m;
	t_sm2[0][1]=m;
	t_sm2[0][2]=count2;
	create_triple((int *)sm2,(int *)t_sm2,m);
	printf("1st sparse matrix triplet representation:\nrow\tcol\tnum.\n");
	display((int *)t_sm1,count1);
	printf("\n2nd sparse matrix triplet representation:\nrow\tcol\tnum.\n");
	display((int *)t_sm2,count2);
	int r[20][3];
	int count=add(r,t_sm1,t_sm2,count1,count2);
	count--;
	printf("\nresultant addition of the two given matrix:\nrow\tcol\tnum.\n");
	display((int *)r,count);
	return 0;
}
