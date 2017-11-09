#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 5
#define max_size 100

int main(){
	int fd[2];
	char buff[max_size];
	int i = 0;
	int c = pipe(fd);

	if(c<0){
		exit(1);
	}
	int check = fork();

	if(check == 0){
		strcpy(buff,"I am proud to be your childx");
		write(fd[1],buff,strlen(buff));
		close(fd[1]);
	}
	else{
		read(fd[0],buff,sizeof(buff));
		for(i = 0;buff[i]!='x';i++){
			printf("%c",buff[i]);
		}
		close(fd[0]);
	}

	printf("\n\n");
	return 0;
}


