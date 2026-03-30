//WAP to create 3 child process from same process
#include<stdio.h>
#include<unistd.h>
int main(){
	if(fork()==0){
		printf("Child1 pid:%d  ppid:%d\n",getpid(),getppid());
		while(1);
	}
	else {
		if(fork()==0){
		printf("Child2 pid:%d  ppid:%d\n",getpid(),getppid());
		while(1);
		}
		else {
			if(fork()==0){
			printf("Child3 pid:%d  ppid:%d\n",getpid(),getppid());
			while(1);
			}
			else{
				while(1);	
			}
		}	
	}
}
