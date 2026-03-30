#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(int argc, char *argv[]){
	if(argc!=3){
		printf("./a.out SigNo. PID\n");
		return 0;
	}
	int ret = kill(atoi(argv[2]),atoi (argv[1]));
	if(ret == -1){
		perror("kill\n");
		return 0;
	}
}

//signal no. 9 is kill
