#include<unistd.h>
#include<stdio.h>

int main(){
  pid_t pid;
  int n;
  scanf("%d",&n);
  pid = fork();
  if(pid == 0){
    int factorial = 1;
    while(n>1){
      factorial*=n;
      n--;
    }
    printf("\nFactorial = %d",factorial);
  }
  else{
    int num1 = 1;
    int num2 = 1;
    int num3 = 1;
    while(n>1){
      num3 = num2 + num1;
      num2 = num3;
      num1 = num2;
      n--;
    }
   
    printf("\nFibonacci sum = %d\n\n",num3);
  }

  return 0;
}
