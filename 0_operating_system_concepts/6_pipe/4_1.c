#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define size 5
#define max_size 100
#define FILENAME "temp1"

int main(){
	int fd;
	char buff[max_size];
	int i = 0;
//	char *myfile = "/tmp/myfile";
	int c = mknod(FILENAME,S_IFIFO|0666,0);		//can also use : mkfifo(FILENAME,0666);
	printf("%d",c);


	if(c<0){
		printf("Terminating...");
		exit(1);
	}
	int check = fork();

	if(check == 0){
		printf("\nchild_start_write_start");	
		fd = open(FILENAME,O_WRONLY);
		strcpy(buff,"I am proud to be your childx");
		write(fd,buff,strlen(buff));
		printf("\nchild_end_write_over");	
		close(fd);
	}
	else{
		printf("\nparent_start_read_start");
		fd = open(FILENAME,O_RDONLY);
		read(fd,buff,sizeof(buff));
		printf("%s",buff);
//		for(i = 0;buff[i]!='x';i++){
//			printf("%c",buff[i]);
//		}
		wait();
		printf("\nparent_end_read_over");
		close(fd);
	}

	printf("\n\n");
	return 0;
}


