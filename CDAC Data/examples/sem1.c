#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define KEY1 1234

union semun {
             int val;                  /* value for SETVAL */
             struct semid_ds *buf;     /* buffer for IPC_STAT, IPC_SET */
             unsigned short *array;    /* array for GETALL, SETALL */
                                       /* Linux specific part: */
             struct seminfo *__buf;    /* buffer for IPC_INFO */
       };


int main()

  {

    int ret1, ret2, id1, id2;
    union semun u1;
    struct sembuf sboa[2];
    unsigned short ary1[3],ary[3] = { 50,0,1};

    //here, we create a semaphore object and a semaphore inside
    //the semaphore object 

    id1 = semget(KEY1, 1, IPC_CREAT|0600);
    //id1 = semget(KEY1, 3, IPC_CREAT|0600);
    if(id1<0) { perror("error in semaphore creation"); exit(1); }    

 
    //we must initialize the semaphore inside a semaphore object !!!

    u1.val = 1;
    semctl(id1,0,SETVAL,u1);
    //semctl(id1,1,SETVAL,u1);

    //fourth parameter in this systemcall API is ignored !!!
    //return value gives the current semaphore value requested
    //via this system call API !!!

    ret1 = semctl(id1,0,GETVAL); 
    printf("1..before decrement..the value of sem 0 is %lu\n",ret1);
   

    /*u1.val = 50;

    semctl(id1,0,SETVAL,u1); 
    u1.val = 0;
    semctl(id1,1,SETVAL,u1); 
    u1.val = 1;
    semctl(id1,2,SETVAL,u1); 
     

    ret1 = semctl(id1,0,GETVAL); 
    printf("the value of sem 0 is %lu\n",ret1); 
    ret1 = semctl(id1,1,GETVAL); 
    printf("the value of sem 1 is %lu\n",ret1);
    ret1 = semctl(id1,2,GETVAL); 
    printf("the value of sem 2 is %lu\n",ret1);*/

    //either above or below
    //u1.array = ary;
    
    //semctl(id1,0,SETALL,u1);

    //u1.array = ary1;

    //semctl(id1,0,GETALL,u1);

    //printf("the values are %lu .. %lu .. %lu\n", ary1[0],
    //	   ary1[1],ary1[2]);

     //operate on 0 
    sboa[0].sem_num = 0;  //we are operating on the first semaphore
    sboa[0].sem_op = -1;  //the operation is decrement operation 
    sboa[0].sem_flg = 0;  //normally, flags can be set to 0 


    semop(id1, sboa, 1);


    ret1 = semctl(id1,0,GETVAL); 
    printf("2..after decrement..the value of sem 0 is %lu\n",ret1);


    //operate on 0 and 2 
    //sboa[0].sem_num = 0;
    //sboa[0].sem_op = -1;
    //sboa[0].sem_flg = 0;

    //sboa[1].sem_num = 2;
    //sboa[1].sem_op = -1;
    //sboa[1].sem_flg = 0;


    //semop(id1, sboa, 2); 

    /*semctl(id1,0,GETALL,u1);

    printf("the values are %lu .. %lu .. %lu\n", ary1[0],
	   ary1[1],ary1[2]);

    //operate on 0 and 2 
    sboa[0].sem_num = 1;
    sboa[0].sem_op = -1;
    sboa[0].sem_flg = 0;*/

    sboa[1].sem_num = 0;
    sboa[1].sem_op =  +1;
    sboa[1].sem_flg = 0;


    semop(id1, sboa, 1);

    ret = semctl(id1,0,GETVAL);

    printf("3..after increment ..the value of sem 0 is %lu\n",ret);

    semctl(id1,0,IPC_RMID); //to delete or destroy the 
                            // semaphore object and all
                            // all semaphores in it 
    

}

