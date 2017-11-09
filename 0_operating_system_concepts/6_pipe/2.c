#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 5
#define max_size 100

int main(){
	int fd1[2],fd2[2];
	char buff1[max_size],buff2[max_size];
	int i = 0;
	int c1 = pipe(fd1);
	int c2 = pipe(fd2);
	if(c2<0){
		exit(1);
	}
	if(c1<0){
		exit(1);
	}
	int check = fork();

	if(check == 0){
		
		strcpy(buff1,"\nI am proud to be your child - says the child\0");
//		strcat(buff1,(char *) getpid());
		write(fd1[1],buff1,strlen(buff1));
//		write(fd1[1],getpid(),sizeof(getpid()));
		close(fd1[1]);
		
		wait(getppid());

		read(fd2[0],buff2,sizeof(buff2));
		for(i = 0;buff2[i]!='\0';i++){
			printf("%c",buff2[i]);
		}
		printf("\n\n");
		close(fd2[0]);
		
	}
	else{
		strcpy(buff2,"\nI am proud to be your parent - says the parent\0");
		write(fd2[1],buff2,strlen(buff2));
		close(fd2[1]);

//		wait(NULL);
		sleep(1);

		read(fd1[0],buff1,sizeof(buff1));
		for(i = 0;buff1[i]!='\0';i++){
			printf("%c",buff1[i]);
		}
//		char ch;
//		read(fd1[0],ch,sizeof(ch));
//		printf("%c\n\n",ch);
		close(fd1[0]);
	}

	printf("\n\n");
	return 0;
}


