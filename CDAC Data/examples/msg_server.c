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

 long mtype;           //must be this, always - used to hold message type 
                       //of received message or sent message !!!

 struct payload data;  //payload space - as required by developer !!!
};

void sig_chld(int signo)
{

  int ret1;

  while(1){
      //Note : signal handlers are not supposed to block
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

   //msgget() enables to create a new mq object 
   //KEY identifies a mq object uniquely, in the system 
   //flags are used to control the behaviour of msgget()
   //IPC_CREAT is needed to create a new mq object - if 
   //object does not exit, create - otherwise, use what exists !!!
   //0600 is the permissions in this context - we are allowing 
   //read/write permissions to the owner of this message queue -
   //currently, use what is given - we will understand more
   //during file permissions !!
   //if msgget() is successful, returns id of the message queue
   //object !!!id will be used for further operations, not KEY  !!!
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
       //first parameter is the id - we do not use KEY - that 
       //is the peculiarity of implementation !!
       //second parameter is pointer to a user-space message
       //buffer related object - it must follow strict rules
       //see the object defined above !!!
      //third parameter is the size of the payload in the 
      //message buffer related object - strict - must be followed 
      //fourth parameter is the type of message to be received - 
      //if it is 0, receive the oldest message
      //in the message queue !!! if it is non-zero, we have the
      //flexibility to set the type of message of our interest - 
      //we will see more of this during sending - if we set to 
      //non-zero value, oldest message of that type will be received- 
      //otherwise, receiving process is blocked until the oldest 
      //message of the given type is received !!!
      //last field(fifth parameter) is flags - mostly set to 0
      //- if needed, refer to man page !!
      //if return value is -ve or 0 , there is error 
      //if return value is +ve, a message was successfuly retrieved
      //from the message queue 
      //the actual size of the received message is returned in 
      //return value - a +ve no !!! we pass the max possible 
      //message that we may receive using 3rd param - actual 
       //message size is passed back to us using ret - 
      //we must use ret's value to actually interpret the
      //payload - if we do not interpret correctly, we may 
      //use garbage data !!!
       ret1 = msgrcv(id1,&msgbuf1,sizeof(msgbuf1.data),2,0);
       
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
        
           


      


    
    

