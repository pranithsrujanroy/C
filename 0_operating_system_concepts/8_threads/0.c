#include<pthread.h>
#include<stdio.h>

void *fun_msg(void *ptr);

int main(){
	const char *mesg1="message 1";
	const char *mesg2="message 2";

	pthread_t thread1, thread2;
	int err1,err2;
	err1 = pthread_create(&thread1,NULL,fun_msg,NULL);
	if(err1!=0){
		exit(1);
	}
	else{
		printf("Thread created successfully");
	}
	err2 = pthread_create(&thread2,NULL,fun_msg,NULL);

	return 0;
}

void *fun_msg(void *ptr){
	char *msg;
	msg =(char *) ptr;
	printf("%s",msg);
}

