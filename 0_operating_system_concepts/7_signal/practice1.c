#include<signal.h>
#include<stdio.h>

int main(){
   void sigint_handler(int);
   void sigquit_handler(int);
   while(true)
      signal(SIGINT,sigint_handler);
      signal(SIGQUIT,sigquit_handler);
   return 0;	
}

void sigint_handler(int sig){
   print("Hello");
}

void sigquit_handler(int sig){
   print("Bye");
}


