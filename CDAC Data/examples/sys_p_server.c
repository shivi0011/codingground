#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

#define KEY1 3333

#define BBUF_SZ 1024

struct payload{
  char op;               //unused field
  char file_data[256];   //char message1[256];
  char cli_npipe[256];   //char message[256];
};

struct msgbuf {

 long mtype; 

 struct payload data;
};

void sig_chld(int signo)
{

  int ret1;

  while(1){
      //Note : signal handlers are not supposed to block
      //
      //waitpid() is a blocking system call API, by default 
      //since we are using it in signal handler, we cannot
      //use it as it is !!! we must use a special flag 
      //that will ensure that waitpid() will never block 
      //assuming we do not use flags, and use 0 for the
      //last parameter, waitpid() will block current 
      //process context when no child of this process
      //is currently in zombie state !!! 
      //if we use WNOHANG, this is overcome - with WNOHANG,
      //if there are no children of this priocess 
      //in zombie state, waitpid() will return 0, does 
      //not block !!! this is the reason for using 
      //WNOHANG !!! 


      //WNOHANG flag is added such that 
      //waitpid() will not block, if there are children and
      //none are in terminated(zombie) state - it will return 0
      //summary - if waitpid() is called with WNOHANG, ret values are:
      //+ve - if a child is cleaned-up
      //0   - if there are children and none are in zombie state
      //-1  - if there are no children in any state or there is an error
      ret1 = waitpid(-1,&status,WNOHANG);
      if(ret1<0) break;
      if(ret1==0) break;

  }

}      


int main()
{


   int ret,ret1,ret2,ret3,id1,id2,fd,npfd;
   struct msgbuf msgbuf1;
   struct payload pld1;
   struct sigaction act1,act2;
   sigset_t set1,set2;

   char *rdbuf;

   //install signal handler for SIGCHLD using sigaction

   sigfillset(&set1);                 //library call
   sigdelset(&set1,SIGCHLD);          //library call
   sigprocmask(SIG_SETMASK,&set1,&set2);//system call //mask is used outside signal 
                                                     //handlers

   //act1.sa_handler = SIG_DFL; //install the default action 
   //act1.sa_handler = SIG_IGN; //action will be to ignore 
   act1.sa_handler = sig_chld; //install a signal handler
   act1.sa_flags = 0;
   sigfillset(&act1.sa_mask);//mask used during the signal handler's execution only
   //you must call sigaction() for each signal that be specially 
   //handled by the system/process
   sigaction(SIGCHLD,&act1,&act2);
   //sigaction(SIGINT,&act1,NULL);

   rdbuf = malloc(1024);
   if(!rdbuf) { 
     printf("error in malloc");
     exit(1);
   }

   ret = mkfifo(argv[1],0600);//create server fifo if needed 
   if(ret<0 && errno != EEXIST) { perror(""); exit(2); }
   while(1){ //server continues to serve
   npsfd = open(argv[1], O_RDONLY);   
   if(npsfd<0) { 
       temp_errno = errno; perror(""); if(temp_errno == EINTR) continue;  
       exit(3); }

   ret = read(npsfd,&pld1,sizeof(pld1));

   if(ret<0) { perror(""); exit(4); }
   
   if(ret==0) continue;  //end of file case is handled without redundant children
   //message has come
   close(npsfd);
   ret = fork(); //create a child per request

   if(ret<0) { perror(""); exit(5); }
   if(ret>0) { close(npsfd); continue; }

   if(ret==0) {
        close(npsfd);  //closing the server name pipe 
	ffd = open(pld1.file_data,O_RDONLY); //opening the data-file
        //add error checking
        npcfd = open(pld1.cli_npipe,O_WRONLY); //opening the npipe of client
        while( (ret=read(ffd,buf,sizeof(buf))) > 0){
                write(npcfd,buf,ret);
        }
        exit(0);
    }	 
  } //while loop

   id1 = msgget(KEY1,IPC_CREAT|0600);

   if(id1<0) { 
      perror("error in msgq creation"); 
      exit(2); 
   }

   while(1)
   {
       //waitpid(-1,&status,0);     //wrong place -- 1
  
       //server waits for message from clients
       //
       ret1 = msgrcv(id1,&msgbuf1,sizeof(msgbuf1.data),0,0);
       
       if(ret1<0 && errno == EINTR) continue;
       if(ret1<0) { 
          perror("error in receiving message"); 
          exit(3);
       }

       //fork and let the child handle the client
       ret1 = fork();
       if(ret1<0) { perror("error in fork"); exit(4); }
       if(ret1>0) {

                //waitpid(-1,&status,0);   //wrong place -- 2
                continue;
       }
       if(ret1==0)
       {
             printf("S..the operation value is %d\n",\
                     msgbuf1.data.op);
       	     printf("S..the filename is %s\n",\
                     msgbuf1.data.file_data);
             printf("S..the client fifo name is %s\n",\
                     msgbuf1.data.cli_np);

             fd = open(msgbuf1.data.file_data,O_RDONLY);
             if(fd<0) { perror("error in opening data file");
                         exit(4);
             }
             npfd = open(msgbuf1.data.cli_np,O_WRONLY);
             if(npfd<0) { 
                  perror("error in opening named\
                          pipe");
                  exit(5);
             }

             printf("S...just after file is open and \
                     fifo is open\n");

             if(msgbuf1.data.op){
       
             do{

               ret2 = read(fd,rdbuf,BBUF_SZ);//reading from a reg. file
               if(ret2<0) { 
               perror("error in reading from datafile");       
               exit(6); //can be somethingelse
               }
               if(ret2 == 0) break;
               //if you write to the pipe and no read descriptors to
               //the pipe are open, the system will generate SIGPIPE
               //signal to the process that is writing 
               ret3 = write(npfd,rdbuf,ret2); //writing to a FIFO
             } while(1);

              printf("S...just after writing the file data\n");
              close(npfd);
             }//if data.op==1
             exit(0);       

          } //child ends here
    }// the server while

exit(0);

}
        
           


      


    
    

