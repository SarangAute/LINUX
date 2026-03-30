#include<stdio.h>
#include<unistd.h>
int main(){
	printf("1) before fun\n");
	fork();
	printf("2) After fork\n");
	fork();
	printf("3) After fork\n");
	fork();
	printf("4) After fork\n");
	while(1);
}
