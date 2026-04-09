/*WAP to change the action of the signal using sigaction */

#include<stdio.h>
#include<signal.h>

void ISR (int n){
	printf("IN ISR...\n");
}

int main(){
	struct sigaction v;
	v.sa_handler = ISR;
	v.sa_flags = 0;
	sigemptyset(&v.sa_mask);
	sigaction(2,&v,0);
	printf("using sigaction function SIGINT signal action updated..\n");
	while(1);
}
