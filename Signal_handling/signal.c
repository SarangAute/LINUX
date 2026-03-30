//WAP to change the action of the signal using signal function.
#include<stdio.h>
#include<signal.h>

void isr(int n){
	printf("INSIDE ISR\n");
	printf("n=%d\n",n);
	signal(n,SIG_DFL);
	printf("ISR COMPLETED\n");
}

int main(){
	printf("PROCESS UNDER EXECUTION\n");
	signal(2,isr);		//ctrl+c = signal-2(SIGINT)
	printf("AFTER SIGNAL FUNCTION\n");
	while(1);
}
