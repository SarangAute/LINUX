#include<stdio.h>
#include<sys/resource.h>
#include<signal.h>

int reach_isr=0;

void ISR(int n){
	printf("IN ISR: %d\n",reach_isr++);
}

int main(){
	struct rlimit v;
	signal(SIGXCPU,ISR);
	if(getrlimit(RLIMIT_CPU, &v)==-1){
		perror("getrlimit");
		return 0;
	}
	printf("SOFT LIMIT : %u\n",v.rlim_cur);
	printf("HARD LIMIT : %u\n",v.rlim_max);

	v.rlim_cur=10;
	if(setrlimit(RLIMIT_CPU, &v)==-1){
		perror("setrlimit");
		return 0;
	}
	printf("AFTER UPDATING LIMIT\n");
	
	if(getrlimit(RLIMIT_CPU, &v)==-1){
		perror("getrlimit");
		return 0;
	}
	printf("SOFT LIMIT : %u\n",v.rlim_cur);
	printf("HARD LIMIT : %u\n",v.rlim_max);
	while(1);
}
