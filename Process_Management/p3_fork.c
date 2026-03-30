#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Hi...\n");
	if(fork()==0){
		printf("Hello\n");
		printf("vector\n");
		printf("child pid:%d\n",getpid());
		while(1);
	}
	else{
		printf("Embedded\n");
		printf("By...\n");
		printf("Parent pid:%d\n",getpid());
		while(1);
	}
}
