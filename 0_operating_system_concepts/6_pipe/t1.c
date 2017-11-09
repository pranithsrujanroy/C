#include<stdlib.h>
#include<stdio.h>

int main(){

	execlp("wc","wc","-l","1.c",NULL);
	return 0;
}
