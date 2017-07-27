#include<stdio.h>     
#include<unistd.h>     // for fork() and getpid()
#include<sys/types.h>  // for 
#include<stdlib.h>     // for exit()
#include<sys/wait.h>   // for wait()

int findmax(int a[],int,int);

int max(int a[],int l,int r)
{
int i,max;

max=a[l];
for(i=l;i<=r;i++)
{	
	if(a[i]>max)
	max=a[i];

}
return max;
}


int main(int argc, char **argv)      // taking number of elements of array as command line arguments
{
int n,i,l,r,PL,PR,max1,max2,mid,out,max11,max22;

n=atoi(argv[1]);
int a[n];

srand(time(NULL));
for(i=0;i<n;i++)
{
	a[i]=rand()%127;
	printf("%d\n",a[i]);
}
l=0;r=n-1;
printf("\nFinal maximum is : %d\n",findmax(a,l,r));

}

int findmax(int a[],int l, int r)
{
int n,i,PL,PR,m1,m2,mid,out,maximum,RET1,RET2;
pid_t pid,ppid;

	if(l==r)
	return a[l];

	else if(l==r-1)
	return (a[l]>a[r]?a[l]:a[r]);
	
	else
	{
	mid=(l+r)/2;
	PL=fork();
	//sleep(1);
	    	if(PL<0)
		perror((char*)PL);
		if(PL==0)   //i.e. child created successfully
		{
		printf("\nin PL");
		m1 = max(a,l,mid);
		printf("\nProcess ID is :%d \nParent Process ID is %d\nMaximum of the provided number is %d\n\n",getpid(),getppid(),m1);
		exit(m1);	
		}	
	
	

	PR=fork();
	sleep(1);
	    	if(PR<0)
		perror((char*)PL);
		if(PR==0)   //i.e. child created successfully
		{
		printf("\nin PR");
		m2 = max(a,mid+1,r);
		printf("\nProcess ID is :%d \nParent Process ID is %d\nMaximum of the provided number is %d\n\n",getpid(),getppid(),m2);
		exit(m2);	
		}
	

	}	

//:::::in parent::::::    parents of both PL and PR will wait for the completion of their execution
waitpid(PL,&m1,0);
RET1=WEXITSTATUS(m1);    //need to catch the exit status of each of the maximum number found by above childs
waitpid(PR,&m2,0);        
RET2=WEXITSTATUS(m2);    //It will exit from wait once it receives the status of m2 from above child PR as on receiving the final value it will exit from wait and parent
				//will complete its execution

maximum=RET1>RET2?RET1:RET2;
return maximum;

}








