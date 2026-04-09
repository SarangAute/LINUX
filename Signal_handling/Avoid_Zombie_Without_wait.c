/*WAP to avoid child process as zombie without using wait() and waitpid() */

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void isr(int n){
	printf("in isr\n");
}

int main(){
	if(fork()==0){
		printf("Child process pid : %d\n",getpid());
		sleep(10);
		printf("child process terminated\n");
		exit(0);
	}
	else{
		struct sigaction v;
		v.sa_handler=isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigaction(17,&v,0);
		printf("parent process under execution\n");
		while(1);
	}
}

