//write a c program for reader and writer problem solution using semaphore between thread of a process;

#include<pthread.h>	 
#include<stdio.h>
#include<semaphore.h>

/*
semaphore.h contains :  
sem_init(sem_t * sem_name,int pshared,unsigned int value);
sem_init(&sem_name,0,0);	//create semaphore | return 0 if successful
sem_wait(sem_t *sem_name)	//decrements semaphore value
sem_post(sem_t *sem_name)	//increments semaphore value
	eg. sem_post(&sem_name);
sem_destroy(sem_t *sem_name);	//delete semaphore

*/

void *reader(void *ptr);
void *writer(void *ptr);

pthread_t thread1, thread2;

int flag = 1;
const int loopcount = 10;
sem_t cs_access;
sem_t readcount_access;
int readcount = 0;

int main(){

	//INITIALISE SEMAPHORES
	sem_init(&cs_access,0,1);		//only one thread/process can access at one time
	sem_init(&readcount_access,0,1);		//only one reader is there to read


	const char *mesg1="\nmessage 1";
	const char *mesg2="\nmessage 2";

	int err1,err2;
	err1 = pthread_create(&thread1,NULL,reader,mesg1);
	if(err1!=0){
		exit(1);
	}
	else{
		printf("\nThread1 created successfully");
		//printf("\nThread1 id in main thread\t:%d",err1);
	}

	err2 = pthread_create(&thread2,NULL,writer,mesg2);
	if(err2!=0){
		exit(1);
	}
	else{
		printf("\nThread2 created successfully");
		//printf("\nThread2 id in main thread\t:%d",err2);
	}

	printf("\nMain thread going to sleep...");

	sleep(1);

	//DESTROY SEMAPHORE
	sem_destroy(&cs_access);
	sem_destroy(&readcount_access);

	printf("\n\n");
	return 0;
}


//THREAD 1
void *reader(void *ptr){
	int count = loopcount;
	while(count--){
		char *msg;
		msg =(char *) ptr;

		//ENTRY SECTION
		sem_wait(&readcount_access);		
		readcount++;
		if(readcount==1){
			sem_wait(&cs_access);		
		}
		sem_post(&readcount_access);

		//CRITICAL SECTION
		printf("\n[READER] flag = %d",flag);		

		//EXIT SECTION
		sem_post(&cs_access);

	}
}

//THREAD 2
void *writer(void *ptr){
	int count = loopcount;
	while(count--){		
		char *msg;
		msg =(char *) ptr;
	
		//ENTRY SECTION
		sem_wait(&cs_access);


		//CRITICAL SECTION
		flag = flag^1;
		printf("\n[WRITER] flag = %d",flag);

		//EXIT SECTION
		sem_post(&cs_access);

	}
}








/*void *fun_msg(void *ptr){
	char *msg;
	msg =(char *) ptr;
	printf("%s",msg);
	pthread_t t_id = pthread_self();
	printf("\nThread id\t: %d",t_id);
	printf("\nThread block ends");

	if(pthread_equal(t_id,thread1)){
		printf("\nInside thread 1");
	}
	if(pthread_equal(t_id,thread2)){
		printf("\nInside thread 2");
	}
}*/
	
