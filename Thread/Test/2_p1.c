#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long mtype;
	char mtext[30];
};

void repeatchar(char *str){
        for(int i=0; str[i]; i++){
                for(int j=i+1; str[j]; j++){
                        if(str[i] == str[j]){
                                for(int k=j;str[k];k++)
                                        str[k]=str[k+1];
                        }
                }
        }
}

int main(){
	int id = msgget(5,IPC_CREAT|0664);
	if(id<0){
		perror("msgget");
		return 0;
	}
	struct msgbuf v;
	v.mtype=1;
	while(1){
		printf("WRITE: ");
		scanf("%s",v.mtext);
		msgsnd(id,&v,strlen(v.mtext)+1,0);
		msgrcv(id,&v,sizeof(v.mtext),1,0);
		repeatchar(v.mtext);
		printf("READ: %s\n",v.mtext);
	}
}
