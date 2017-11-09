#include<pthread.h>
#include<stdio.h>
#include<stdbool.h>

#define SIZE 3

bool matrix_add(void *ptr);
void matrix_disp(int mat[][SIZE]);

int matrix1[SIZE][SIZE] = { {1,2,3},{4,5,6},{7,8,9}};
int matrix2[SIZE][SIZE] = { {1,1,1},{2,2,2},{3,3,3}};
int matrix3[SIZE][SIZE] = { {0,0,0},{0,0,0},{0,0,0}};

pthread_t thread1,thread2;

int main(){
	int err1,err2;
	const char *mesg1="isEven";
	const char *mesg2="isOdd";
	err1 = pthread_create(&thread1,NULL,matrix_add,mesg1);
	if(err1!=0){
		exit(1);
	}
	else{
		printf("\nThread #1 created successfully");
	}

	err2 = pthread_create(&thread2,NULL,matrix_add,mesg2);
	if(err2!=0){
		exit(1);
	}
	else{
		printf("\nThread #2 created successfully");
	}

	printf("\nWaiting for threads to complete their work");
	sleep(2);

	printf("\nResult:");
	matrix_disp(matrix3);

	printf("\n\n");
	return 0;
}

bool matrix_add(void *ptr){
	char *my_work;
	my_work = (char *) ptr;
//	printf("\n%s",flag);

	int i,j;
	if(strcmp(my_work,"isEven")){
		printf("\nThread #1 : Adding even rows");

		for(i=0;i<SIZE;i=i+2)
			for(j=0;j<SIZE;j++)
				matrix3[i][j]=matrix1[i][j]+matrix2[i][j];	

	}
	else if(strcmp(my_work,"isOdd")){
		printf("\nThread #1 : Adding odd rows");
		for(i=1;i<SIZE;i=i+2)
			for(j=0;j<SIZE;j++)
				matrix3[i][j]=matrix1[i][j]+matrix2[i][j];	

		
	}

	return true;
}

void matrix_disp(int m[SIZE][SIZE]){
	int i=0;
	int j=0;	
	for(i=0;i<SIZE;i++){
		printf("\n\t");
		for(j=0;j<SIZE;j++){
			printf(" %d ",m[i][j]);  		
		}	
	}
}
