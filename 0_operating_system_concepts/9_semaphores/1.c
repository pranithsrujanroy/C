#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdio.h>

//int semget(key_t key_identifier_of_sem_set, int sem_num_of_semaphores_in_one_row, int sem_flag);

void create_sems(int num);

int main(){
//	int sem_id;
//	key_t key;
//	int sem_num = 1;
//	int val=3;
//	sem_id = semget(key,sem_num,0666|IPC_CREAT);
//	semctl(sem_id,1,SETVAL,val);
//	int rtval = semctl(sem_id,0,GETVAL);
//	printf("%d",rtval);

//	printf("\n Press any key to continue ...\t");
//	char ch = getchar();
	
//	semctl(sem_id,1,IPC_RMID);
//	semctl(13795328,1,IPC_RMID);
//	semctl(9175040,1,IPC_RMID);
	
	create_sems(15000);

	return 0;
}

void create_sems(int n){
	key_t key[n];
	int sem_num = 1;
	int a[n];
	int i;
	int max=0;
	for(i = 0;i<n;i++){
		a[i] = semget(key[i],sem_num,0666|IPC_CREAT);
		if(a[i]==-1){
			printf("\n Can't create more semaphores");
			char ch = getchar();
			max = i;
			printf("\n %d semaphores created ",i);
			break;
			}
	}

	if(i==n)
		printf("\n%d semaphores created\n",n);
	printf("\nPress any key to continue ...\t");
	char ch = getchar();
	for(i = 0;i<n;i++){
		semctl(a[i],sem_num,IPC_RMID);
	}
	if(max==0)
		printf("\n%d semaphores removed\n",n);	
	
	printf("\nMax semaphores : %d\n",max);
}
