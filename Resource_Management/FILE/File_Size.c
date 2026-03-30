#include<stdio.h>
#include<sys/resource.h>

int main(){
	char buf[50]="abcdefghijklm";
	struct rlimit v;
	FILE* fp= fopen("text.txt","w");
	if(fp==NULL){
		perror("fopen");
		return 0;
	}
	
	if(getrlimit(RLIMIT_FSIZE,&v)==-1){
		perror("setrlimit");
		return 0;
	}
	printf("Soft limit: %u\n",v.rlim_cur);
	printf("Hard limit: %u\n",v.rlim_max);

	v.rlim_cur=10;
	if(setrlimit(RLIMIT_FSIZE,&v)==-1){
		perror("setrlimit");
		return 0;
	}
	printf("after setting limit\n");
	
	if(getrlimit(RLIMIT_FSIZE,&v)==-1){
		perror("setrlimit");
		return 0;
	}
	printf("Soft limit: %u\n",v.rlim_cur);
	printf("Hard limit: %u\n",v.rlim_max);
	fprintf(fp,"%s",buf);
}
