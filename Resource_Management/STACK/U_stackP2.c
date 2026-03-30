#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

void rec_fun(int depth){
	char bf[1024];
	printf("Depth : %d\n",depth);
	sleep(1);
	rec_fun(depth+1);
}

int main(){
	struct rlimit v;
	printf("new process started execution\n");
	if(getrlimit(RLIMIT_STACK,&v)==-1){
		perror("getrlimit");
		return 0;
	}
	printf("soft : %u\n",v.rlim_cur);
	printf("hard : %u\n",v.rlim_max);
	rec_fun(1);
}
