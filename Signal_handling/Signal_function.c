#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void isr(int n){
	printf("IN ISR: signal num: %d \n",n);
}

int main(){
	int n;
	void (*ptr) (int);
	signal(2,SIG_IGN);
	signal(3,isr);

	printf("ENTER SIGNAL NUMBER: ");
	scanf("%d",&n);

	ptr = signal(n,SIG_DFL);
	signal(n,ptr);

	if(ptr==SIG_DFL)
		printf("DEFAULT\n");
	else if(ptr==SIG_IGN)
		printf("IGNORE\n");
	else
		printf("IN ISR\n");
}

