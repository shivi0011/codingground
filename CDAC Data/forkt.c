#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int arr(int a[],int p,int q)
{
	int i,mid,left,right,max1,max2,max11,max22;
	if((q-p)<=1)
	{
		int max=a[p];
		for(i=p+1;i<=q;i++){if(max<a[i])max=a[i];}
		printf("\nreturned max:%d,",max);
		return max;
	}
	else
	{
		mid=(p+q)/2;
		left=fork();
	if(left<0){exit(1);}
	if(left==0)
	{
	max1=arr(a,p,mid);printf(" max1=>>%d",max1);
	exit(max1);
	}
	right=fork();
	if(right<0)	
	{
		exit(1);
	}
	if(right==0)
	{
		max2=arr(a,mid+1,q);printf(" max2=>>%d",max2);
			exit(max2);
	}
	waitpid(left,&max1,0);
	waitpid(right,&max2,0);
	if(WIFEXITED(max1))
	max11=WEXITSTATUS(max1);
	if(WIFEXITED(max1))
	max22=WEXITSTATUS(max2);
	printf("\nMAX 1 = %d max2 = %d  ",max11,max22);
	}//outer else
}

void main()
{
int a[]={1,2,3,4,5,6,7,8,9,0};
arr(a,0,9);
}
