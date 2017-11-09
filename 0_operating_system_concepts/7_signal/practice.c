#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>

int main(void){
  void sigint_handler(int sig);
  char s[200];
  int t;
  signal(SIGINT, sigint_handler);

  while(1);
}

void sigint_handler(int sig){
  printf("Heloo\n");
}
