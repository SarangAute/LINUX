#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	if(fork()==0){
		printf("child process under execution with PID:%d\n",getpid());
		sleep(10);
		printf("child process terminated\n");
		exit(3);
	}
	else{
		int ret,stat;
		printf("before wait system call\n");
		//ret=wait(0);
		ret=wait(&stat);	//wait system call blocks parent process
					//until process terminate
		printf("after wait system call\n");
		printf("ret val : %d\n",ret);
		printf("stat : %d\n",stat);
		printf("parent process PID:%d\n",getpid());
		while(1);
	}
}
