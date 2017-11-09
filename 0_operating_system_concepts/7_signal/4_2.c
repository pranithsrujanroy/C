#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define max_size 100
#define BUF_SIZE 100

void sigpipe_handler(int);
int main(){		
	int fd[2];
	char buff[max_size];
	int i;

	int c = pipe(fd);
	if(c<0){
		exit(0);
	}

	int pid = fork();

	if(pid>0){
		printf("\nBinding signal pipe to handler in parent process");
		signal(SIGPIPE,sigpipe_handler);
				

//		signal(SIGPIPE,sigpipe_handler);

		close(fd[0]);
		sleep(3);
		printf("\nAttempt to read from broken pipe");
		read(fd[0],buff,sizeof(buff));
		for(i = 0;buff[i]!='x';i++){
			printf("%c",buff[i]);
		}
		close(fd[0]);
	}
	
	if(pid == 0){
		sleep(1);
		printf("\nCalling parent process from parent with pipe signal");
		kill(getppid(),SIGPIPE);		


		sleep(2);
		//printf("\nBreaking pipe");
		//close(fd[1]);		
		
		printf("\nAttempt to write in broken pipe");
		strcpy(buff,"I am proud to be your childx");
		write(fd[1],buff,strlen(buff));
		close(fd[1]);
		printf("\nWritten in broken pipe");
	}
	return 0;
}

void sigpipe_handler(int sig){
   printf("\nPipe is broken. Caught signal pipe interrupt.\n");
}
