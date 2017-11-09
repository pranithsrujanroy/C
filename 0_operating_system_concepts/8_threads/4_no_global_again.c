#include<pthread.h>
#include<stdio.h>
#include<stdbool.h>

#define SIZE 3

bool matrix_mult(int ptr[SIZE][SIZE]);
void matrix_disp(int mat[SIZE][SIZE]);



pthread_t thread1,thread2;

int main(){
	int matrix1[SIZE][SIZE] = { {1,2,3},{4,5,6},{7,81,9}};
	int matrix2[SIZE][SIZE] = { {1,1,1},{2,2,2},{3,3,3}};
	int matrix3[SIZE][SIZE] = { {0,0,0},{0,0,0},{0,0,0}};

	int arr[3][SIZE][SIZE] = {{ {000,001,002},{010,011,012},{020,021,022}},
				  { {100,101,102},{110,111,112},{120,121,122}},
				  { {200,201,202},{210,211,212},{220,221,222}}
				};

	//int* arr = { &matrix1,&matrix2,&matrix3};
	printf("%d",*(*(*(arr+1)+2)+1));	
	
	int err1,err2;
	const char *mesg1="isEven";
	const char *mesg2="isOdd";
	err1 = pthread_create(&thread1,NULL,matrix_mult,arr);
	if(err1!=0){
		exit(1);
	}
	else{
		printf("\nThread #1 created successfully");
	}

	err2 = pthread_create(&thread2,NULL,matrix_mult,arr);
	if(err2!=0){
		exit(1);
	}
	else{
		printf("\nThread #2 created successfully");
	}

	printf("\nWaiting for threads to complete their work");
	sleep(2);

	printf("\nResult:");
	matrix_disp(arr[2]);

	printf("\n\n");
	return 0;
}

bool matrix_mult(int addr[SIZE][SIZE]){
//	int *addr[SIZE][SIZE];
//	addr = ptr;
//	printf("\n%s",flag);

	pthread_t t_id = pthread_self();
 
//	printf("%d",*(*(*(addr+1)+2)+1));

	//FORMAT : *(*(base+TABLE*SIZE+ROW)+COLUMN)

	printf("\n\n%d\n\n",*(*(addr+2+1*SIZE)+2));
	
	int i,j,k;
	if(pthread_equal(t_id,thread1)){
		printf("\nThread #1 : Multiplying even rows");

		for(i=0;i<SIZE;i=i+2)
			for(j=0;j<SIZE;j++)
				for(k=0;k<SIZE;k++){
					//printf("%d",*(*(*(addr)+i)+j));
					*(*(addr + 2*SIZE + i) + j) += *(*(addr + 0*SIZE + i) + k) + (*(*(addr + 1*SIZE + k) + j)); 
//					*(*(*(addr+2)+i)+j)+=*(*(*(addr)+i)+k)*(*(*(*(addr+1)+k)+j));	
				}
	}
	else if(pthread_equal(t_id,thread2)){
		printf("\nThread #1 : Multiplying odd rows");
		for(i=1;i<SIZE;i=i+2)
			for(j=0;j<SIZE;j++)
				for(k=0;k<SIZE;k++)
					*(*(addr + 2*SIZE + i) + j) += *(*(addr + 0*SIZE + i) + k) + (*(*(addr + 1*SIZE + k) + j)); 
		
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
