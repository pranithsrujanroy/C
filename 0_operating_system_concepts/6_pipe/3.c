#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define max_size 100
#define BUF_SIZE 100

int main(){		
	int fd[2];
	char buff[max_size];

	int c = pipe(fd);
	if(c<0){
		exit(0);
	}

	int pid = fork();

	if(pid>0){
		//Write output of command#1 to pipe
		close(fd[0]);
		dup2(fd[1],1);		
		execlp("ls","ls","-l",(char *)0);		
		close(fd[1]);
	
	}
	
	if(pid == 0){
		char f_data[BUF_SIZE];

		//Read output from pipe
		close(fd[1]);		
		dup2(fd[0],0);
		execlp("wc","wc","-l",(char *)0);

		close(fd[0]);
	}
	return 0;
}
