#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd[2];
	if(pipe(fd)<0){
		perror("pipe");
		return 0;
	}
	if(fork()==0){
		char s1[20];
		while(1){
			read(fd[0],s1,sizeof(s1));
			for(int i=0;s1[i];i++){
				if((s1[i]>='a')&&(s1[i]<='z')||(s1[i]>='A')&&(s1[i]<='Z'))
					s1[i]^=32;
			}
			write(fd[1],s1,strlen(s1)+1);
			sleep(1);
		}
	}
	else{
		char s2[20];
		while(1){
			printf("ENTER STRING : ");
			scanf("%[^\n]",s2);
			write(fd[1],s2,strlen(s2)+1);
			sleep(1);
			read(fd[0],s2,sizeof(s2));
			printf("READED STRING: %s\n",s2);
		}
	}
}
