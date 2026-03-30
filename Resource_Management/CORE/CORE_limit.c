#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;
	if(getrlimit(RLIMIT_CORE,&v)==-1){
		perror("getrlimit");
		return 0;
	}
	printf("SOFT LIMIT : %u\n",v.rlim_cur);
	printf("HARD LIMIT : %u\n",v.rlim_max);

	v.rlim_cur=1000;
	if(setrlimit(RLIMIT_CORE,&v)==-1){
		perror("setrlimit");
		return 0;
	}

	printf("AFTER UPDATING LIMIT...\n");
	if(getrlimit(RLIMIT_CORE,&v)==-1){
		perror("getrlimit");
		return 0;
	}
	printf("SOFT LIMIT : %u\n",v.rlim_cur);
	printf("HARD LIMIT : %u\n",v.rlim_max);

}
