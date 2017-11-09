#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>	

#define size 5
#define max_size 100
#define FILENAME "temp2"

int main(){
	int fd;
	char buff1[max_size],buff2[max_size];
	int i = 0;
	int c1 = mkfifo(FILENAME,0666);
	if(c1<0){
		printf("\nCan't create FIFO special file");	
		exit(1);
	}


	int check = fork();
	if(check == 0){
		fd = open(FILENAME, O_WRONLY);
		strcpy(buff1,"\nI am proud to be your child - says the child\0");
		write(fd,buff1,strlen(buff1));
		close(fd);
		
//		wait(getppid());

		fd = open(FILENAME, O_RDONLY);
		read(fd,buff2,sizeof(buff2));
		printf("%s",buff2);
		printf("\n\n");
		close(fd);
		
	}
	else{
		
//		sleep(1);

		fd = open(FILENAME,O_RDONLY);
		read(fd,buff1,sizeof(buff1));
		printf("%s",buff1);
		close(fd);

		fd = open(FILENAME, O_WRONLY);
		strcpy(buff2,"\nI am proud to be your parent - says the parent\0");
		write(fd,buff2,strlen(buff2));
		close(fd);

	}

	printf("\n\n");

	return 0;
}


