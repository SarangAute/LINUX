#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>	//strlrn

int main(){
	char a[100];
	int fd = open("text.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0){
		perror("open");
		return 0;
	}
	printf("ENTER DATA INTO A FILE.. \n");
	scanf("%[^\t]",a);
	write(fd,a,strlen(a)+1);
	close(fd);
}
