//write a program to print all semaphores values of a set
#include<stdio.h>	//for printf
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>


#define SIZE 3

union semun{
	int val;
	struct semid_ds *buf;
	int *array;
	}arg;

int main(){
	int i;
	int n;
	key_t key;
	int arg1[SIZE] = {12,24,5};
	int arg2[SIZE] = {0,0,0}; 

	printf("\nValues in array at initialisation :\t");
	for(i=0;i<SIZE;i++)
		printf("%d ",arg2[i]);

	int sem_id=semget(key,5,0666|IPC_CREAT);
	arg.array=arg1;
	printf("\nValues in sem array at assignment :\t");
	for(i=0;i<SIZE;i++)
		printf("%d ",*(arg.array+i));
	int flag = semctl(sem_id,SIZE,SETALL,arg.array);

	if(flag == -1){
		printf("Semaphore control failed");
		return 1;
	}

	flag = semctl(sem_id,SIZE,GETALL,arg2);
	if(flag == -1){
		printf("Semaphore control failed");
		return 1;
	}

	printf("\nValues in array after copying :\t\t");
	for(i=0;i<SIZE;i++)
		printf("%d ",arg2[i]);

	semctl(sem_id,0,IPC_RMID);
	semctl(9109504,0,IPC_RMID);

	return 0;
}
