#include<signal.h>
#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<fcntl.h>

#define true 1
#define false 0

void info();
void sigint_handler(int sig);

int main(){
   int pid = fork();
   if(pid<0){
      printf("Failed to create child\n");
   }
   else if(pid == 0){
      sleep(1);
      int pp = getppid();
      kill(pp,SIGINT);	
   }
   else{
        signal(SIGINT,sigint_handler);
	printf("Child terminates!\n");
	wait(1);        
	//while(1);
   }

   return 0;

}



void sigint_handler(int sig){
   printf("\nCaught the Ctrl+C interrupt\n");
}

void info(){
   int p = getpid();
   int pp = getppid();
   printf("Process id\t\t:\t%d  \nParent Process id\t:\t%d\n",p,pp);
}


