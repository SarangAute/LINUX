//pause: sleep and wait for signal
#include<stdio.h>
#include<signal.h>
int main(){
	printf("PROCESS UNDER EXECUTION\n");
	printf("PID:%d\n",getpid());
	printf("BEFORE PAUSE\n");
	int ret = pause();
	printf("AFTER PAUSE\n");
	printf("Ret = %d\n",ret);
	while(1);
}
