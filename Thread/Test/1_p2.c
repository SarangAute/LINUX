/*fifo full duplex communication using threads */

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>

void* thread1(){
	char str1[30];
	mkfifo("fifo1",0664);
	int fd = open("fifo1",O_RDONLY);
	if(fd<0){
		perror("open");
		return 0;
	}
	while(1){
		read(fd,str1,sizeof(str1));
		printf("READ: %s\n",str1);
	}
}

void* thread2(){
	char str2[30];
	mkfifo("fifo2",0664);
	int fd = open("fifo2",O_WRONLY);
	if(fd<0){
		perror("open");
		return 0;
	}
	while(1){
		printf("ENTER MSG: ");
		scanf("%s",str2);
		write(fd,str2,strlen(str2)+1);
	}
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	while(1);
}
