#include<stdio.h>
#include<unistd.h>
int main(){
	printf("PROCESS UNDER EXECUTION...\n");
	printf("Proces ID: %d\n",getpid());
	while(1);
}
