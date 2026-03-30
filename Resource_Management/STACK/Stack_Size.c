#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;
	if(getrlimit(RLIMIT_STACK, &v)==-1){
		perror("getlimit");
		return 0;
	}	
	printf("Soft limit of stack : %u\n",v.rlim_cur);
	printf("Hard limit of stack : %u\n",v.rlim_max);
}
