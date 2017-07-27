#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>
/* 0COMPILE WITH THE FOLLOWING COMMAND 
	gcc -Wall -D_GNU_SOURCE mutex_simple.c -o mutex -lpthread

	vi  /usr/include/features.h 
/////////////////////////////////////////////////////////// */

/* If _GNU_SOURCE was defined by the user, turn on all the other features.  
#ifdef _GNU_SOURCE
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE 1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE  1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE        200112L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE  600
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED 1
# undef  _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE    1
# undef  _BSD_SOURCE
# define _BSD_SOURCE    1
# undef  _SVID_SOURCE
# define _SVID_SOURCE   1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE 1
#endif

//////////////////////////////////////////////////////

	vi /usr/include/pthread.h 
 
///////////////////////////

{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
#ifdef __USE_UNIX98
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
#endif

//////////////////////////////////////////////////////////

*/
pthread_mutex_t m1;

	//create a object of mutex

//sem_t sem1;

pthread_cond_t eq_cv1,dq_cv2;  //enqueue and dequeue

pthread_t th_id1,th_id2;// two threads from pthread

//void cleanup1(void *arg1)

struct job_head { 
      unsigned int queue_count;
      struct job *next;

}job_head1;


struct job
{
	char str1[2048];
	struct job *next;
};

//struct job* job_queue;

//receiver or consumer
void *thread_func1(void *arg)
{
	while(1)
	{
		struct job* next_job;

        	pthread_mutex_lock(&m1);

                while(job_head1.queue_count < 5)
                       pthread_cond_wait(&dq_cv2,&m1);
                while(1){
			if(job_head1.next == NULL)
			{
				next_job = NULL;
                                break;
			}
			else
			{
				next_job = job_head1.next;
				job_head1.next = job_head1.next->next;
                        	job_head1.queue_count--;
     printf("in dequeue count is %d\n", job_head1.queue_count);
     printf("the string is %s\n", next_job->str1);
                                free(next_job);
                         
                	}   
		  }//inner-while

                pthread_cond_signal(&eq_cv1);                

		pthread_mutex_unlock(&m1);

	}//outer-while
	pthread_exit(NULL);
	return(NULL);
}

//sender or producer

void *thread_func2(void *arg)
{
	struct job *new_job;
//	new_job = (struct job *)malloc(sizeof(struct job));
         
	while(1)
	{

            	pthread_mutex_lock(&m1);
                while(job_head1.queue_count >= 5)  //add the condition
                     pthread_cond_wait(&eq_cv1,&m1);
                  
  new_job = (struct job *)malloc(sizeof(struct job));   
	
 read(STDIN_FILENO,new_job->str1,sizeof(new_job->str1)); //take user input in a local buffer
    
//		printf("Enter the string to be Queued \n");
                
	//	gets(new_job->str1);
        //	strcpy(new_job->str1,"ravivek");
		if(job_head1.next == NULL)
                {
                    job_head1.next = new_job;
                    new_job->next = NULL;
                }

                else{
                     struct job *temp = job_head1.next;
                     while(temp->next != NULL)
                            temp = temp->next;
                     temp->next = new_job;
                     new_job->next = NULL;
                }         

                job_head1.queue_count++;

                printf("in enqueue count is %d\n", job_head1.queue_count);

                if(job_head1.queue_count >=5) 
                         pthread_cond_signal(&dq_cv2);
       
		pthread_mutex_unlock(&m1);

                //sem_post(&sem1);

	//	sched_yield();

	}
	pthread_exit(NULL);
}



int main()
{
	int ret1,ret2;
	pthread_mutexattr_t ma1;
	pthread_attr_t tha1,tha2;
	int policy1,polciy2;
	struct sched_param p1;


        job_head1.queue_count = 0;
        job_head1.next = NULL;
	//alarm(300);
	printf("I am in Main Thread and PID is %lu .. PPID is %lu\n",getpid(),getppid());
        //ptr to semaphore object
        //process shared field - 0, if it is PROCESS_PRIVATE
        //                       1, if it is PROCESS_SHARED  
        //the initial value of the semaphore count = 0
        //sem_init(&sem1,0,0);

	pthread_attr_init(&tha1); // initialize attribute object - default
	pthread_mutexattr_init(&ma1);//default

	pthread_mutexattr_settype(&ma1,PTHREAD_MUTEX_NORMAL);
	//pthread_mutexattr_settype(&ma1,PTHREAD_MUTEX_ERRORCHECK);
	
	//pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m1,&ma1);

        pthread_cond_init(&eq_cv1,NULL); //the condition variable
                                      //is initialized to def. attributes
	

        pthread_cond_init(&dq_cv2,NULL); //the condition variable


	pthread_attr_setschedpolicy(&tha1,SCHED_FIFO); //policy attribute
	p1.sched_priority = 10;
	pthread_attr_setschedparam(&tha1,&p1); //sched. param attrib- priority
	ret1 = pthread_create(&th_id1,&tha1,thread_func1,NULL);
	if(ret1)     
	{
		printf("error in thread creation\n");
		exit(1);
	}
	printf("thread created\n");

	policy1 = SCHED_FIFO;
	p1.sched_priority = 15;

	ret1 = pthread_setschedparam(pthread_self(),policy1,&p1); //changing priority of main thread

	ret1 = pthread_create(&th_id2,&tha1,thread_func2,NULL);
	if(ret1)
	{
		printf("error in thread creation\n");
		exit(1);
	}

	printf("thread2 created\n");

	pthread_join(th_id1,NULL);
	pthread_join(th_id2,NULL);
	
	exit(0);
}
