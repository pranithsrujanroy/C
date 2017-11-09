#include<pthread.h>
#include<stdio.h>

void *fun_msg(void *ptr);

pthread_t thread1, thread2;

int main(){
	const char *mesg1="\nmessage 1";
	const char *mesg2="\nmessage 2";

	int err1,err2;
	err1 = pthread_create(&thread1,NULL,fun_msg,mesg1);
	if(err1!=0){
		exit(1);
	}
	else{
		printf("\nThread1 created successfully");
		//printf("\nThread1 id in main thread\t:%d",err1);
	}

	err2 = pthread_create(&thread2,NULL,fun_msg,mesg2);
	if(err2!=0){
		exit(1);
	}
	else{
		printf("\nThread2 created successfully");
		//printf("\nThread2 id in main thread\t:%d",err2);
	}

	printf("\nMain thread going to sleep...");

	sleep(1);

	printf("\n\n");
	return 0;
}

void *fun_msg(void *ptr){
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
}
	
