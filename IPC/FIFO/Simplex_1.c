#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
	int fd;
	char str[30];
	mkfifo("fifo",0664);
	perror("mkfifo");
	printf("EXECUTION STARTED\n");
	fd = open("fifo",O_WRONLY);
	if(fd<0){
		perror("open");
		return 0;
	}
	while(1){
		printf("ENTER STRING: ");
	//	scanf("%[^\t]",str);
		//scanf(" %19[^\n]", str);
		scanf("%s",str);
		write(fd,str,strlen(str)+1);
	}
}
