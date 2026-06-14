#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
        printf("WORK STARTED...\n");
	int count=0;
	while(1){
		if(count<4){
			kill(getppid(), SIGUSR1);	//continuous sends signal
			printf("Heartbit Sent**\n");
		}
		count++;
		sleep(2);
	}
	return 0;
}

//cc worker.c -o worker  -for execl 
