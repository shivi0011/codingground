#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{

   int ret;
   int status;
   int parentid;
   int ccount=0;

   parentid = getpid();
   printf("parent id is %d \n ", parentid);

while(++ccount<=5)
{   
ret = fork();
if(ret<0)
{
perror("error in fork \n");
 exit(1);
}
if(ret>0)
{
printf("inside parent \n");
printf("child pid is %d \n",ret);
}
else
{
printf("child %d created \n",ccount);
exit(0);
} 
}//while
while(--ccount>0)
{
ret = waitpid(-1,&status,0); 
           if(ret>0) 
{
                   printf("child with pid %d terminated\n", ret); 
                   if(WIFEXITED(status))
                     printf("normal termination %d\n", WEXITSTATUS(status));
                   else
                     printf("abnormal termination \n");  
}
else 
{ 
          printf("Error in Excuting wait \n");
exit(1);
}
}
return(0);
}
