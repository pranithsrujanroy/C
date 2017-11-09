#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

pid_t pid1;
int count = 0;
int loop = 0;

int main(){
	pid_t main_pid = getpid();
	printf("PID of main process = %d\n",main_pid);
	int n=4;
	int i=0;
	
	for(i=0;i<n;i++){
		pid1 = fork();
		if(pid1 == 0){
			printf("process[%d] = %d\n",i,getpid());
		}
		else
			count++;
	}

		//if(pid1!=0)
		//printf("Total #process = %d\n",count);

	return 0;
}

