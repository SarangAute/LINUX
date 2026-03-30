#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
#define stack_size (1024*100)

int main(){
	struct rlimit v;
	if(getrlimit(RLIMIT_STACK,&v)==-1){
		perror("getrlimit");
		return 0;
	}
	
	printf("soft limit of stack : %u\n",v.rlim_cur);
	printf("hard limit of stack : %u\n",v.rlim_max);
	v.rlim_cur=stack_size;

	if(setrlimit(RLIMIT_STACK,&v)==-1){
		perror("setrlimit");
		return 0;
	}

	printf("after update in kernal soft and hard limits are \n");
	
	if(getrlimit(RLIMIT_STACK,&v)==-1){
		perror("getrlimit");
		return 0;
	}
	
	printf("soft limit of stack : %u\n",v.rlim_cur);
	printf("hard limit of stack : %u\n",v.rlim_max);

	printf("execl function going to execute\n");
	sleep(5);
	execl("./stack","U_stackP2",NULL);
	printf("after execl function\n");
}
