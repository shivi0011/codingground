#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{

   int ret,status,parentid;

   parentid = getpid();

   ret = fork();
 
   if(ret<0){ perror("error in fork"); exit(1); }

   //if(getpid() == parentid){

   if(ret>0){ 
          //any useful code of the parent process can exist here
          printf("in parent context pid is %d and ppid is %d\n", 
                                    getpid(), getppid()); 

           //first parameter is set to -1 such that 
           //waitpid() will clean-up any child process of 
           //this parent process, which is currently in terminated state  !!
           //the first parameter can also be +ve - in this case, 
           //waitpid() will cleanup only the specific child process !!!
           //most common use is to set first parameter to -1 
	   //also refer to manual page of waitpid()  
           //second parameter is used to extract the termination/exit status code
           //of the child process - waitpid() system call API fills the
           //status field when the system call API is invoked !!!
           //last field is the flags field - currently unused - in most 
           //cases, flags field will be set to 0 - meaning, default
           //behaviour of the system call API !!! if you really need to
           //use flags, refer to manual page of waitpid() !!!


	  ret = waitpid(-1,&status,0); 
           if(ret>0) {
                   printf("child with pid %d cleaned-up\n", ret); 
                   if(WIFEXITED(status))
                     printf("normal termination and the exit status is %d\n", WEXITSTATUS(status));
                   else
                       printf("the process terminated abnormally\n");  
                   //assuming that the parent process has collected the exit status code
                   //of the first child and the compilation is successful, 
                   //create another child process and load the newly created binary 

          }
           pause(); //used to block a process, unconditionally  !!!
           //sleep(10);   
	   exit(0); 
   }

  else { 
          printf("in child context pid is %d and ppid is %d\n", 
                                    getpid(), getppid()); 
	   
  pause();    
           //we want the child to launch a compiler

   //if vi is launched, this process will start executing vi
   //when vi terminates normally, this child process will terminate !!!

   //ret = execl("/usr/bin/vi", "vi", "fork2n.c", NULL);  
  

   ret = execl("/usr/bin/gcc","gcc","fork1n.c", "-o", "fork1n",NULL);  
   if(ret<0) { perror("error in execl"); exit(33); }     
   printf("my program is successfully loaded \n"); 

 

//   pause();    
   exit(0);  //this exit will never run - this is added only for 
             //formality !!!
  }

return 0;
   
}


