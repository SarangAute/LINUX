#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("USAGE: ./a.out file_name");
		return 0;
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd<0){
		perror("open");
		return 0;
	}
	else
		printf("FILE EXIST!!!\n");
	close(fd);
}
