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
	int i=10;
	for(;i<100000;i++){
	create_sems(i);
}
	return 0;
}

void create_sems(int n){
	key_t key;
	int sem_num[n];
	int sem_id;
	int i=n;
	int max=0;
//	for(i = 0;i<n;i=i*2){
		sem_id = semget(key,i,0666|IPC_CREAT);
		max = i;
		if(sem_id==-1){
			printf("\n Can't create more sub-semaphores");
			char ch = getchar();
			max = i;
			printf("\n %d sub-semaphores created ",i);
	//		break;
			}
	//}

			//printf("\nPress any key to continue(check semaphores in another terminal using 'ipc -s') ...\t");
			//char ch = getchar();
			for(i = 0;i<n;i++){
				semctl(sem_id,i,IPC_RMID);
			}
				printf("\n%d sub-semaphores removed\n",n);	

//	}
	
	printf("\nMax sub-semaphores : %d\n",max);
}
