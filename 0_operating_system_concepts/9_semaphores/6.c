//write a program for classical IPC producer and consumer problme using semaphore between processes.

#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t access_buffer;
sem_t access_avail_items;
sem_t access_avail_spots;

const int total_spots = 10;
int item=-1;

int main(){	
	//SEMAPHORE INITIALISATION
	sem_init(&access_buffer,0,1);
	sem_init(&access_avail_items,0,0);
	sem_init(&access_avail_spots,0,total_spots);

	pid_t pid;
//	pid = fork();
//	if(pid == 0){
		//PRODUCER

		//ENTRY SECTION
		sem_wait(&access_buffer);				
	
		//CRITICAL SECTION
		item=(item+1)%total_spots;

		//EXIT SECTION
		sem_post(&access_buffer);
//	}
//	else{
		//CONSUMER
		sem_wait(&access_buffer);

		//ENTRY SECTION
		if(item>=0)
			item--;
		else
			printf("\nproducer is lazy");

		//CRITICAL SECTION
		sem_post(&access_buffer);

		//EXIT SECTION

//	}

	sem_destroy(&access_buffer);
	sem_destroy(&access_avail_items);
	sem_destroy(&access_avail_spots);

return 0;
}
