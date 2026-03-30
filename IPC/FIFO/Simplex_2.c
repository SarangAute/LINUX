#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd;
	char str[30];
	mkfifo("fifo",0664);
	perror("mkfifo");
	printf("EXECUTION STARTED\n");
	fd = open("fifo",O_RDONLY);
	if(fd<0){
		perror("open");
		return 0;
	}
	while(1){
		read(fd,str,sizeof(str));
		printf("READED STRING: %s \n",str);
	}
}


