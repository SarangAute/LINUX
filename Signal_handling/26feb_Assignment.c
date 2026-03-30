#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int i;
void isr(int n){
	printf("IN ISR FOR %d SEC\n",i);
	if(i==0)
		raise(9);
	else
		alarm(i);
	i--;
}

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("using ./a.out sec\n");
		return 0;
	}
	printf("MAIN PROCESS STARTED...\n");
	i=atoi(argv[1]);
	signal(SIGALRM,isr);
	alarm(i);
	while(1);
}
