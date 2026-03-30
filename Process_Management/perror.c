#include<stdio.h>

int main(){
	FILE* fp;
	fp=fopen("temp","r");
	if(fp==NULL){
		perror("fopen");	//prints system error message
		return 0 ;
	}
	printf("file open successfully\n");
}
